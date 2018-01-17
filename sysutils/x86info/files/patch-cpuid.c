--- cpuid.c.orig	2017-09-06 10:17:13.000000000 -0600
+++ cpuid.c	2018-01-11 10:34:12.018249000 -0700
@@ -21,14 +21,7 @@
 {
 	unsigned int a = 0, b = 0, c = 0, d = 0;
 
-	if (eax != NULL)
-		a = *eax;
-	if (ebx != NULL)
-		b = *ebx;
-	if (ecx != NULL)
-		c = *ecx;
-	if (edx != NULL)
-		d = *edx;
+	c = idx >> 32;
 
 	bind_cpu(cpunr);
 
