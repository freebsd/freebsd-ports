--- ./src/collectd.c.orig	2013-11-23 22:04:05.130103822 +0000
+++ ./src/collectd.c	2013-11-23 22:04:25.627104708 +0000
@@ -294,7 +294,7 @@
 #endif
 
 #if HAVE_LIBSTATGRAB
-	if (sg_init ())
+	if (sg_init (0))
 	{
 		ERROR ("sg_init: %s", sg_str_error (sg_get_error ()));
 		return (-1);
