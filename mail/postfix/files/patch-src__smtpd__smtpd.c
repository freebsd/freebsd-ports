--- src/smtpd/smtpd.c.orig	2008-03-24 16:38:05.000000000 -0300
+++ src/smtpd/smtpd.c	2008-03-24 16:48:38.000000000 -0300
@@ -2108,14 +2108,14 @@
     if (smtpd_milters != 0
 	&& SMTPD_STAND_ALONE(state) == 0
 	&& (state->saved_flags & MILTER_SKIP_FLAGS) == 0) {
+	PUSH_STRING(saved_sender, state->sender, STR(state->addr_buf)); 
 	err = milter_mail_event(smtpd_milters,
 				milter_argv(state, argc - 2, argv + 2));
 	if (err != 0) {
 	    /* Log reject etc. with correct sender information. */
-	    PUSH_STRING(saved_sender, state->sender, STR(state->addr_buf));
 	    err = check_milter_reply(state, err);
-	    POP_STRING(saved_sender, state->sender);
 	}
+	POP_STRING(saved_sender, state->sender);
 	if (err != 0) {
 	    /* XXX Reset access map side effects. */
 	    mail_reset(state);
@@ -2362,14 +2362,14 @@
 	}
 	if (smtpd_milters != 0
 	    && (state->saved_flags & MILTER_SKIP_FLAGS) == 0) {
+	    PUSH_STRING(saved_rcpt, state->recipient, STR(state->addr_buf));
 	    err = milter_rcpt_event(smtpd_milters,
 				    milter_argv(state, argc - 2, argv + 2));
 	    if (err != 0) {
 		/* Log reject etc. with correct recipient information. */
-		PUSH_STRING(saved_rcpt, state->recipient, STR(state->addr_buf));
 		err = check_milter_reply(state, err);
-		POP_STRING(saved_rcpt, state->recipient);
 	    }
+	    POP_STRING(saved_rcpt, state->recipient);
 	    if (err != 0) {
 		smtpd_chat_reply(state, "%s", err);
 		return (-1);
