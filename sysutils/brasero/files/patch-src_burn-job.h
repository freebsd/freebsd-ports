--- src/burn-job.h.orig	2008-01-02 14:59:55.000000000 -0500
+++ src/burn-job.h	2008-01-02 15:00:13.000000000 -0500
@@ -148,6 +148,9 @@ BraseroBurnResult
 brasero_job_get_device (BraseroJob *job, gchar **device);
 
 BraseroBurnResult
+brasero_job_get_cdrecord_device (BraseroJob *job, gchar **device);
+
+BraseroBurnResult
 brasero_job_get_media (BraseroJob *job, BraseroMedia *media);
 
 BraseroBurnResult
