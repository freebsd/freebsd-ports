--- src/freebsd.c.orig	Sun Dec  3 21:22:52 2006
+++ src/freebsd.c	Sun Dec  3 21:23:33 2006
@@ -514,7 +514,7 @@
 	if (freq_sysctl == NULL)
 		exit(-1);
 
-	snprintf(freq_sysctl, 16, "dev.cpu.%d.freq", cpu);
+	snprintf(freq_sysctl, 16, "dev.cpu.%d.freq", (cpu - 1));
 	
 	if (!p_client_buffer || client_buffer_size <= 0 ||
 			!p_format || divisor <= 0)
