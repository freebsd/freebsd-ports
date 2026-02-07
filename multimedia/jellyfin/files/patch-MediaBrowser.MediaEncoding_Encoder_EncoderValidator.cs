--- MediaBrowser.MediaEncoding/Encoder/EncoderValidator.cs.orig	2024-05-17 20:09:34 UTC
+++ MediaBrowser.MediaEncoding/Encoder/EncoderValidator.cs
@@ -371,7 +371,7 @@ namespace MediaBrowser.MediaEncoding.Encoder
 
         public bool CheckVaapiDeviceByDriverName(string driverName, string renderNodePath)
         {
-            if (!OperatingSystem.IsLinux())
+            if (!OperatingSystem.IsLinux() && !OperatingSystem.IsFreeBSD())
             {
                 return false;
             }
@@ -395,7 +395,7 @@ namespace MediaBrowser.MediaEncoding.Encoder
 
         public bool CheckVulkanDrmDeviceByExtensionName(string renderNodePath, string[] vulkanExtensions)
         {
-            if (!OperatingSystem.IsLinux())
+            if (!OperatingSystem.IsLinux() && !OperatingSystem.IsFreeBSD())
             {
                 return false;
             }
