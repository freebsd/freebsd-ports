--- libpty/logwtmp.c.orig	2009-11-05 12:15:06.000000000 -0800
+++ libpty/logwtmp.c	2011-08-31 20:37:06.438225202 -0700
@@ -104,8 +104,13 @@
     ut.ut_host[sizeof(ut.ut_host) - 1] = '\0';
 #endif
     strncpy(ut.ut_line, tty, sizeof(ut.ut_line));
+#ifdef HAVE_UTMPX_H
+    strncpy(ut.ut_user, user, sizeof(ut.ut_user));
+    return ptyint_update_wtmpx(&utx);
+#else
     strncpy(ut.ut_name, user, sizeof(ut.ut_name));
     return ptyint_update_wtmp(&ut);
+#endif
 
 #endif /* !HAVE_LOGWTMP */
 }
