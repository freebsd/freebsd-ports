--- input/joystick.c.orig	2007-10-08 03:49:26.000000000 +0800
+++ input/joystick.c	2007-10-20 16:00:20.000000000 +0800
@@ -24,8 +24,6 @@
 #define JS_DEV "/dev/input/js0"
 #endif
 
-#ifdef TARGET_LINUX
-
 #include <linux/joystick.h>
 
 int axis[256];
@@ -145,18 +143,3 @@
 
   return MP_INPUT_NOTHING;
 }
-
-#else /* TARGET_LINUX */
-
-// dummy function
-
-int mp_input_joystick_init(char* dev) {
-  return -1;
-}
-
-int mp_input_joystick_read(int fd) {
-  
-  return MP_INPUT_NOTHING;
-}
-
-#endif /* TARGET_LINUX */
