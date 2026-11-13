--- ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc.orig	2026-11-11 14:44:17 UTC
+++ ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc
@@ -48,7 +48,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_window.h"
 #include "ui/ozone/platform/wayland/host/wayland_window_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
@@ -70,7 +70,7 @@ using mojom::DragOperation;
 constexpr char kMimeTypeEmptyDragData[] = "chromium/x-empty-drag-data";
 
 bool IsPortalMimeType(const std::string& mime_type) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return mime_type == kMimeTypePortalFileTransfer ||
          mime_type == kMimeTypePortalFiles;
 #else
@@ -203,7 +203,7 @@ void WaylandDataDragController::StartSessionInternal(
   }
 
   auto mime_types = GetOfferedExchangeDataProvider()->BuildMimeTypesList();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (GetOfferedExchangeDataProvider()->HasFile()) {
     mime_types.push_back(kMimeTypePortalFileTransfer);
     mime_types.push_back(kMimeTypePortalFiles);
@@ -621,7 +621,7 @@ void WaylandDataDragController::OnDataSourceSend(
   CHECK_EQ(data_source_.get(), source);
   VLOG(1) << __FUNCTION__ << " mime=" << mime_type;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mime_type == kMimeTypePortalFileTransfer ||
       mime_type == kMimeTypePortalFiles) {
     std::optional<std::vector<FileInfo>> filenames =
@@ -743,7 +743,7 @@ void WaylandDataDragController::OnDataFetched(
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check for portal data. We read the raw portal key from the FD on the
   // background thread, and now we resolve it to actual paths on the UI thread.
   for (const char* mime : {kMimeTypePortalFileTransfer, kMimeTypePortalFiles}) {
