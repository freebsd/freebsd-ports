--- libbrasero-burn/burn-process.c.orig	2010-03-07 15:07:48.000000000 -0500
+++ libbrasero-burn/burn-process.c	2010-03-07 15:08:41.000000000 -0500
@@ -609,6 +609,7 @@ brasero_process_start (BraseroJob *job, 
 	gchar *envp [] = {	"LANG=C",
 				"LANGUAGE=C",
 				"LC_ALL=C",
+				"PATH=/bin:/sbin:/usr/bin:/usr/sbin:%%LOCALBASE%%/bin:%%LOCALBASE%%/sbin",
 				NULL};
 
 	if (priv->pid)
