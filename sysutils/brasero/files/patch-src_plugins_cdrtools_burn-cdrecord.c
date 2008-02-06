--- src/plugins/cdrtools/burn-cdrecord.c.orig	2008-01-02 14:59:18.000000000 -0500
+++ src/plugins/cdrtools/burn-cdrecord.c	2008-01-02 14:59:27.000000000 -0500
@@ -899,7 +899,7 @@ brasero_cdrecord_set_argv (BraseroProces
 	g_ptr_array_add (argv, g_strdup ("cdrecord"));
 	g_ptr_array_add (argv, g_strdup ("-v"));
 
-	brasero_job_get_device (BRASERO_JOB (cdrecord), &device);
+	brasero_job_get_cdrecord_device (BRASERO_JOB (cdrecord), &device);
 	dev_str = g_strdup_printf ("dev=%s", device);
 	g_ptr_array_add (argv, dev_str);
 	g_free (device);
