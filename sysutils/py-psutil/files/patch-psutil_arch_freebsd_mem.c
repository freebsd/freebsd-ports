--- psutil/arch/freebsd/mem.c.orig	2022-01-17 12:10:50 UTC
+++ psutil/arch/freebsd/mem.c
@@ -6,6 +6,7 @@
 
 
 #include <Python.h>
+#include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
 #include <vm/vm_param.h>
