--- ./talk/third_party/mediastreamer/msrtprecv.h.orig	Thu Mar 16 18:43:05 2006
+++ ./talk/third_party/mediastreamer/msrtprecv.h	Fri Apr 21 10:56:34 2006
@@ -47,6 +47,8 @@
 	RtpSession *rtpsession;
 	guint32 prev_ts;
 	gint stream_started;
+	gint payload_expected;
+	gboolean ignore;
 };
 
 typedef struct _MSRtpRecv MSRtpRecv;
