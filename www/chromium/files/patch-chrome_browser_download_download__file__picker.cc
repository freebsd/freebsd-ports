--- chrome/browser/download/download_file_picker.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/download/download_file_picker.cc
@@ -20,12 +20,12 @@
 #include "ui/display/types/display_constants.h"
 #include "ui/shell_dialogs/selected_file_info.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_window/public/browser_window_interface_iterator.h"
 #include "ui/base/base_window.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window.h"
 #endif
 
@@ -95,7 +95,7 @@ DownloadFilePicker::DownloadFilePicker(download::Downl
       web_contents ? platform_util::GetTopLevel(web_contents->GetNativeView())
                    : gfx::NativeWindow();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On Aura (Linux/Win), an offscreen extension WebContents has a non-null
   // aura::Window* with a null WindowTreeHost, which prevents the file dialog
   // from being modal (https://crbug.com/40825014). Clear it so we fall back to
@@ -104,7 +104,7 @@ DownloadFilePicker::DownloadFilePicker(download::Downl
     owning_window = gfx::NativeWindow();
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // If the download was initiated without a WebContents (e.g., from an
   // extension background service worker) or with a hostless Aura window, fall
   // back to the last active browser window.
