--- ui/base/x/x11_drag_context.h.orig	2026-05-09 18:09:27 UTC
+++ ui/base/x/x11_drag_context.h
@@ -17,7 +17,7 @@
 #include "ui/gfx/x/event.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/weak_ptr.h"
 #endif
 
@@ -71,7 +71,7 @@ class COMPONENT_EXPORT(UI_BASE_X) XDragContext {
   // position handling if all targets have been fetched.
   void RequestNextTargetOrComplete();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalPathsExtracted(std::vector<std::string> paths);
 #endif
 
@@ -114,7 +114,7 @@ class COMPONENT_EXPORT(UI_BASE_X) XDragContext {
   // Possible actions.
   std::vector<x11::Atom> actions_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::WeakPtrFactory<XDragContext> weak_factory_{this};
 #endif
 };
