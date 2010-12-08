--- mythvideo/mythvideo/videodlg.h.orig	2009-11-28 19:50:27.000000000 +0100
+++ mythvideo/mythvideo/videodlg.h	2010-12-05 14:00:27.000000000 +0100
@@ -150,7 +150,7 @@
     QString RemoteImageCheck(QString host, QString filename);
     QString GetCoverImage(MythGenericTree *node);
     QString GetFirstImage(MythGenericTree *node, QString type,
-                          QString gpnode = NULL, int levels = 0);
+                          QString gpnode = QString(), int levels = 0);
     QString GetImageFromFolder(Metadata *metadata);
     QString GetScreenshot(MythGenericTree *node);
     QString GetBanner(MythGenericTree *node);
