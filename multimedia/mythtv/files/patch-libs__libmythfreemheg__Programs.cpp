--- ./libs/libmythfreemheg/Programs.cpp.orig	2007-03-29 15:44:23.000000000 -0400
+++ ./libs/libmythfreemheg/Programs.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -30,7 +30,15 @@
 #include "freemheg.h"
 
 #include <sys/timeb.h>
+#ifdef __FreeBSD__
+/* 
+ * This file refers to the non-POSIX structure timezone, which is
+ * defined in sys/time.h.
+ */
+#include <sys/time.h>
+#else
 #include <time.h>
+#endif
 
 #include "../../config.h"
 
