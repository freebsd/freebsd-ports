--- ./talk/third_party/mediastreamer/osscard.c.orig	Fri Apr 21 11:06:47 2006
+++ ./talk/third_party/mediastreamer/osscard.c	Fri Apr 21 11:07:03 2006
@@ -342,7 +342,7 @@
 {
 	int p=0,mix_fd;
 	int osscmd;
-	g_return_if_fail(obj->mixdev_name!=NULL);
+	g_return_val_if_fail(obj->mixdev_name!=NULL,-1);
 #ifdef HAVE_SYS_SOUNDCARD_H
 	switch(way){
 		case SND_CARD_LEVEL_GENERAL:
