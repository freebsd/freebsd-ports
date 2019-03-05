--- src/3rdparty/chromium/mojo/public/c/system/buffer.h.orig	2018-04-10 14:05:55 UTC
+++ src/3rdparty/chromium/mojo/public/c/system/buffer.h
@@ -40,7 +40,7 @@ const MojoCreateSharedBufferOptionsFlags
   ((MojoCreateSharedBufferOptionsFlags)0)
 #endif
 
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 struct MOJO_ALIGNAS(8) MojoCreateSharedBufferOptions {
   uint32_t struct_size;
   MojoCreateSharedBufferOptionsFlags flags;
