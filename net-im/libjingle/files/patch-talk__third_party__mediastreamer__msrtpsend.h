--- talk/third_party/mediastreamer/msrtpsend.h.orig	Fri May  5 23:32:24 2006
+++ talk/third_party/mediastreamer/msrtpsend.h	Fri May  5 23:32:42 2006
@@ -34,7 +34,7 @@
 
 #define MSRTPSEND_MAX_INPUTS  1 /* max input per filter*/
 
-#define MSRTPSEND_DEF_GRAN  4096/* the default granularity*/
+#define MSRTPSEND_DEF_GRAN 160	/* the default granularity*/
 
 struct _MSRtpSend
 {
