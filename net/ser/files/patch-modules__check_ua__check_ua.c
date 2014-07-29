
$FreeBSD$

--- /dev/null	Sun Jan  9 11:17:56 2005
+++ modules/check_ua/check_ua.c	Sun Jan  9 11:17:26 2005
@@ -0,0 +1,368 @@
+/*
+ * $Id: patch-modules::check_ua::check_ua.c,v 1.2 2005/04/05 13:10:07 netch Exp $
+ *
+ * CHECK_UA module
+ *
+ *
+ * Copyright (C) 2004-2005 Porta Software Ltd.
+ * Copyright (C) Valentin Nechayev <netch@portaone.com>
+ *
+ * This file is part of ser, a free SIP server.
+ *
+ * ser is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version
+ *
+ * For a license to use the ser software under conditions
+ * other than those described here, or to purchase support for this
+ * software, please contact iptel.org by e-mail at the following addresses:
+ *    info@iptel.org
+ *
+ * ser is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+ */
+/* History:
+ * --------
+ * 2004-12-15 initial version (netch)
+ *
+ * 2005-01-09 style(9) and other minor nits (sobomax, netch)
+ */
+
+
+#include <sys/types.h>
+#include <regex.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+
+#include "../../db/db.h"
+#include "../../db/db_val.h"
+#include "../../dprint.h"
+#include "../../error.h"
+#include "../../flags.h"
+#include "../../mem/mem.h"
+#include "../../sr_module.h"
+
+#include "tailq.h"
+
+MODULE_VERSION
+
+static int check_ua_init(void);
+static int check_ua_exit(void);
+static int check_ua_f(struct sip_msg *, char *, char *);
+static int child_init(int);
+
+/* parameters */
+
+/* global variables */
+
+int  check_ua_f(struct sip_msg *, char *, char *);
+
+static cmd_export_t cmds[]={
+	{"check_ua", check_ua_f, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE | FAILURE_ROUTE},
+	{0, 0, 0, 0, 0}
+};
+
+static char *db_url = NULL;
+static char *db_table = NULL;
+static db_con_t *db_handle;
+static int reread_interval = 300;
+
+static param_export_t params[]={
+	{"db_url",	STR_PARAM,	&db_url},
+	{"db_table",	STR_PARAM,	&db_table},
+	{"reread_interval",	INT_PARAM,	&reread_interval},
+	{0, 0, 0}
+};
+
+struct module_exports exports= {
+	"check_ua",
+	cmds,
+	params,
+
+	check_ua_init,   /* module initialization function */
+	(response_function) 0,
+	(destroy_function) check_ua_exit,   /* module exit function */
+	0,
+	child_init  /* per-child init function */
+};
+
+typedef struct reglist_entry {
+	TAILQ_ENTRY(reglist_entry)	re_link;
+	char				*re_regexp;
+	regex_t				re_compiled;
+	int				re_has_compiled;
+	int				re_flag_num;
+} reglist_entry;
+
+static TAILQ_HEAD(reglist_head_t, reglist_entry) reglist;
+typedef struct reglist_head_t reglist_head_t;
+
+static time_t last_got;
+
+static void reglist_entry_free(reglist_entry *);
+static int load_reglist(reglist_head_t *);
+static void check_ua_periodic(void);
+static str *getUserAgent(struct sip_msg *msg);
+
+static db_func_t db_functions;
+
+static int
+check_ua_init(void)
+{
+
+	LOG(L_INFO,"CHECK_UA - initializing\n");
+	if (bind_dbmod(db_url, &db_functions) != 0) {
+		LOG(L_ERR, "CHECK_UA: init: bind_dbmod() failed\n");
+		return -1;
+	}
+
+	return 0;
+}
+
+static int
+child_init(int child)
+{
+
+	TAILQ_INIT(&reglist);
+	db_handle = db_functions.init(db_url);
+	if (!db_handle) {
+		LOG(L_ERR, "CHECK_UA: cannot connect to database\n");
+		return -1;
+	}
+	if (load_reglist(&reglist) < 0)
+		return -1;
+	time(&last_got);
+	srand(time(NULL) + getpid());
+	return 0;
+}
+
+static int
+check_ua_exit(void)
+{
+
+	reglist_entry *re;
+	LOG(L_INFO, "CHECK_UA - destroing module\n");
+
+	/* Free reglist */
+	while ((re = TAILQ_FIRST(&reglist)) != NULL) {
+		TAILQ_REMOVE(&reglist, re, re_link);
+		reglist_entry_free(re);
+	}
+
+	return 0;
+}
+
+static int
+load_reglist_sub(reglist_head_t *head)
+{
+
+	db_key_t cols[2];
+	db_res_t *db_res;
+	reglist_entry *re;
+	int i;
+	int ret;
+
+	ret = -1;
+	if (db_functions.use_table(db_handle, db_table) < 0) {
+		LOG(L_ERR, "check_ua: load_reglist(): can't select table\n");
+		return -1;
+	}
+	cols[0] = "rexp";
+	cols[1] = "flag";
+	if (db_functions.query(db_handle, NULL, NULL, NULL, cols, 0, 2, NULL, &db_res) < 0) {
+		LOG(L_ERR, "check_ua: load_reglist(): query failed\n");
+		return -1;
+	}
+	/* Iterate result */
+	for (i = 0; i < RES_ROW_N(db_res); ++i) {
+		db_row_t *row = &RES_ROWS(db_res)[i];
+		db_val_t *val_regexp;
+		db_val_t *val_flag;
+		char *r;
+		int flags;
+		str t;
+
+		if (row->n != 2) {
+			LOG(L_ERR, "check_ua: load_reglist(): no required columns\n");
+			goto cleanup;
+		}
+		val_regexp = &ROW_VALUES(row)[0];
+		val_flag = &ROW_VALUES(row)[1];
+		re = pkg_malloc(sizeof(*re));
+		if (re == NULL) {
+			LOG(L_ERR, "ERROR: check_ua: load_reglist(): no memory\n");
+			goto cleanup;
+		}
+		memset(re, '\0', sizeof(*re));
+		/* First is weight, either absolute or accumulated */
+		re->re_flag_num = VAL_INT(val_flag);
+		if (VAL_TYPE(val_regexp) == DB_STRING) {
+			t.s = (char *)VAL_STRING(val_regexp);
+			t.len = strlen(t.s);
+		} else if (VAL_TYPE(val_regexp) == DB_STR) {
+			t = VAL_STR(val_regexp);
+		} else {
+			LOG(L_ERR, "ERROR: check_ua: load_reglist(): invalid value type\n");
+			goto cleanup;
+		}
+		re->re_regexp = pkg_malloc(t.len + 1);
+		if (re->re_regexp == NULL)  {
+			LOG(L_ERR, "ERROR: check_ua: load_reglist(): no memory\n");
+			goto cleanup;
+		}
+		memcpy(re->re_regexp, t.s, t.len);
+		re->re_regexp[t.len] = '\0';
+		flags = REG_EXTENDED;
+		r = re->re_regexp;
+		if (strncmp(r, "\\c", 2) == 0) {
+			r += 2;
+			flags |= REG_ICASE;
+		}
+		if (regcomp(&re->re_compiled, r, flags) != 0) {
+			LOG(L_ERR, "ERROR: check_ua: load_reglist(): regcomp() failed\n");
+			reglist_entry_free(re);
+			goto cleanup;
+		}
+		re->re_has_compiled = 1;
+		TAILQ_INSERT_TAIL(head, re, re_link);
+	}
+	ret = 0;
+cleanup:
+	db_functions.free_result(db_handle, db_res);
+	return ret;
+}
+
+static int
+load_reglist(reglist_head_t *head)
+{
+	reglist_entry *re;
+	int rc;
+
+	rc = load_reglist_sub(head);
+	if (rc < 0) {
+		/* Free list. This is too hard to add in subfunction. */
+		while ((re = TAILQ_FIRST(head)) != NULL) {
+			TAILQ_REMOVE(head, re, re_link);
+			reglist_entry_free(re);
+		}
+	}
+	return rc;
+}
+
+static int
+check_ua_f(struct sip_msg *msg, char *dummy1, char *dummy2)
+{
+	str *useragent_str;
+	char *ua;
+	reglist_entry *re;
+	time_t now;
+	int rval;
+
+	time(&now);
+	if (now < last_got || now >= last_got + reread_interval)
+		check_ua_periodic();
+
+	/* Note that getUserAgent() always returns valid pointer */
+	useragent_str = getUserAgent(msg);
+	/*
+	 * Make nul-terminated string copy of user-agent. We can't use
+	 * that is in parsed header.
+	 */
+	ua = pkg_malloc(useragent_str->len + 1);
+	if (ua == NULL) {
+		LOG(L_ERR, "ERROR: check_ua: no memory\n");
+		return -1;
+	}
+	memcpy(ua, useragent_str->s, useragent_str->len);
+	ua[useragent_str->len] = '\0';
+
+	rval = -1;
+	/* Iterate regexp list and set flags on matching */
+	TAILQ_FOREACH(re, &reglist, re_link) {
+		int rc;
+
+		rc = regexec(&re->re_compiled, ua, 0, NULL, 0);
+		if (rc == 0) { /* matched */
+			setflag(msg, re->re_flag_num);
+			rval = 1;
+		} else if (rc != REG_NOMATCH) {
+			/* What's this? */
+			LOG(L_ERR, "ERROR: check_ua: unexpected regexec error: %d\n", rc);
+			rval = -1; /* 0 maybe??? */
+			break;
+		}
+	}
+	pkg_free(ua);
+	return rval;
+}
+
+static void
+check_ua_periodic(void)
+{
+	reglist_head_t newhead;
+	reglist_entry *re;
+
+	TAILQ_INIT(&newhead);
+	/*
+	 * Reread base and recompile expression list.
+	 * As we have no way to check whether regexp list was changed,
+	 * do it unconditionally.
+	 */
+	if (load_reglist(&newhead) < 0) {
+		LOG(L_ERR, "check_ua: check_ua_periodic(): error reading new regexp file, keeping list from old one\n");
+		return;
+	}
+	/* Delete old list and move all entries of new list to old one */
+	while ((re = TAILQ_FIRST(&reglist)) != NULL) {
+		TAILQ_REMOVE(&reglist, re, re_link);
+		reglist_entry_free(re);
+	}
+	while ((re = TAILQ_FIRST(&newhead)) != NULL) {
+		TAILQ_REMOVE(&newhead, re, re_link);
+		TAILQ_INSERT_TAIL(&reglist, re, re_link);
+	}
+	time(&last_got);
+	last_got -= (rand() % 3);
+}
+
+static void
+reglist_entry_free(reglist_entry *re)
+{
+	if (re->re_has_compiled)
+		regfree(&re->re_compiled);
+	if (re->re_regexp)
+		pkg_free(re->re_regexp);
+	pkg_free(re);
+}
+
+#define UA_DUMMY_STR "Unknown"
+#define UA_DUMMY_LEN 7
+
+/* Extract User-Agent */
+static str *
+getUserAgent(struct sip_msg *msg)
+{
+	static str notfound = {UA_DUMMY_STR, UA_DUMMY_LEN};
+
+	if ((parse_headers(msg, HDR_USERAGENT, 0)!=-1) && msg->user_agent &&
+		msg->user_agent->body.len>0) {
+		return &(msg->user_agent->body);
+	}
+	if ((parse_headers(msg, HDR_SERVER, 0)!=-1) && msg->server &&
+		msg->server->body.len>0) {
+		return &(msg->server->body);
+	}
+
+	notfound.s = UA_DUMMY_STR;
+	notfound.len = UA_DUMMY_LEN;
+
+	return &notfound;
+}
