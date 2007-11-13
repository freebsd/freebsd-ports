An official patch obtained from ftp://stunnel.mirt.net/stunnel/setuid.patch

--- src/stunnel.c.old	2007-11-12 11:30:38.000000000 +0200
+++ src/stunnel.c	2007-11-12 11:30:48.000000000 +0200
@@ -3,8 +3,8 @@
  *   Copyright (c) 1998-2007 Michal Trojnara <Michal.Trojnara@mirt.net>
  *                 All Rights Reserved
  *
- *   Version:      4.21             (stunnel.c)
- *   Date:         2007.10.27
+ *   Version:      4.22             (stunnel.c)
+ *   Date:         2007.11.xx
  *
  *   Author:       Michal Trojnara  <Michal.Trojnara@mirt.net>
  *
@@ -41,7 +41,7 @@
 static void accept_connection(LOCAL_OPTIONS *);
 static void get_limits(void); /* setup global max_clients and max_fds */
 #if !defined (USE_WIN32) && !defined (__vms)
-static void make_chroot(void);
+static void drop_privileges(void);
 static void daemonize(void);
 static void create_pid(void);
 static void delete_pid(void);
@@ -111,9 +111,6 @@
     } else { /* inetd mode */
 #if !defined (USE_WIN32) && !defined (__vms)&&!defined(USE_OS2)
         max_fds=FD_SETSIZE; /* just in case */
-#ifdef HAVE_CHROOT
-        make_chroot();
-#endif /* HAVE_CHROOT */
         drop_privileges();
 #endif
         num_clients=1;
@@ -171,9 +168,6 @@
 #if !defined (USE_WIN32) && !defined (__vms) && !defined(USE_OS2)
     if(!(options.option.foreground))
         daemonize();
-#ifdef HAVE_CHROOT
-        make_chroot();
-#endif /* HAVE_CHROOT */
     drop_privileges();
     create_pid();
 #endif /* !defined USE_WIN32 && !defined (__vms) */
@@ -299,24 +293,9 @@
 #endif
 }
 
-#ifdef HAVE_CHROOT
-static void make_chroot(void) {
-    if(options.chroot_dir) {
-        if(chroot(options.chroot_dir)) {
-            sockerror("chroot");
-            exit(1);
-        }
-        if(chdir("/")) {
-            sockerror("chdir");
-            exit(1);
-        }
-    }
-}
-#endif /* HAVE_CHROOT */
-
 #if !defined (USE_WIN32) && !defined (__vms)
-    /* set process user and group(s) id */
-void drop_privileges(void) {
+    /* chroot and set process user and group(s) id */
+static void drop_privileges(void) {
     int uid=0, gid=0;
     struct group *gr;
 #ifdef HAVE_SETGROUPS
@@ -350,6 +329,20 @@
         }
     }
 
+#ifdef HAVE_CHROOT
+    /* chroot */
+    if(options.chroot_dir) {
+        if(chroot(options.chroot_dir)) {
+            sockerror("chroot");
+            exit(1);
+        }
+        if(chdir("/")) {
+            sockerror("chdir");
+            exit(1);
+        }
+    }
+#endif /* HAVE_CHROOT */
+
     /* Set uid and gid */
     if(gid) {
         if(setgid(gid)) {
