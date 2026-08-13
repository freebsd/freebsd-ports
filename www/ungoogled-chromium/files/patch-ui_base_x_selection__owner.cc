--- ui/base/x/selection_owner.cc.orig	2026-08-13 07:41:05 UTC
+++ ui/base/x/selection_owner.cc
@@ -19,7 +19,7 @@
 #include "ui/gfx/x/window_event_manager.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_view_util.h"
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
@@ -118,7 +118,7 @@ void SelectionOwner::RetrieveTargets(std::vector<x11::
 
   add_if_present(GetURIListAtomsFrom());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Lazily advertise portal atoms if we have a URI list.
   if (format_map_.contains(x11::GetAtom(kMimeTypeUriList))) {
     for (const char* mime :
@@ -162,7 +162,7 @@ void SelectionOwner::OnSelectionRequest(
   x11::Atom requested_target = request.target;
   x11::Atom requested_property = request.property;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Handle portal requests asynchronously.
   // NOTE: MULTIPLE requests are intentionally unsupported for portal paths
   // because we handle them by early-returning here before the MULTIPLE logic.
@@ -225,7 +225,7 @@ void SelectionOwner::OnSelectionRequest(
   connection_->SendEvent(reply, requestor, x11::EventMask::NoEvent);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SelectionOwner::OnPortalPathsRegistered(x11::SelectionRequestEvent request,
                                              std::string key) {
   x11::SelectionNotifyEvent reply{
