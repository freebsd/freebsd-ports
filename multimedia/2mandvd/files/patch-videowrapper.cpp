diff -urN videowrapper.cpp videowrapper.cpp
--- videowrapper.cpp	2012-06-06 20:25:24.000000000 +1100
+++ videowrapper.cpp	2013-08-03 10:54:05.426228163 +1100
@@ -38,7 +38,7 @@
 int videowrapper::load_video(QString filename)
 {
     // *** OUVERTURE DU FICHIER VIDEO ***
-    #ifdef avformat_open_input
+#if LIBAVFORMAT_VERSION_MAJOR >= 53
         if (avformat_open_input(&pFormatCtx,filename.toAscii().data(),NULL,NULL)!=0)
         {
     #else
@@ -90,7 +90,7 @@
 
     // *** OUVERTURE DU CODEC ***
 
-    if(avcodec_open(pCodecCtx, pCodec)<0)
+    if(avcodec_open2(pCodecCtx, pCodec, NULL)<0)
     {
         qDebug() << "CAN'T FIND VIDEO CODEC";
         return 1;
