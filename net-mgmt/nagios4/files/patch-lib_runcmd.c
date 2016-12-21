--- lib/runcmd.c.orig	2014-08-12 15:00:01 UTC
+++ lib/runcmd.c
@@ -36,7 +36,7 @@
 #endif
 
 /* Determine whether we have setenv()/unsetenv() (see setenv(3) on Linux) */
-#if _BSD_SOURCE || _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
+#if defined(__DragonFly__) || __FreeBSD__ || _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
 # define HAVE_SETENV
 #endif
 
