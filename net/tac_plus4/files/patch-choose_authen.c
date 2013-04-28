--- choose_authen.c.orig	2012-04-17 01:42:55.000000000 +0400
+++ choose_authen.c	2013-04-13 13:55:20.000000000 +0400
@@ -130,12 +130,29 @@
 #else /* SKEY */
 	    report(LOG_ERR,
 		   "%s %s: user %s s/key support has not been compiled in",
-		   name ? name : "<unknown>",
-		   session.peer, session.port);
+		   session.peer, session.port,
+		   name ? name : "<unknown>");
 	    return(CHOOSE_FAILED);
 #endif	/* SKEY */
 	}
 
+	if (cfg_passwd && STREQ(cfg_passwd, "opie")) {
+	    if (debug & DEBUG_PASSWD_FLAG)
+		report(LOG_DEBUG, "%s %s: user %s requires opie",
+			session.peer, session.port, name);
+#ifdef OPIE
+		type->authen_func = opie_fn;
+		strcpy(type->authen_name, "opie_fn");
+		return (CHOOSE_OK);
+#else /* OPIE */
+		report(LOG_ERR,
+			"%s %s: user %s opie support has not been compiled in",
+			session.peer, session.port,
+			name ? name : "<unknown>");
+		return(CHOOSE_FAILED);
+#endif /* OPIE */
+	}
+
 	/* Does this user require aceclnt */
 	cfg_passwd = cfg_get_login_secret(name, TAC_PLUS_RECURSE);
 	if (cfg_passwd && STREQ(cfg_passwd, "aceclnt")) {
