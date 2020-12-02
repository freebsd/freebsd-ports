--- utils/v4l2-compliance/v4l2-test-buffers.cpp.orig	2020-12-02 20:09:09 UTC
+++ utils/v4l2-compliance/v4l2-test-buffers.cpp
@@ -32,6 +32,7 @@
 #include <ctype.h>
 #include <errno.h>
 #include <poll.h>
+#include <signal.h>
 #include <sys/ioctl.h>
 #include <netinet/in.h>
 #include <map>
