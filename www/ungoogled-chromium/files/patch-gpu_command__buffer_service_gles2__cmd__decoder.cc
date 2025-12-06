--- gpu/command_buffer/service/gles2_cmd_decoder.cc.orig	2025-12-06 13:30:52 UTC
+++ gpu/command_buffer/service/gles2_cmd_decoder.cc
@@ -2850,7 +2850,7 @@ std::unique_ptr<GLES2Decoder> GLES2Decoder::Create(
   }
 
 // Allow linux to run fuzzers.
-#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<GLES2DecoderImpl>(client, command_buffer_service,
                                             outputter, group);
 #else
