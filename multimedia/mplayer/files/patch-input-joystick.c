--- input/joystick.c.orig	Sat Mar 31 05:10:08 2007
+++ input/joystick.c	Sat Mar 31 05:09:30 2007
@@ -24,8 +24,6 @@
 #define JS_DEV "/dev/input/js0"
 #endif
 
-#ifdef TARGET_LINUX
-
 #include <linux/joystick.h>
 
 int axis[256];
@@ -147,17 +145,3 @@
   return MP_INPUT_NOTHING;
 }
 
-#else
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
-#endif
