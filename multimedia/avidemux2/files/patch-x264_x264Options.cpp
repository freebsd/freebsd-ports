--- plugins/ADM_videoEncoder/ADM_vidEnc_x264/x264Options.cpp.orig	2011-06-24 13:05:41.000000000 +0200
+++ plugins/ADM_videoEncoder/ADM_vidEnc_x264/x264Options.cpp	2011-06-24 13:07:55.000000000 +0200
@@ -417,7 +417,7 @@ void x264Options::setCabac(bool cabac)
 	_param.b_cabac = cabac;
 }
 
-#if X264_BUILD > 101
+#if X264_BUILD > 101 && X264_BUILD < 115
 unsigned int x264Options::getOpenGopMode(void)
 {
 	return _param.i_open_gop;
@@ -428,6 +428,17 @@ void x264Options::setOpenGopMode(unsigne
 	if (openGopMode < 3)
 		_param.i_open_gop = openGopMode;
 }
+#else X264_BUILD > 114
+unsigned int x264Options::getOpenGopMode(void)
+{
+	return _param.b_open_gop;
+}
+
+void x264Options::setOpenGopMode(unsigned int openGopMode)
+{
+	if (openGopMode < 3)
+		_param.b_open_gop = openGopMode;
+}
 #endif
 
 unsigned int x264Options::getInterlaced(void)
