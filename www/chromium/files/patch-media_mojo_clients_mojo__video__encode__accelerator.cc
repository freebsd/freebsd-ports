--- media/mojo/clients/mojo_video_encode_accelerator.cc.orig	2019-12-16 21:51:27 UTC
+++ media/mojo/clients/mojo_video_encode_accelerator.cc
@@ -124,7 +124,7 @@ void MojoVideoEncodeAccelerator::Encode(scoped_refptr<
             frame->layout().num_planes());
   DCHECK(vea_.is_bound());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // TODO(crbug.com/1003197): Remove this once we stop supporting STORAGE_DMABUF
   // in VideoEncodeAccelerator.
   if (frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
