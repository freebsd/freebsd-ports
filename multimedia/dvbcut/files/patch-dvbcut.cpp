--- src/dvbcut.cpp.orig	2016-06-23 12:34:35 UTC
+++ src/dvbcut.cpp
@@ -1232,7 +1232,7 @@ void dvbcut::playPlay()
   arguments << "-geometry" << QString().sprintf("%dx%d+0+0",int(ui->imagedisplay->width()),int(ui->imagedisplay->height()));
 
   if (currentaudiotrack>=0 && currentaudiotrack<mpg->getaudiostreams()) {
-    arguments << "-aid" << QString().sprintf("0x%x",int(currentaudiotrack));
+    arguments << "-aid" << QString().sprintf("0x%x", int(mpg->mplayeraudioid(currentaudiotrack)));
     }
     
   // for now, pass all filenames from the current one up to the last one
