--- MediaBrowser.Controller/MediaEncoding/EncodingHelper.cs.orig	2024-11-03 15:57:46 UTC
+++ MediaBrowser.Controller/MediaEncoding/EncodingHelper.cs
@@ -894,7 +894,7 @@ namespace MediaBrowser.Controller.MediaEncoding
         private string GetQsvDeviceArgs(string renderNodePath, string alias)
         {
             var arg = " -init_hw_device qsv=" + (alias ?? QsvAlias);
-            if (OperatingSystem.IsLinux())
+            if (OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD())
             {
                 // derive qsv from vaapi device
                 return GetVaapiDeviceArgs(renderNodePath, "iHD", "i915", "0x8086", null, VaapiAlias) + arg + "@" + VaapiAlias;
@@ -970,7 +970,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
             var args = new StringBuilder();
             var isWindows = OperatingSystem.IsWindows();
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
             var isMacOS = OperatingSystem.IsMacOS();
             var optHwaccelType = options.HardwareAccelerationType;
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
@@ -1807,11 +1807,15 @@ namespace MediaBrowser.Controller.MediaEncoding
             }
             else if (hardwareAccelerationType == HardwareAccelerationType.qsv)
             {
-                if (OperatingSystem.IsLinux())
+                if (OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD())
                 {
                     var ver = Environment.OSVersion.Version;
                     var isFixedKernel60 = ver.Major == 6 && ver.Minor == 0 && ver >= _minFixedKernel60i915Hang;
                     var isUnaffectedKernel = ver < _minKerneli915Hang || ver > _maxKerneli915Hang;
+                    if (OperatingSystem.IsFreeBSD()) {
+                        isFixedKernel60 = true;
+                        isUnaffectedKernel = true;
+                    }
 
                     if (!(isUnaffectedKernel || isFixedKernel60))
                     {
@@ -4009,7 +4013,7 @@ namespace MediaBrowser.Controller.MediaEncoding
             }
 
             var isWindows = OperatingSystem.IsWindows();
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
             var isSwDecoder = string.IsNullOrEmpty(vidDecoder);
             var isSwEncoder = !vidEncoder.Contains("qsv", StringComparison.OrdinalIgnoreCase);
@@ -4598,7 +4602,7 @@ namespace MediaBrowser.Controller.MediaEncoding
                 return (null, null, null);
             }
 
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
             var isSwDecoder = string.IsNullOrEmpty(vidDecoder);
             var isSwEncoder = !vidEncoder.Contains("vaapi", StringComparison.OrdinalIgnoreCase);
@@ -5535,7 +5539,7 @@ namespace MediaBrowser.Controller.MediaEncoding
                 return (null, null, null);
             }
 
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
             var vidDecoder = GetHardwareVideoDecoder(state, options) ?? string.Empty;
             var isSwDecoder = string.IsNullOrEmpty(vidDecoder);
             var isSwEncoder = !vidEncoder.Contains("rkmpp", StringComparison.OrdinalIgnoreCase);
@@ -6128,7 +6132,7 @@ namespace MediaBrowser.Controller.MediaEncoding
         public string GetHwaccelType(EncodingJobInfo state, EncodingOptions options, string videoCodec, int bitDepth, bool outputHwSurface)
         {
             var isWindows = OperatingSystem.IsWindows();
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
             var isMacOS = OperatingSystem.IsMacOS();
             var isD3d11Supported = isWindows && _mediaEncoder.SupportsHwaccel("d3d11va");
             var isVaapiSupported = isLinux && IsVaapiSupported(state);
@@ -6281,7 +6285,7 @@ namespace MediaBrowser.Controller.MediaEncoding
         public string GetQsvHwVidDecoder(EncodingJobInfo state, EncodingOptions options, MediaStream videoStream, int bitDepth)
         {
             var isWindows = OperatingSystem.IsWindows();
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
 
             if ((!isWindows && !isLinux)
                 || options.HardwareAccelerationType != HardwareAccelerationType.qsv)
@@ -6363,7 +6367,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
         public string GetNvdecVidDecoder(EncodingJobInfo state, EncodingOptions options, MediaStream videoStream, int bitDepth)
         {
-            if ((!OperatingSystem.IsWindows() && !OperatingSystem.IsLinux())
+            if ((!OperatingSystem.IsWindows() && (!OperatingSystem.IsLinux() && !OperatingSystem.IsFreeBSD()))
                 || options.HardwareAccelerationType != HardwareAccelerationType.nvenc)
             {
                 return null;
@@ -6492,7 +6496,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
         public string GetVaapiVidDecoder(EncodingJobInfo state, EncodingOptions options, MediaStream videoStream, int bitDepth)
         {
-            if (!OperatingSystem.IsLinux()
+            if ((!OperatingSystem.IsLinux() && !OperatingSystem.IsFreeBSD())
                 || options.HardwareAccelerationType != HardwareAccelerationType.vaapi)
             {
                 return null;
@@ -6622,7 +6626,7 @@ namespace MediaBrowser.Controller.MediaEncoding
 
         public string GetRkmppVidDecoder(EncodingJobInfo state, EncodingOptions options, MediaStream videoStream, int bitDepth)
         {
-            var isLinux = OperatingSystem.IsLinux();
+            var isLinux = OperatingSystem.IsLinux() || OperatingSystem.IsFreeBSD();
 
             if (!isLinux
                 || options.HardwareAccelerationType != HardwareAccelerationType.rkmpp)
