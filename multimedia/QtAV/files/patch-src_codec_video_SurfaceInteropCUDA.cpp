--- src/codec/video/SurfaceInteropCUDA.cpp.orig	2020-08-26 17:34:29 UTC
+++ src/codec/video/SurfaceInteropCUDA.cpp
@@ -132,7 +132,7 @@ bool HostInteropResource::map(int picIndex, const CUVI
         if (!ensureResource(pitch, H)) //copy height is coded height
             return false;
         // the same thread (context) as cuMemAllocHost, so no ccontext switch is needed
-        CUDA_ENSURE(cuMemcpyDtoH(host_mem.data, devptr, pitch*H*3/2), NULL);
+        CUDA_ENSURE(cuMemcpyDtoH(host_mem.data, devptr, pitch*H*3/2), false);
         host_mem.index = picIndex;
     }
     // map to texture
@@ -173,7 +173,7 @@ bool HostInteropResource::ensureResource(int pitch, in
     if (!share_ctx) // cuMemFreeHost will be called in dtor which is not the current thread.
         CUDA_WARN(cuCtxPushCurrent(ctx));
     // NV12
-    CUDA_ENSURE(cuMemAllocHost((void**)&host_mem.data, pitch*height*3/2), NULL);
+    CUDA_ENSURE(cuMemAllocHost((void**)&host_mem.data, pitch*height*3/2), false);
     if (!share_ctx)
         CUDA_WARN(cuCtxPopCurrent(NULL)); //can be null or &ctx
     return true;
