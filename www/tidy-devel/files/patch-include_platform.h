--- ./include/platform.h.orig	Mon Jul  8 08:50:02 2002
+++ ./include/platform.h	Sat Jul 27 10:55:37 2002
@@ -28,7 +28,7 @@
   variable is not set. Contributed by Todd Lewis.
 */
 
-/* #define SUPPORT_GETPWNAM */
+#define SUPPORT_GETPWNAM
 
 /* Enable/disable support for Big5 and Shift_JIS character encodings */
 #ifndef SUPPORT_ASIAN_ENCODINGS
