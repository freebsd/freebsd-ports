--- src/updownclient.h.orig	Sun May 25 18:27:59 2003
+++ src/updownclient.h	Tue May 27 21:14:31 2003
@@ -26,12 +26,20 @@
 #include "SafeFile.h"
 #include "BarShader.h"
 #include "otherfunctions.h"
+#include <sys/time.h>
 
 class CPartFile;
 class CKnownFile;
 typedef unsigned char byte;
-extern inline long GetTickCount();
 
+inline long GetTickCount()
+{
+  struct timeval aika;
+  gettimeofday(&aika,NULL);
+  unsigned long secs=aika.tv_sec*1000;
+  secs+=(aika.tv_usec/1000);
+  return secs;
+}
 
 // uploadstate
 #define	US_UPLOADING		0
