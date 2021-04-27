--- media/mojo/clients/mojo_video_encode_accelerator.cc.orig	2021-04-14 18:41:05 UTC
+++ media/mojo/clients/mojo_video_encode_accelerator.cc
@@ -134,7 +134,7 @@ void MojoVideoEncodeAccelerator::Encode(scoped_refptr<
   DCHECK_EQ(num_planes, frame->layout().num_planes());
   DCHECK(vea_.is_bound());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(crbug.com/1003197): Remove this once we stop supporting STORAGE_DMABUF
   // in VideoEncodeAccelerator.
   if (frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
