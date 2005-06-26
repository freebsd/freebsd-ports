--- kioslave/audiocd/audiocd.cpp.orig	Sat Jun 25 21:47:21 2005
+++ kioslave/audiocd/audiocd.cpp	Sat Jun 25 21:47:33 2005
@@ -71,7 +71,7 @@
 
 #include "audiocd.h"
 
-#include <audiocdencoder.h>
+#include "plugins/audiocdencoder.h"
 
 #include <sys/stat.h>
 #include <unistd.h>
