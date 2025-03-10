--- third_party/blink/renderer/core/loader/mixed_content_checker.cc.orig	2025-03-05 08:14:56 UTC
+++ third_party/blink/renderer/core/loader/mixed_content_checker.cc
@@ -484,7 +484,7 @@ bool MixedContentChecker::ShouldBlockFetch(
   switch (context_type) {
     case mojom::blink::MixedContentContextType::kOptionallyBlockable:
 
-#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)) && \
+#if (BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENABLE_CAST_RECEIVER)
       // Fuchsia WebEngine can be configured to allow loading Mixed Content from
       // an insecure IP address. This is a workaround to revert Fuchsia Cast
