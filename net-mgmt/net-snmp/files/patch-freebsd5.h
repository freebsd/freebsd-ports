--- /dev/null	Sat Aug 16 16:33:01 2003
+++ include/net-snmp/system/freebsd5.h	Sat Aug 16 16:42:08 2003
@@ -0,0 +1,19 @@
+#include "freebsd.h"
+
+/*
+ * freebsd4 is a superset of freebsd2 and freebsd3 
+ */
+#define freebsd2 1
+#define freebsd3 1
+#define freebsd4 1
+
+#undef IFADDR_SYMBOL
+#define IFADDR_SYMBOL "in_ifaddrhead"
+
+#undef PROC_SYMBOL
+#define PROC_SYMBOL "allproc"
+
+#undef NPROC_SYMBOL
+#define NPROC_SYMBOL "nprocs"
+
+#undef TOTAL_MEMORY_SYMBOL
