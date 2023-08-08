--- src/libm/tryvsx3.c.orig	2023-05-12 23:04:06 UTC
+++ src/libm/tryvsx3.c
@@ -1,8 +1,8 @@
 #include <altivec.h>
 
 __vector double sleef_cpuidtmp0;
-__vector unsigned long long sleef_cpuidtmp1, sleef_cpuidtmp2;
+__vector unsigned long long sleef_cpuidtmp1, sleef_cpuidtmp3;
 
 void sleef_tryVSX3() {
-  sleef_cpuidtmp0 = vec_insert_exp(sleef_cpuidtmp1, sleef_cpuidtmp2);
+  sleef_cpuidtmp0 = vec_insert_exp(sleef_cpuidtmp1, sleef_cpuidtmp3);
 }
