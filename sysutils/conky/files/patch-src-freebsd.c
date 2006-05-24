--- src/freebsd.c.orig	Sun Mar 26 01:47:50 2006
+++ src/freebsd.c	Wed May 24 07:57:35 2006
@@ -508,7 +508,7 @@
 
 	if (GETSYSCTL("dev.cpu.0.freq", freq) == 0)
 		snprintf(p_client_buffer, client_buffer_size,
-				p_format, freq/divisor);
+				p_format, (float)freq/(float)divisor);
 	else
 		snprintf(p_client_buffer, client_buffer_size, p_format, 0.0f);
 }
