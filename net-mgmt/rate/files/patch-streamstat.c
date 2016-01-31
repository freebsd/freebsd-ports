--- streamstat.c.orig	2016-01-15 08:36:19 UTC
+++ streamstat.c
@@ -282,6 +282,7 @@ char * customize_format(int cols, int ou
 {
 	static char fmtstring[256];
 	int n = (cols - outlen - 1) / 2;
+	if (n < 15) n = 15;	/* minimum required chars for IPv4 */
 	snprintf(fmtstring, 256, fmt, n, n, n, n);
 	return(fmtstring);
 }
