--- utils/v4l2-ctl/v4l2-ctl-streaming.cpp.orig	2022-01-25 16:28:52 UTC
+++ utils/v4l2-ctl/v4l2-ctl-streaming.cpp
@@ -2,6 +2,8 @@
 
 #include <netdb.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 
 #include <linux/media.h>
 
