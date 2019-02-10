--- 3rdparty/apriltag/common/workerpool.c.orig	2019-01-23 14:54:34 UTC
+++ 3rdparty/apriltag/common/workerpool.c
@@ -34,6 +34,7 @@ either expressed or implied, of the Rege
 #include <pthread.h>
 #include <sched.h>
 #include <assert.h>
+#define _WITH_GETLINE
 #include <stdio.h>
 #include <stdlib.h>
 //#include <inttypes.h>
