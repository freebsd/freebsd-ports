--- programs/mythtranscode/mpeg2fix.cpp.orig	2009-11-02 20:52:39.000000000 +0100
+++ programs/mythtranscode/mpeg2fix.cpp	2009-11-02 20:53:08.000000000 +0100
@@ -12,6 +12,10 @@
 #include <getopt.h>
 #include <stdint.h>
 
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
+
 #include "config.h"
 #include "mpeg2fix.h"
 
