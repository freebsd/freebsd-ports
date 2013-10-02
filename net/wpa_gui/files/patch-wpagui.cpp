--- wpagui.cpp.orig	2010-09-07 15:43:39.000000000 +0000
+++ wpagui.cpp
@@ -12,10 +12,7 @@
  * See README and COPYING for more details.
  */
 
-#ifdef __MINGW32__
-/* Need to get getopt() */
 #include <unistd.h>
-#endif
 
 #ifdef CONFIG_NATIVE_WINDOWS
 #include <windows.h>
