--- src/dvtitler/textblock.cc.orig	Tue Oct  4 09:15:44 2005
+++ src/dvtitler/textblock.cc	Sat Dec 17 23:25:26 2005
@@ -22,7 +22,7 @@
 #endif
 
 #include "textblock.h"
-#include <stdint.h>
+#include <sys/types.h>
 
 struct DVColor
 {
