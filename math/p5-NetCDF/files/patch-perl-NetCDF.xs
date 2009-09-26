--- perl/NetCDF.xs.orig	2003-01-10 00:09:14.000000000 +0800
+++ perl/NetCDF.xs	2009-09-26 06:10:36.000000000 +0800
@@ -23,6 +23,10 @@
 #include <assert.h>
 #include "netcdf.h"
 
+#if !defined(MAX_NC_OPEN)
+#define MAX_NC_OPEN sysconf(_SC_OPEN_MAX)
+#endif
+
 /*
  * Macro for setting a scalar value either directly or through a reference:
  */
