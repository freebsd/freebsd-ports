--- utils/v4l2-ctl/v4l2-ctl-vidcap.cpp.orig	2020-12-30 21:13:40 UTC
+++ utils/v4l2-ctl/v4l2-ctl-vidcap.cpp
@@ -14,6 +14,7 @@
 #include <dirent.h>
 #include <math.h>
 #include <cstdlib>
+#include <sys/endian.h>
 
 #include "v4l2-ctl.h"
 
