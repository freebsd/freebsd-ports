--- avidemux_plugins/ADM_videoEncoder/ffDv/ADM_ffDv.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_videoEncoder/ffDv/ADM_ffDv.cpp
@@ -44,7 +44,7 @@ typedef struct
 
 static const dvProfileClass supportedProfiles[]=
 {
-    {720,480,29.97,dvColor422},
+    {720,480,30,dvColor422},
     {720,576,25,dvColor420},
 };
 
