--- gpu/command_buffer/client/test_shared_image_interface.h.orig	2025-09-06 10:01:20 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.h
@@ -37,7 +37,7 @@ class TestSharedImageInterface : public SharedImageInt
  public:
   TestSharedImageInterface();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // TODO(blundell): Fold this inside of a TestSII::CreateSI() variant and have
   // test clients that need the handle grab it from the created SI.
   static gfx::GpuMemoryBufferHandle CreatePixmapHandle(
