--- chrome/browser/ui/webui/side_panel/read_anything/read_anything_untrusted_page_handler.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/ui/webui/side_panel/read_anything/read_anything_untrusted_page_handler.cc
@@ -192,7 +192,7 @@ constexpr int PDF_LOAD_DELAY_MS = 1000;
 // Prefix definition for logging.
 constexpr char kReadAnythingPrefix[] = "Read Anything";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // chrome://whats-new renders its content in a single https://www.google.com
 // child frame (see the frame-src CSP in WhatsNewUI). Reading mode distills that
 // frame directly.
@@ -331,7 +331,7 @@ bool IsSameOriginSubframe(content::RenderFrameHost* rf
 // chrome://whats-new only exists on Windows, Mac and Linux.
 bool IsWhatsNewEmbeddedContentFrame(content::RenderFrameHost* rfh,
                                     content::RenderFrameHost* main_frame) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return rfh->GetParent() == main_frame &&
          main_frame->GetLastCommittedOrigin().IsSameOriginWith(
              GURL(chrome::kChromeUIWhatsNewURL)) &&
