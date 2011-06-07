--- ./ext/mpeg2enc/gstmpeg2encoder.cc.orig	2011-06-07 12:41:52.230187424 +0200
+++ ./ext/mpeg2enc/gstmpeg2encoder.cc	2011-06-07 12:42:40.731015830 +0200
@@ -27,9 +27,8 @@
 #include <mpegconsts.h>
 #include <quantize.hh>
 #if GST_MJPEGTOOLS_API >= 10900
-#include <ontheflyratectl.hh>
-#include <pass1ratectl.hh>
-#include <pass2ratectl.hh>
+#include <ontheflyratectlpass1.hh>
+#include <ontheflyratectlpass2.hh>
 #else
 #include <ratectl.hh>
 #endif
