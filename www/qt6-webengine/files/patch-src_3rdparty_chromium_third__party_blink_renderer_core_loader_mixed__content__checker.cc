--- src/3rdparty/chromium/third_party/blink/renderer/core/loader/mixed_content_checker.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/loader/mixed_content_checker.cc
@@ -508,7 +508,7 @@ bool MixedContentChecker::ShouldBlockFetch(
   switch (context_type) {
     case mojom::blink::MixedContentContextType::kOptionallyBlockable:
 
-#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)) && \
+#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_CAST_RECEIVER)
       // Fuchsia WebEngine can be configured to allow loading Mixed Content from
       // an insecure IP address. This is a workaround to revert Fuchsia Cast
