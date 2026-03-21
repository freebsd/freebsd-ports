--- gpu/ipc/service/shared_image_stub.cc.orig	2026-03-13 06:02:14 UTC
+++ gpu/ipc/service/shared_image_stub.cc
@@ -48,7 +48,7 @@ SharedImageStub::SharedImageStub(GpuChannel* channel, 
       command_buffer_id_(
           CommandBufferIdFromChannelAndRoute(channel->client_id(), route_id)),
       sequence_(channel->scheduler()->CreateSequence(
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           base::FeatureList::IsEnabled(features::kSharedImageStubHighPriority)
               ? SchedulingPriority::kHigh
               : SchedulingPriority::kLow,
