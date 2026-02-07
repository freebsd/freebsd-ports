--- plugins/VOIP/VOIP.pro.orig	2016-03-05 21:47:58 UTC
+++ plugins/VOIP/VOIP.pro
@@ -26,6 +26,7 @@ linux-* {
 	PKGCONFIG += opencv
 } else {
 	LIBS += -lspeex -lspeexdsp -lavcodec -lavutil
+	LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc
 }
 
 #################################### Windows #####################################
