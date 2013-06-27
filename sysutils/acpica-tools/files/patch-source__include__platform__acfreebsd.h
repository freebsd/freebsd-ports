--- ../../source/include/platform/acfreebsd.h.orig	2013-06-26 14:00:12.000000000 -0400
+++ ../../source/include/platform/acfreebsd.h	2013-06-26 20:30:30.000000000 -0400
@@ -49,12 +49,21 @@
 
 #include "acgcc.h"
 #include <sys/types.h>
-#include <machine/acpica_machdep.h>
+
+#ifdef __LP64__
+#define ACPI_MACHINE_WIDTH      64
+#else
+#define ACPI_MACHINE_WIDTH      32
+#endif
+
+#define COMPILER_DEPENDENT_INT64        int64_t
+#define COMPILER_DEPENDENT_UINT64       uint64_t
 
 #define ACPI_UINTPTR_T      uintptr_t
 
 #define ACPI_USE_DO_WHILE_0
 #define ACPI_USE_LOCAL_CACHE
+#define ACPI_USE_NATIVE_DIVIDE
 #define ACPI_USE_SYSTEM_CLIBRARY
 
 #ifdef _KERNEL
@@ -63,6 +72,7 @@
 #include <sys/param.h>
 #include <sys/systm.h>
 #include <sys/libkern.h>
+#include <machine/acpica_machdep.h>
 #include <machine/stdarg.h>
 
 #include "opt_acpi.h"
