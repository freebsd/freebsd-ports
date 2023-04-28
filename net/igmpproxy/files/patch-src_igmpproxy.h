--- src/igmpproxy.h.orig	2022-10-29 10:01:46 UTC
+++ src/igmpproxy.h
@@ -115,7 +115,7 @@ void my_log( int Serverity, int Errno, const char *Fmt
 
 /* ifvc.c
  */
-#define MAX_IF         40     // max. number of interfaces recognized
+#define MAX_IF         240     // max. number of interfaces recognized
 
 // Interface states
 #define IF_STATE_DISABLED      0   // Interface should be ignored.
@@ -183,7 +183,7 @@ struct Config {
     unsigned short	defaultInterfaceState;	// 0: disable, 2: downstream
     //~ aimwang added done
     char                chroot[PATH_MAX];
-    char                user[LOGIN_NAME_MAX];
+    char                user[MAXLOGNAME];
 };
 
 // Holds the indeces of the upstream IF...
