--- media/mojo/mojom/video_frame_mojom_traits.cc.orig	2024-11-16 12:20:41 UTC
+++ media/mojo/mojom/video_frame_mojom_traits.cc
@@ -27,7 +27,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -152,7 +152,7 @@ media::mojom::VideoFrameDataPtr MakeVideoFrameData(
             std::move(shared_image), std::move(mailbox_holder.sync_token),
             std::move(mailbox_holder.texture_target),
             std::move(input->ycbcr_info())));
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (input->HasOOPVDMailbox()) {
     return media::mojom::VideoFrameData::NewMailboxData(
         media::mojom::MailboxVideoFrameData::New(input->oopvd_mailbox()));
@@ -353,7 +353,7 @@ bool StructTraits<media::mojom::VideoFrameDataView,
     frame = media::VideoFrame::WrapExternalGpuMemoryBuffer(
         visible_rect, natural_size, std::move(gpu_memory_buffer), shared_image,
         sync_token, base::NullCallback(), timestamp);
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (data.is_mailbox_data()) {
     media::mojom::MailboxVideoFrameDataDataView mailbox_data;
     data.GetMailboxDataDataView(&mailbox_data);
