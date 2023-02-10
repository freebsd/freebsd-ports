--- src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura.cc
@@ -159,7 +159,7 @@ class WebDragSourceAura : public content::WebContentsO
   raw_ptr<aura::Window> window_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Fill out the OSExchangeData with a file contents, synthesizing a name if
 // necessary.
 void PrepareDragForFileContents(const DropData& drop_data,
@@ -242,7 +242,7 @@ void PrepareDragData(const DropData& drop_data,
   if (!drop_data.download_metadata.empty())
     PrepareDragForDownload(drop_data, provider, web_contents);
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // We set the file contents before the URL because the URL also sets file
   // contents (to a .URL shortcut).  We want to prefer file content data over
   // a shortcut so we add it first.
@@ -1333,7 +1333,7 @@ void WebContentsViewAura::OnMouseEvent(ui::MouseEvent*
     // Linux window managers like to handle raise-on-click themselves.  If we
     // raise-on-click manually, this may override user settings that prevent
     // focus-stealing.
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
     // It is possible for the web-contents to be destroyed while it is being
     // activated. Use a weak-ptr to track whether that happened or not.
     // More in https://crbug.com/1040725
