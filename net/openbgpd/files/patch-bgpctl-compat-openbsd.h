--- /dev/null	2009-06-24 01:22:00.000000000 +0900
+++ bgpctl/compat-openbsd.h	2009-06-24 01:24:55.000000000 +0900
@@ -0,0 +1,3 @@
+#include <sys/endian.h>
+
+#define betoh64(x)	(be64toh(x))
