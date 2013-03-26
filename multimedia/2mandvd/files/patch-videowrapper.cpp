--- videowrapper.cpp.orig
+++ videowrapper.cpp
@@ -38,7 +38,7 @@ void videowrapper::delete_videowrapper()
 int videowrapper::load_video(QString filename)
 {
     // *** OUVERTURE DU FICHIER VIDEO ***
-    #ifdef avformat_open_input
+    #if LIBAVFORMAT_VERSION_INT > AV_VERSION_INT(53,5,0)
         if (avformat_open_input(&pFormatCtx,filename.toAscii().data(),NULL,NULL)!=0)
         {
     #else
