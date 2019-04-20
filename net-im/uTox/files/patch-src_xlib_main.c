Based on:
https://github.com/uTox/uTox/commit/22b183433c37d51867ec4eb55813ac2b1db6477c

--- src/xlib/main.c.orig	2019-02-17 05:10:45 UTC
+++ src/xlib/main.c
@@ -94,6 +94,11 @@ void init_ptt(void) {
 
 #ifdef __linux__
 #include <linux/input.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+#include <linux/input.h>
+#endif
+
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
 static bool linux_check_ptt(void) {
     /* First, we try for direct access to the keyboard. */
     int ptt_key = KEY_LEFTCTRL; // TODO allow user to change this...
@@ -146,7 +151,7 @@ bool check_ptt_key(void) {
         return true; /* If push to talk is disabled, return true. */
     }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
     return linux_check_ptt();
 #else
     return bsd_check_ptt();
