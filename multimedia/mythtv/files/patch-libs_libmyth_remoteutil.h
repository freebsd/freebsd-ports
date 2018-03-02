--- libs/libmyth/remoteutil.h.orig	2015-06-16 16:03:30 UTC
+++ libs/libmyth/remoteutil.h
@@ -10,6 +10,7 @@
 using namespace std;
 
 #include "mythexp.h"
+#include <sys/types.h>
 
 class ProgramInfo;
 class MythEvent;
