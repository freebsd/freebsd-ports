--- mojo/public/c/system/message_pipe.h.orig	2018-05-09 19:05:53 UTC
+++ mojo/public/c/system/message_pipe.h
@@ -44,7 +44,7 @@ const MojoCreateMessagePipeOptionsFlags
   ((MojoCreateMessagePipeOptionsFlags)0)
 #endif
 
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 struct MOJO_ALIGNAS(8) MojoCreateMessagePipeOptions {
   uint32_t struct_size;
   MojoCreateMessagePipeOptionsFlags flags;
