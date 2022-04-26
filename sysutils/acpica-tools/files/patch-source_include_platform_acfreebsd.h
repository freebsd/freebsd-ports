--- source/include/platform/acfreebsd.h.orig	2022-03-31 16:38:39 UTC
+++ source/include/platform/acfreebsd.h
@@ -211,6 +211,7 @@
 
 #if __STDC_HOSTED__
 #include <ctype.h>
+#include <unistd.h>
 #endif
 
 #define ACPI_CAST_PTHREAD_T(pthread)    ((ACPI_THREAD_ID) ACPI_TO_INTEGER (pthread))
