--- MediaBrowser.MediaEncoding/Encoder/MediaEncoder.cs.orig	2024-05-17 20:09:34 UTC
+++ MediaBrowser.MediaEncoding/Encoder/MediaEncoder.cs
@@ -198,7 +198,7 @@ namespace MediaBrowser.MediaEncoding.Encoder
                 _isPkeyPauseSupported = validator.CheckSupportedRuntimeKey("p      pause transcoding");
 
                 // Check the Vaapi device vendor
-                if (OperatingSystem.IsLinux()
+                if ((OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD())
                     && SupportsHwaccel("vaapi")
                     && !string.IsNullOrEmpty(options.VaapiDevice)
                     && string.Equals(options.HardwareAccelerationType, "vaapi", StringComparison.OrdinalIgnoreCase))
