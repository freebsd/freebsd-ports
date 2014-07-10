--- scepd/scepconf.c.orig	2001-03-03 23:23:22.000000000 +0100
+++ scepd/scepconf.c	2014-07-10 22:26:24.326212726 +0200
@@ -20,7 +20,11 @@
 int	debug = 0;
 
 int	main(int argc, char *argv[]) {
+#ifdef LHASH_OF
+	LHASH_OF(CONF_VALUE) *conf;
+#else	
 	LHASH	*conf;
+#endif
 	long	eline;
 	char	*section = NULL, *variable = NULL, *value;
 	int	c, n;
