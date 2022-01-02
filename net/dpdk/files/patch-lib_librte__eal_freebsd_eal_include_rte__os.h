--- lib/librte_eal/freebsd/eal/include/rte_os.h.orig	2021-03-17 16:43:15 UTC
+++ lib/librte_eal/freebsd/eal/include/rte_os.h
@@ -14,8 +14,30 @@
 #include <pthread_np.h>
 
 typedef cpuset_t rte_cpuset_t;
-#define RTE_CPU_AND(dst, src1, src2) do \
+
+/* FreeBSD 14 uses GLIBC compatible CPU_AND, CPU_OR, ... */
+#ifdef CPU_ALLOC
+
+#define RTE_CPU_AND(dst, src1, src2) CPU_AND(dst, src1, src2)
+#define RTE_CPU_OR(dst, src1, src2) CPU_OR(dst, src1, src2)
+#define RTE_CPU_FILL(set) do \
 { \
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
+#define RTE_CPU_AND(dst, src1, src2) do		\
+{ \
 	cpuset_t tmp; \
 	CPU_COPY(src1, &tmp); \
 	CPU_AND(&tmp, src2); \
@@ -29,6 +51,9 @@ typedef cpuset_t rte_cpuset_t;
 	CPU_COPY(&tmp, dst); \
 } while (0)
 #define RTE_CPU_FILL(set) CPU_FILL(set)
+
+/* In FreeBSD 13 CPU_NAND macro is CPU_ANDNOT */
+#ifdef CPU_NAND
 #define RTE_CPU_NOT(dst, src) do \
 { \
 	cpuset_t tmp; \
@@ -36,5 +61,16 @@ typedef cpuset_t rte_cpuset_t;
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
+#endif /* CPU_NAND */
+
+#endif /* CPU_ALLOC */
 
 #endif /* _RTE_OS_H_ */
