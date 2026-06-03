--- app/render/videoparams.cpp.orig	2026-03-01 03:24:41 UTC
+++ app/render/videoparams.cpp
@@ -226,7 +226,7 @@ QString VideoParams::GetFormatName(PixelFormat format)
     break;
   }
 
-  return QCoreApplication::translate("VideoParams", "Unknown (0x%1)").arg(format, 0, 16);
+  return QCoreApplication::translate("VideoParams", "Unknown (0x%1)").arg(static_cast<int>(format), 0, 16);
 }
 
 int VideoParams::GetDividerForTargetResolution(int src_width, int src_height, int dst_width, int dst_height)
