--- src/xlib/main.c.orig	2016-12-21 09:12:44 UTC
+++ src/xlib/main.c
@@ -35,7 +35,9 @@ void postmessage(uint32_t msg, uint16_t 
     XFlush(display);
 }
 
+#ifdef __LINUX__
 #include <linux/input.h>
+#endif
 FILE *   ptt_keyboard_handle;
 Display *ptt_display;
 void     init_ptt(void) {
@@ -60,6 +62,7 @@ bool check_ptt_key(void) {
     int ptt_key;
 
     /* First, we try for direct access to the keyboard. */
+#ifdef __LINUX__
     ptt_key = KEY_LEFTCTRL; // TODO allow user to change this...
     if (ptt_keyboard_handle) {
         /* Nice! we have direct access to the keyboard! */
@@ -78,6 +81,7 @@ bool check_ptt_key(void) {
             return 0;
         }
     }
+#endif
     /* Okay nope, lets' fallback to xinput... *pouts*
      * Fall back to Querying the X for the current keymap. */
     ptt_key       = XKeysymToKeycode(display, XK_Control_L);
