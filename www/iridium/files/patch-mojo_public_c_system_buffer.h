--- mojo/public/c/system/buffer.h.orig	2018-05-09 19:05:53 UTC
+++ mojo/public/c/system/buffer.h
@@ -35,7 +35,7 @@ const MojoCreateSharedBufferOptionsFlags
   ((MojoCreateSharedBufferOptionsFlags)0)
 #endif
 
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 struct MOJO_ALIGNAS(8) MojoCreateSharedBufferOptions {
   uint32_t struct_size;
   MojoCreateSharedBufferOptionsFlags flags;
