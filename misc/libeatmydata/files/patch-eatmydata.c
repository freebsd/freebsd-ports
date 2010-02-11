--- eatmydata.c.orig	2009-05-12 03:11:01.000000000 +0200
+++ eatmydata.c	2010-01-16 20:33:45.000000000 +0100
@@ -53,10 +53,15 @@
 	mode_t mode;
 
 	va_start(ap, flags);
-	mode= va_arg(ap, mode_t);
+	mode= va_arg(ap, int);
 	va_end(ap);
 
+#if defined(O_DSYNC)
 	flags &= ~(O_SYNC|O_DSYNC);
+#else
+	flags &= ~(O_SYNC);
+#endif
+
 
 	if(!libc_open)
 		eatmydata_init();
