--- utils/v4l2-compliance/v4l2-test-buffers.cpp.orig	2020-04-09 16:29:54 UTC
+++ utils/v4l2-compliance/v4l2-test-buffers.cpp
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <signal.h>
 #include <inttypes.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -48,8 +49,8 @@
 #define VIVID_CID_QUEUE_ERROR		(VIVID_CID_VIVID_BASE + 70)
 #define VIVID_CID_REQ_VALIDATE_ERROR	(VIVID_CID_VIVID_BASE + 72)
 
-static struct cv4l_fmt cur_fmt;
-static struct cv4l_fmt cur_m2m_fmt;
+static cv4l_fmt cur_fmt;
+static cv4l_fmt cur_m2m_fmt;
 static int stream_from_fd = -1;
 static bool stream_use_hdr;
 
@@ -354,7 +355,7 @@ int buffer::check(unsigned type, unsigned memory, unsi
 	unsigned timestamp_src = g_timestamp_src();
 	unsigned frame_types = 0;
 	unsigned buf_states = 0;
-	const struct cv4l_fmt &fmt = is_m2m ? cur_m2m_fmt : cur_fmt;
+	const cv4l_fmt &fmt = is_m2m ? cur_m2m_fmt : cur_fmt;
 
 	fail_on_test(g_type() != type);
 	fail_on_test(g_memory() == 0);
