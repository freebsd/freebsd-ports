--- source4/torture/ndr/ndr.h.orig	2022-01-24 10:27:00 UTC
+++ source4/torture/ndr/ndr.h
@@ -20,6 +20,8 @@
 #ifndef __TORTURE_NDR_H__
 #define __TORTURE_NDR_H__
 
+#include <sys/types.h>
+
 #include "torture/torture.h"
 #include "librpc/ndr/libndr.h"
 #include "libcli/security/security.h"
