--- crypto/ppccap.c.orig	2022-04-12 16:31:27 UTC
+++ crypto/ppccap.c
@@ -117,14 +117,18 @@ static unsigned long getauxval(unsigned long key)
 #endif
 
 /* I wish <sys/auxv.h> was universally available */
-#define HWCAP                   16      /* AT_HWCAP */
+#ifndef AT_HWCAP
+# define AT_HWCAP               16      /* AT_HWCAP */
+#endif
 #define HWCAP_PPC64             (1U << 30)
 #define HWCAP_ALTIVEC           (1U << 28)
 #define HWCAP_FPU               (1U << 27)
 #define HWCAP_POWER6_EXT        (1U << 9)
 #define HWCAP_VSX               (1U << 7)
 
-#define HWCAP2                  26      /* AT_HWCAP2 */
+#ifndef AT_HWCAP2
+# define AT_HWCAP2               26      /* AT_HWCAP2 */
+#endif
 #define HWCAP_VEC_CRYPTO        (1U << 25)
 #define HWCAP_ARCH_3_00         (1U << 23)
 
@@ -215,8 +219,8 @@ void OPENSSL_cpuid_setup(void)
 
 #ifdef OSSL_IMPLEMENT_GETAUXVAL
     {
-        unsigned long hwcap = getauxval(HWCAP);
-        unsigned long hwcap2 = getauxval(HWCAP2);
+        unsigned long hwcap = getauxval(AT_HWCAP);
+        unsigned long hwcap2 = getauxval(AT_HWCAP2);
 
         if (hwcap & HWCAP_FPU) {
             OPENSSL_ppccap_P |= PPC_FPU;
