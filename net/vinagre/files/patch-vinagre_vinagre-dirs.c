--- vinagre/vinagre-dirs.c.orig	2015-05-28 09:18:05.360678000 +0200
+++ vinagre/vinagre-dirs.c	2015-05-28 09:19:16.854504000 +0200
@@ -204,6 +204,7 @@
 " directories.", _tmp18_);
 	data_dirs = (_vala_array_free (data_dirs, data_dirs_length1, (GDestroyNotify) g_free), NULL);
 	system_data_dirs = (_vala_array_free (system_data_dirs, system_data_dirs_length1, (GDestroyNotify) g_free), NULL);
+	return result;
 }
 
 
