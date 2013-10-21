--- ../../source/os_specific/service_layers/osunixxf.c
+++ ../../source/os_specific/service_layers/osunixxf.c
@@ -91,7 +91,7 @@
 /* Terminal support for AcpiExec only */
 
 #ifdef ACPI_EXEC_APP
-#include <termio.h>
+#include <termios.h>
 
 struct termios              OriginalTermAttributes;
 
