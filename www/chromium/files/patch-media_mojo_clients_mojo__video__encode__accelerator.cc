--- media/mojo/clients/mojo_video_encode_accelerator.cc.orig	2020-11-13 06:36:44 UTC
+++ media/mojo/clients/mojo_video_encode_accelerator.cc
@@ -132,7 +132,7 @@ void MojoVideoEncodeAccelerator::Encode(scoped_refptr<
   DCHECK_EQ(num_planes, frame->layout().num_planes());
   DCHECK(vea_.is_bound());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // TODO(crbug.com/1003197): Remove this once we stop supporting STORAGE_DMABUF
   // in VideoEncodeAccelerator.
   if (frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
