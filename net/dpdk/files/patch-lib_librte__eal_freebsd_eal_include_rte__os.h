--- lib/librte_eal/freebsd/eal/include/rte_os.h.orig	2020-01-03 12:22:03 UTC
+++ lib/librte_eal/freebsd/eal/include/rte_os.h
@@ -29,6 +29,9 @@ typedef cpuset_t rte_cpuset_t;
 	CPU_COPY(&tmp, dst); \
 } while (0)
 #define RTE_CPU_FILL(set) CPU_FILL(set)
+
+/* In FreeBSD 13 CPU_NAND macro is CPU_ANDNOT */
+#ifdef CPU_NAND
 #define RTE_CPU_NOT(dst, src) do \
 { \
 	cpuset_t tmp; \
@@ -36,5 +39,14 @@ typedef cpuset_t rte_cpuset_t;
 	CPU_NAND(&tmp, src); \
 	CPU_COPY(&tmp, dst); \
 } while (0)
+#else
+#define RTE_CPU_NOT(dst, src) do \
+{ \
+	cpuset_t tmp; \
+	CPU_FILL(&tmp); \
+	CPU_ANDNOT(&tmp, src); \
+	CPU_COPY(&tmp, dst); \
+} while (0)
+#endif
 
 #endif /* _RTE_OS_H_ */
