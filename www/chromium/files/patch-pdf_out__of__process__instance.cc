--- pdf/out_of_process_instance.cc.orig	2021-12-31 00:57:37 UTC
+++ pdf/out_of_process_instance.cc
@@ -75,7 +75,7 @@
 #include "ui/gfx/geometry/size.h"
 #include "url/gurl.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "pdf/ppapi_migration/pdfium_font_linux.h"
 #endif
 
@@ -749,7 +749,7 @@ void OutOfProcessInstance::RotateCounterclockwise() {
 }
 
 void OutOfProcessInstance::SetLastPluginInstance() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   SetLastPepperInstance(this);
 #endif
 }
