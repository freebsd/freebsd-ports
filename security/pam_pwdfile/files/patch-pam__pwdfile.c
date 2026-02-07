--- pam_pwdfile.c.orig	2025-04-02 18:36:58 UTC
+++ pam_pwdfile.c
@@ -42,9 +42,6 @@
 #define _GNU_SOURCE
 #include <crypt.h>
 #else
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE 700
-#endif
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE
 #endif
@@ -66,7 +63,8 @@
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
-#include <security/pam_ext.h>
+
+#define pam_syslog(H, C, ...)  syslog(C, __VA_ARGS__)
 
 static int lock_fd(int fd) {
     int delay;
