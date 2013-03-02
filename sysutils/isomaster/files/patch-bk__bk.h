--- bk/bk.h.orig
+++ bk/bk.h
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <limits.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <stdio.h>
 
 #include "bkError.h"
@@ -186,7 +186,7 @@
     int imageForWriting;
     void(*progressFunction)(struct VolInfo*);
     void(*writeProgressFunction)(struct VolInfo*, double);
-    struct timeb lastTimeCalledProgress;
+    struct timeval lastTimeCalledProgress;
     bk_off_t estimatedIsoSize;
     BkHardLink* fileLocations; /* list of where to find regular files */
     char readWriteBuffer[READ_WRITE_BUFFER_SIZE];
