--- ui/views/widget/widget.h.orig	2024-03-22 08:19:40 UTC
+++ ui/views/widget/widget.h
@@ -420,7 +420,7 @@ class VIEWS_EXPORT Widget : public internal::NativeWid
     // If set, the widget was created in headless mode.
     bool headless_mode = false;
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
     // Indicates whether the desktop native widget is required for the widget.
     // This may enforce changing the type of the underlying platform window.
     // See crbug.com/1280332
