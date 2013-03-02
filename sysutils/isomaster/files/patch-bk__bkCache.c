--- bk/bkCache.c.orig
+++ bk/bkCache.c
@@ -21,7 +21,7 @@
 
 #include <string.h>
 #include <stdio.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -57,11 +57,11 @@
     
     if(volInfo->writeProgressFunction != NULL)
     {
-        struct timeb timeNow;
-        ftime(&timeNow);
+        struct timeval timeNow;
+        gettimeofday(&timeNow, NULL);
         
-        if(timeNow.time - volInfo->lastTimeCalledProgress.time >= 1 ||
-           timeNow.millitm - volInfo->lastTimeCalledProgress.millitm >= 100)
+        if(timeNow.tv_sec - volInfo->lastTimeCalledProgress.tv_sec >= 1 ||
+           timeNow.tv_usec/1000 - volInfo->lastTimeCalledProgress.tv_usec/1000 >= 100)
         {
             BkStatStruct statStruct;
             double percentComplete;
