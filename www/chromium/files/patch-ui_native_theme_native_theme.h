--- ui/native_theme/native_theme.h.orig	2017-09-07 02:03:42.878086000 +0200
+++ ui/native_theme/native_theme.h	2017-09-07 02:04:02.716811000 +0200
@@ -47,7 +47,7 @@
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
