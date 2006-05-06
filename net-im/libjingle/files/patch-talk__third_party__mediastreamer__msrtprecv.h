--- ./talk/third_party/mediastreamer/msrtprecv.h.orig	Thu Mar 16 18:43:05 2006
+++ ./talk/third_party/mediastreamer/msrtprecv.h	Fri Apr 21 10:56:34 2006
@@ -34,7 +34,7 @@
 
 #define MSRTPRECV_MAX_OUTPUTS  1 /* max output per filter*/
 
-#define MSRTPRECV_DEF_GRAN 4096 /* the default granularity*/
+#define MSRTPRECV_DEF_GRAN 320	/* the default granularity*/
 
 struct _MSRtpRecv
 {
@@ -47,6 +47,8 @@
 	RtpSession *rtpsession;
 	guint32 prev_ts;
 	gint stream_started;
+	gint payload_expected;
+	gboolean ignore;
 };
 
 typedef struct _MSRtpRecv MSRtpRecv;
