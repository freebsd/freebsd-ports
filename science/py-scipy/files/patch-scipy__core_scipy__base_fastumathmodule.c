
$FreeBSD$

--- scipy_core/scipy_base/fastumathmodule.c.orig
+++ scipy_core/scipy_base/fastumathmodule.c
@@ -1,8 +1,8 @@
+#include <math.h>
 #include "Python.h"
 #include "Numeric/arrayobject.h"
 #include "Numeric/ufuncobject.h"
 #include "abstract.h"
-#include <math.h>
 #include "mconf_lite.h"
 
 /* Fast umath module whose functions do not check for range and domain
