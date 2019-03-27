--- src/3rdparty/chromium/mojo/public/c/system/data_pipe.h.orig	2018-04-10 14:05:55 UTC
+++ src/3rdparty/chromium/mojo/public/c/system/data_pipe.h
@@ -40,7 +40,7 @@ struct MOJO_ALIGNAS(8) MojoCreateDataPipeOptions {
   // system-dependent capacity of at least one element in size.
   uint32_t capacity_num_bytes;
 };
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 MOJO_STATIC_ASSERT(sizeof(MojoCreateDataPipeOptions) == 16,
                    "MojoCreateDataPipeOptions has wrong size");
 
