--- ui/views/widget/widget.h.orig	2025-10-21 16:57:35 UTC
+++ ui/views/widget/widget.h
@@ -494,7 +494,7 @@ class VIEWS_EXPORT Widget : public internal::NativeWid
     bool force_system_menu_for_frameless = false;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only used by X11, for root level windows. Specifies the res_name and
     // res_class fields, respectively, of the WM_CLASS window property. Controls
     // window grouping and desktop file matching in Linux window managers.
