--- choose_authen.c.orig	Sun Jun 18 13:26:53 2000
+++ choose_authen.c	Sun Dec  8 15:26:08 2002
@@ -118,10 +118,27 @@
 #else /* SKEY */
 	    report(LOG_ERR, 
 		   "%s %s: user %s s/key support has not been compiled in",
-		   name ? name : "<unknown>",
-		   session.peer, session.port);
+		   session.peer, session.port,
+		   name ? name : "<unknown>");
 	    return(CHOOSE_FAILED);
 #endif	/* SKEY */
+	}
+
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
 	}
 
 	/* Not an skey user. Must be none, des, cleartext or file password */
