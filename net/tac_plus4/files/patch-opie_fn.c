--- opie_fn.c.orig	Sun Dec  8 15:26:20 2002
+++ opie_fn.c	Sun Dec  8 15:27:01 2002
@@ -0,0 +1,239 @@
+/* 
+   Copyright (c) 1995-2000 by Cisco systems, Inc.
+
+   Permission to use, copy, modify, and distribute modified and
+   unmodified copies of this software for any purpose and without fee is
+   hereby granted, provided that (a) this copyright and permission notice
+   appear on all copies of the software and supporting documentation, (b)
+   the name of Cisco Systems, Inc. not be used in advertising or
+   publicity pertaining to distribution of the program without specific
+   prior permission, and (c) notice be given in supporting documentation
+   that use, modification, copying and distribution is by permission of
+   Cisco Systems, Inc.
+
+   Cisco Systems, Inc. makes no representations about the suitability
+   of this software for any purpose.  THIS SOFTWARE IS PROVIDED ``AS
+   IS'' AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
+   WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
+   FITNESS FOR A PARTICULAR PURPOSE.
+*/
+
+#ifdef OPIE
+#include "tac_plus.h"
+#include "expire.h"
+
+/* internal state variables */
+#define STATE_AUTHEN_START   0	/* no requests issued */
+#define STATE_AUTHEN_GETUSER 1	/* username has been requested */
+#define STATE_AUTHEN_GETPASS 2	/* password has been requested */
+
+#include <opie.h>
+
+struct private_data {
+    struct opie opiedata;
+    char password[MAX_PASSWD_LEN + 1];
+    int state;
+};
+
+/* Use s/key to verify a supplied password using state set up earlier
+when the username was supplied */
+
+static int
+opie_verify(passwd, data)
+char *passwd;
+struct authen_data *data;
+{
+    struct private_data *p = data->method_data;
+    struct opie *opiep = &p->opiedata;
+
+    data->status = TAC_PLUS_AUTHEN_STATUS_FAIL;
+
+    if (opieverify(opiep, passwd) == 0) {
+	/* S/Key authentication succeeded */
+	data->status = TAC_PLUS_AUTHEN_STATUS_PASS;
+	if (opiep->opie_n < 5) {
+	    data->server_msg = tac_strdup("Password will expire soon");
+	    return (1);
+	}
+    }
+    return (0);
+}
+
+/*
+ * Skey tacacs login authentication function. Wants a username
+ * and a password, and tries to verify them via opie.
+ *
+ * Choose_authen will ensure that we already have a username before this
+ * gets called.
+ *
+ * We will query for a password and keep it in the method_data.
+ *
+ * Any strings returned via pointers in authen_data must come from the
+ * heap. They will get freed by the caller.
+ *
+ * Return 0 if data->status is valid, otherwise 1
+ */
+
+int
+opie_fn(data)
+struct authen_data *data;
+{
+    char *name, *passwd;
+    struct private_data *p;
+    char *prompt;
+    int pwlen;
+
+    p = (struct private_data *) data->method_data;
+
+    /* An abort has been received. Clean up and return */
+    if (data->flags & TAC_PLUS_CONTINUE_FLAG_ABORT) {
+	if (data->method_data)
+	    free(data->method_data);
+	data->method_data = NULL;
+	return (1);
+    }
+    /* Initialise method_data if first time through */
+    if (!p) {
+	p = (struct private_data *) tac_malloc(sizeof(struct private_data));
+	bzero(p, sizeof(struct private_data));
+	data->method_data = p;
+	p->state = STATE_AUTHEN_START;
+    }
+
+    /* Unless we're enabling, we need a username */
+    if (data->service != TAC_PLUS_AUTHEN_SVC_ENABLE &&
+	!(char) data->NAS_id->username[0]) {
+	switch (p->state) {
+
+	case STATE_AUTHEN_GETUSER:
+	    /* we have previously asked for a username but none came back.
+	     * This is a gross error */
+	    data->status = TAC_PLUS_AUTHEN_STATUS_ERROR;
+	    report(LOG_ERR, "%s: No username supplied after GETUSER",
+		   session.peer);
+	    return (0);
+
+	case STATE_AUTHEN_START:
+	    /* No username. Try requesting one */
+	    data->status = TAC_PLUS_AUTHEN_STATUS_GETUSER;
+	    if (data->service == TAC_PLUS_AUTHEN_SVC_LOGIN) {
+		prompt = "\nUser Access Verification\n\nUsername: ";
+	    } else {
+		prompt = "Username: ";
+	    }
+	    data->server_msg = tac_strdup(prompt);
+	    p->state = STATE_AUTHEN_GETUSER;
+	    return (0);
+
+	default:
+	    /* something awful has happened. Give up and die */
+	    report(LOG_ERR, "%s: opie_fn bad state %d", 
+		   session.peer, p->state);
+	    return (1);
+	}
+    }
+
+    /* we now have a username if we needed one */
+    name = data->NAS_id->username;
+
+    /* Do we have a password? */
+    passwd = p->password;
+
+    if (!passwd[0]) {
+	char opieprompt[80];
+
+	/* no password yet. Either we need to ask for one and expect to get
+	 * called again, or we asked but nothing came back, which is fatal */
+
+	switch (p->state) {
+	case STATE_AUTHEN_GETPASS:
+	    /* We already asked for a password. This should be the reply */
+	    if (data->client_msg) {
+		pwlen = MIN(strlen(data->client_msg), MAX_PASSWD_LEN);
+	    } else {
+		pwlen = 0;
+	    }
+	    strncpy(passwd, data->client_msg, pwlen);
+	    passwd[pwlen] = '\0';
+	    break;
+
+	default:
+	    /* Request a password */
+	    passwd = cfg_get_login_secret(name, TAC_PLUS_RECURSE);
+	    if (!passwd && !STREQ(passwd, "opie")) {
+		report(LOG_ERR, "Cannot find opie password declaration for %s",
+		       name);
+		data->status = TAC_PLUS_AUTHEN_STATUS_ERROR;
+		return(1);
+	    }
+
+	    if (opiechallenge(&p->opiedata, name, opieprompt) == 0) {
+		char buf[256];
+		sprintf(buf, "%s\nPassword: ", opieprompt);
+		data->server_msg = tac_strdup(buf);
+
+		/* We try to make it in accordance of standard FreeBSD
+		 * behaviour in order to avoid surprises for user */
+		data->flags = TAC_PLUS_AUTHEN_FLAG_NOECHO;
+
+		data->status = TAC_PLUS_AUTHEN_STATUS_GETPASS;
+		p->state = STATE_AUTHEN_GETPASS;
+		return (0);
+	    } 
+
+	    data->status = TAC_PLUS_AUTHEN_STATUS_ERROR;
+	    report(LOG_ERR, "Cannot generate opie prompt for %s", name);
+	    return(1);
+	}
+    }
+
+    /* We have a username and password. Try validating */
+
+    /* Assume the worst */
+    data->status = TAC_PLUS_AUTHEN_STATUS_FAIL;
+
+    switch (data->service) {
+    case TAC_PLUS_AUTHEN_SVC_LOGIN:
+	opie_verify(passwd, data);
+	if (debug)
+	    report(LOG_INFO, "login query for '%s' %s from %s %s",
+		   name && name[0] ? name : "unknown",
+		   data->NAS_id->NAS_port && data->NAS_id->NAS_port[0] ?
+		       data->NAS_id->NAS_port : "unknown",
+		   session.peer,
+		   (data->status == TAC_PLUS_AUTHEN_STATUS_PASS) ?
+		   "accepted" : "rejected");
+	break;
+
+    default:
+	data->status = TAC_PLUS_AUTHEN_STATUS_ERROR;
+	report(LOG_ERR, "%s: Bogus service value %d from packet", 
+	       session.peer, data->service);
+	break;
+    }
+
+    if (data->method_data)
+	free(data->method_data);
+    data->method_data = NULL;
+
+    switch (data->status) {
+    case TAC_PLUS_AUTHEN_STATUS_ERROR:
+    case TAC_PLUS_AUTHEN_STATUS_FAIL:
+    case TAC_PLUS_AUTHEN_STATUS_PASS:
+	return (0);
+    default:
+	report(LOG_ERR, "%s: opie_fn couldn't set recognizable status %d",
+	       session.peer, data->status);
+	data->status = TAC_PLUS_AUTHEN_STATUS_ERROR;
+	return (1);
+    }
+}
+#else /* OPIE */
+
+/* The following code is not needed or used. It exists solely to
+   prevent compilers from "helpfully" complaining that this source
+   file is empty, which upsets novices building the software */
+
+static int dummy = 0;
+
+#endif /* OPIE */
