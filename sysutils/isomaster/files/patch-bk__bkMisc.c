--- bk/bkMisc.c.orig
+++ bk/bkMisc.c
@@ -12,22 +12,22 @@
 * 
 ******************************************************************************/
 
-#include <time.h>
+#include <sys/time.h>
 
 #include "bkInternal.h"
 #include "bkMisc.h"
 
 void maybeUpdateProgress(VolInfo* volInfo)
 {
-    struct timeb timeNow;
+    struct timeval timeNow;
     
     if(volInfo->progressFunction == NULL)
         return;
     
-    ftime(&timeNow);
+    gettimeofday(&timeNow, NULL);
     
-    if(timeNow.time - volInfo->lastTimeCalledProgress.time >= 1 ||
-       timeNow.millitm - volInfo->lastTimeCalledProgress.millitm >= 100)
+    if(timeNow.tv_sec - volInfo->lastTimeCalledProgress.tv_sec >= 1 ||
+       timeNow.tv_usec/1000 - volInfo->lastTimeCalledProgress.tv_usec/1000 >= 100)
     {
         volInfo->progressFunction(volInfo);
         
