--- misc/Misc.h.orig	Tue Jul 22 16:14:35 2003
+++ misc/Misc.h	Tue Jul 22 16:14:59 2003
@@ -26,7 +26,9 @@
 #ifndef MISC_H
 #define MISC_H
 
-#include <strstream.h>
+#include <strstream>
+
+using std::ostrstream;
 
 class Misc
 {
