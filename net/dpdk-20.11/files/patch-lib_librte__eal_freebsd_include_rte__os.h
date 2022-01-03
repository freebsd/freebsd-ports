--- lib/librte_eal/freebsd/include/rte_os.h.orig	2021-03-08 17:40:08 UTC
+++ lib/librte_eal/freebsd/include/rte_os.h
@@ -14,6 +14,28 @@
 #include <pthread_np.h>
 
 typedef cpuset_t rte_cpuset_t;
+
+/* FreeBSD 14 uses GLIBC compatible CPU_AND, CPU_OR, ... */
+#ifdef CPU_ALLOC
+
+#define RTE_CPU_AND(dst, src1, src2) CPU_AND(dst, src1, src2)
+#define RTE_CPU_OR(dst, src1, src2) CPU_OR(dst, src1, src2)
+#define RTE_CPU_FILL(set) do \
+{ \
+	unsigned int i; \
+	CPU_ZERO(set); \
+	for (i = 0; i < CPU_SETSIZE; i++) \
+		CPU_SET(i, set); \
+} while (0)
+#define RTE_CPU_NOT(dst, src) do \
+{ \
+	cpu_set_t tmp; \
+	RTE_CPU_FILL(&tmp); \
+	CPU_XOR(dst, &tmp, src); \
+} while (0)
+
+#else
+
 #define RTE_CPU_AND(dst, src1, src2) do \
 { \
 	cpuset_t tmp; \
@@ -47,6 +69,8 @@ typedef cpuset_t rte_cpuset_t;
 	CPU_ANDNOT(&tmp, src); \
 	CPU_COPY(&tmp, dst); \
 } while (0)
-#endif
+#endif /* CPU_NAND */
+
+#endif /* CPU_ALLOC */
 
 #endif /* _RTE_OS_H_ */
