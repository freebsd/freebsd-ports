--- pdf/out_of_process_instance.cc.orig	2021-09-24 18:53:06 UTC
+++ pdf/out_of_process_instance.cc
@@ -72,7 +72,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "pdf/ppapi_migration/pdfium_font_linux.h"
 #endif
 
@@ -846,7 +846,7 @@ void OutOfProcessInstance::RotateCounterclockwise() {
 }
 
 void OutOfProcessInstance::SetLastPluginInstance() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetLastPepperInstance(this);
 #endif
 }
