--- mojo/public/c/system/data_pipe.h.orig	2018-05-09 19:05:53 UTC
+++ mojo/public/c/system/data_pipe.h
@@ -46,7 +46,7 @@ const MojoCreateDataPipeOptionsFlags MOJO_CREATE_DATA_
   ((MojoCreateDataPipeOptionsFlags)0)
 #endif
 
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 struct MOJO_ALIGNAS(8) MojoCreateDataPipeOptions {
   MOJO_ALIGNAS(4) uint32_t struct_size;
   MOJO_ALIGNAS(4) MojoCreateDataPipeOptionsFlags flags;
