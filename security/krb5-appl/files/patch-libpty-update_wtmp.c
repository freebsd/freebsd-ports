--- libpty/update_wtmp.c.orig	2009-11-05 12:15:06.000000000 -0800
+++ libpty/update_wtmp.c	2011-08-31 20:51:26.695908790 -0700
@@ -50,8 +50,13 @@
 ptyint_update_wtmpx(struct utmpx *ent)
 {
 #if !(defined(HAVE_UPDWTMPX) && defined(WTMPX_FILE))
+#ifdef HAVE_UTMPX_H
+    struct utmpx ut;
+#endif
+#ifdef HAVE_UTMP_H
     struct utmp ut;
 #endif
+#endif
 
 #if defined(HAVE_UPDWTMPX) && defined(WTMPX_FILE)
     updwtmpx(WTMPX_FILE, ent);
@@ -62,9 +67,17 @@
     getutmp(ent, &ut);
 #else  /* Emulate getutmp().  Yuck. */
     memset(&ut, 0, sizeof(ut));
+#ifdef HAVE_UTMPX_H
+    strncpy(ut.ut_user, ent->ut_user, sizeof(ut.ut_user));
+#else
     strncpy(ut.ut_name, ent->ut_user, sizeof(ut.ut_name));
+#endif
     strncpy(ut.ut_line, ent->ut_line, sizeof(ut.ut_line));
+#ifdef HAVE_UTMPX_H
+    ut.ut_tv.tv_sec = ent->ut_tv.tv_sec;
+#else
     ut.ut_time = ent->ut_tv.tv_sec;
+#endif
 #ifdef HAVE_STRUCT_UTMP_UT_HOST
     strncpy(ut.ut_host, ent->ut_host, sizeof(ut.ut_host));
     ut.ut_host[sizeof(ut.ut_host) - 1] = '\0';
@@ -88,7 +101,11 @@
 #endif
 #endif /* !HAVE_GETUTMP */
 
+#ifdef HAVE_UTMP_H
     return ptyint_update_wtmp(&ut);
+#else
+    return 0;
+#endif
 #endif /* !(defined(WTMPX_FILE) && defined(HAVE_UPDWTMPX)) */
 }
 
@@ -97,8 +114,13 @@
 #if !(defined(WTMPX_FILE) && defined(HAVE_UPDWTMPX)) \
 	|| !defined(HAVE_SETUTXENT)
 
+#ifdef HAVE_UTMP_H
 long
 ptyint_update_wtmp(struct utmp *ent)
+#ifdef HAVE_SETUTXENT
+long ptyint_update_wtmpx(struct utmpx *utx);
+#endif
+
 {
 #ifndef HAVE_UPDWTMP
     int fd;
@@ -123,3 +145,4 @@
 }
 
 #endif
+#endif
