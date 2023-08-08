--- prnt/cupsext/cupsext.c.orig	2023-06-02 08:02:35 UTC
+++ prnt/cupsext/cupsext.c
@@ -89,6 +89,13 @@ Sanjay Kumar
 #include "hp_ipp.h"
 #include "utils.h"
 
+void _releaseCupsInstance(void);
+int addCupsPrinter(char *name, char *device_uri, char *location,
+                   char *ppd_file, char *model, char *info);
+int delCupsPrinter(char *pr_name);
+int setDefaultCupsPrinter(char *pr_name);
+int controlCupsPrinter(char *pr_name, int op);
+
 /* Ref: PEP 353 (Python 2.5) */
 #if PY_VERSION_HEX < 0x02050000
 typedef int Py_ssize_t;
