--- avidemux_plugins/ADM_videoEncoder/x265/qt4/Q_x265.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/x265/qt4/Q_x265.cpp
@@ -38,7 +38,7 @@ typedef struct
 }idcToken;
 
 static const idcToken listOfIdc[]={
-        {-1,"Auto"},
+        {(unsigned int)-1,"Auto"},
         {10,"1"},
         {20,"2"},
         {21,"2.1"},
