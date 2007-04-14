--- src/freebsd.c.orig	Sat Apr 14 20:21:32 2007
+++ src/freebsd.c	Sat Apr 14 20:21:54 2007
@@ -530,7 +530,7 @@
 	snprintf(p_client_buffer, client_buffer_size, p_format,
 		(float)((cycles[1] - cycles[0]) / microseconds) / divisor);
 #else
-	get_freq(p_client_buffer, client_buffer_size, p_format, divisor);
+	get_freq(p_client_buffer, client_buffer_size, p_format, divisor, 1);
 #endif
 }
 
