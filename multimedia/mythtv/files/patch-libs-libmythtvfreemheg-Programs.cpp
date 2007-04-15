--- libs/libmythfreemheg/Programs.cpp~	Fri Mar 16 18:11:34 2007
+++ libs/libmythfreemheg/Programs.cpp	Sat Apr  7 11:41:11 2007
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
 
