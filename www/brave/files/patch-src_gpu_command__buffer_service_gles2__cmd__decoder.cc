--- src/gpu/command_buffer/service/gles2_cmd_decoder.cc.orig	2026-10-18 18:43:23 UTC
+++ src/gpu/command_buffer/service/gles2_cmd_decoder.cc
@@ -3073,7 +3073,7 @@ std::unique_ptr<GLES2Decoder> GLES2Decod
   }
 
 // Allow linux to run fuzzers.
-#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VALIDATING_COMMAND_DECODER) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<GLES2DecoderImpl>(client, command_buffer_service,
                                             outputter, group);
 #else
