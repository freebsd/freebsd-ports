--- gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc.orig	2025-12-10 15:04:57 UTC
+++ gpu/command_buffer/service/raster_decoder_unittest_context_lost.cc
@@ -15,6 +15,18 @@ using ::testing::Return;
 using ::testing::SaveArg;
 using ::testing::SetArrayArgument;
 
+#ifndef GL_CONTEXT_LOST_KHR
+#define GL_CONTEXT_LOST_KHR 0x0507
+#endif
+
+#ifndef GL_GUILTY_CONTEXT_RESET_KHR
+#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
+#endif
+
+#ifndef GL_INNOCENT_CONTEXT_RESET_KHR
+#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
+#endif
+
 namespace gpu {
 namespace raster {
 
