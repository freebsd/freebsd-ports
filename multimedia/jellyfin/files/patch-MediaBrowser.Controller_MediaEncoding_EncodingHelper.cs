--- MediaBrowser.Controller/MediaEncoding/EncodingHelper.cs.orig	2024-05-17 20:09:34 UTC
+++ MediaBrowser.Controller/MediaEncoding/EncodingHelper.cs
@@ -886,7 +886,7 @@ namespace MediaBrowser.Controller.MediaEncoding
         private string GetQsvDeviceArgs(string alias)
         {
             var arg = " -init_hw_device qsv=" + (alias ?? QsvAlias);
-            if (OperatingSystem.IsLinux())
+            if (OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD())
             {
                 // derive qsv from vaapi device
                 return GetVaapiDeviceArgs(null, "iHD", "i915", null, VaapiAlias) + arg + "@" + VaapiAlias;
@@ -957,6 +957,7 @@ namespace MediaBrowser.Controller.MediaEncoding
             var args = new StringBuilder();
             var isWindows = OperatingSystem.IsWindows();
             var isLinux = OperatingSystem.IsLinux();
+            var isFreeBSD = OperatingSystem.IsFreeBSD();
             var isMacOS = OperatingSystem.IsMacOS();
             var optHwaccelType = options.HardwareAccelerationType;
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
@@ -964,7 +965,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
             if (string.Equals(optHwaccelType, "vaapi", StringComparison.OrdinalIgnoreCase))
             {
-                if (!isLinux || !_mediaEncoder.SupportsHwaccel("vaapi"))
+                if ((!isLinux && !isFreeBSD) || !_mediaEncoder.SupportsHwaccel("vaapi"))
                 {
                     return string.Empty;
                 }
@@ -1037,7 +1038,7 @@ namespace MediaBrowser.Controller.MediaEncoding
             }
             else if (string.Equals(optHwaccelType, "qsv", StringComparison.OrdinalIgnoreCase))
             {
-                if ((!isLinux && !isWindows) || !_mediaEncoder.SupportsHwaccel("qsv"))
+                if ((!isLinux && !isWindows && !isFreeBSD) || !_mediaEncoder.SupportsHwaccel("qsv"))
                 {
                     return string.Empty;
                 }
@@ -3967,6 +3968,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
             var isWindows = OperatingSystem.IsWindows();
             var isLinux = OperatingSystem.IsLinux();
+            var isFreeBSD = OperatingSystem.IsFreeBSD();
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
             var isSwDecoder = string.IsNullOrEmpty(vidDecoder);
             var isSwEncoder = !vidEncoder.Contains("qsv", StringComparison.OrdinalIgnoreCase);
@@ -3974,7 +3976,7 @@ namespace MediaBrowser.Controller.MediaEncoding
             var isIntelDx11OclSupported = isWindows
                 && _mediaEncoder.SupportsHwaccel("d3d11va")
                 && isQsvOclSupported;
-            var isIntelVaapiOclSupported = isLinux
+            var isIntelVaapiOclSupported = (isLinux || isFreeBSD)
                 && IsVaapiSupported(state)
                 && isQsvOclSupported;
 
@@ -4435,10 +4437,11 @@ namespace MediaBrowser.Controller.MediaEncoding
             }
 
             var isLinux = OperatingSystem.IsLinux();
+            var isFreeBSD = OperatingSystem.IsFreeBSD();
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
             var isSwDecoder = string.IsNullOrEmpty(vidDecoder);
             var isSwEncoder = !vidEncoder.Contains("vaapi", StringComparison.OrdinalIgnoreCase);
-            var isVaapiFullSupported = isLinux && IsVaapiSupported(state) && IsVaapiFullSupported();
+            var isVaapiFullSupported = (isLinux || isFreeBSD) && IsVaapiSupported(state) && IsVaapiFullSupported();
             var isVaapiOclSupported = isVaapiFullSupported && IsOpenclFullSupported();
             var isVaapiVkSupported = isVaapiFullSupported && IsVulkanFullSupported();
 
@@ -5821,11 +5824,12 @@ namespace MediaBrowser.Controller.MediaEncoding
         {
             var isWindows = OperatingSystem.IsWindows();
             var isLinux = OperatingSystem.IsLinux();
+            var isFreeBSD = OperatingSystem.IsFreeBSD();
             var isMacOS = OperatingSystem.IsMacOS();
             var isD3d11Supported = isWindows && _mediaEncoder.SupportsHwaccel("d3d11va");
-            var isVaapiSupported = isLinux && IsVaapiSupported(state);
+            var isVaapiSupported = (isLinux || isFreeBSD) && IsVaapiSupported(state);
             var isCudaSupported = (isLinux || isWindows) && IsCudaFullSupported();
-            var isQsvSupported = (isLinux || isWindows) && _mediaEncoder.SupportsHwaccel("qsv");
+            var isQsvSupported = (isLinux || isWindows || isFreeBSD) && _mediaEncoder.SupportsHwaccel("qsv");
             var isVideotoolboxSupported = isMacOS && _mediaEncoder.SupportsHwaccel("videotoolbox");
             var isRkmppSupported = isLinux && IsRkmppFullSupported();
             var isCodecAvailable = options.HardwareDecodingCodecs.Contains(videoCodec, StringComparison.OrdinalIgnoreCase);
@@ -5945,8 +5949,9 @@ namespace MediaBrowser.Controller.MediaEncoding
         {
             var isWindows = OperatingSystem.IsWindows();
             var isLinux = OperatingSystem.IsLinux();
+            var isFreeBSD = OperatingSystem.IsFreeBSD();
 
-            if ((!isWindows && !isLinux)
+            if ((!isWindows && !isLinux && !isFreeBSD)
                 || !string.Equals(options.HardwareAccelerationType, "qsv", StringComparison.OrdinalIgnoreCase))
             {
                 return null;
@@ -5956,7 +5961,7 @@ namespace MediaBrowser.Controller.MediaEncoding
             var isIntelDx11OclSupported = isWindows
                 && _mediaEncoder.SupportsHwaccel("d3d11va")
                 && isQsvOclSupported;
-            var isIntelVaapiOclSupported = isLinux
+            var isIntelVaapiOclSupported = (isLinux || isFreeBSD)
                 && IsVaapiSupported(state)
                 && isQsvOclSupported;
             var hwSurface = (isIntelDx11OclSupported || isIntelVaapiOclSupported)
@@ -6136,7 +6141,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
         public string GetVaapiVidDecoder(EncodingJobInfo state, EncodingOptions options, MediaStream videoStream, int bitDepth)
         {
-            if (!OperatingSystem.IsLinux()
+            if ((!OperatingSystem.IsLinux() && !OperatingSystem.IsFreeBSD())
                 || !string.Equals(options.HardwareAccelerationType, "vaapi", StringComparison.OrdinalIgnoreCase))
             {
                 return null;
