--- cpuid_x86.c.orig	2017-07-24 04:03:35 UTC
+++ cpuid_x86.c
@@ -1329,6 +1329,7 @@ int get_cpuname(void){
       case 8:
 	switch (model) {
 	case 1:
+	case 8:
 	  // AMD Ryzen
 	  if(support_avx())
 #ifndef NO_AVX2
@@ -1865,6 +1866,7 @@ int get_coretype(void){
       } else if (exfamily == 8) {
 	switch (model) {
 	case 1:
+	case 8:
 	  // AMD Ryzen
 	  if(support_avx())
 #ifndef NO_AVX2
