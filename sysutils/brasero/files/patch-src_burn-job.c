--- src/burn-job.c.orig	2008-01-02 15:00:34.000000000 -0500
+++ src/burn-job.c	2008-01-02 15:01:15.000000000 -0500
@@ -1300,6 +1300,28 @@ brasero_job_get_device (BraseroJob *self
 }
 
 BraseroBurnResult
+brasero_job_get_cdrecord_device (BraseroJob *self, gchar **device)
+{
+	BraseroBurnSession *session;
+	NautilusBurnDrive *drive;
+	BraseroJobPrivate *priv;
+	const gchar *path;
+
+	BRASERO_JOB_DEBUG (self);
+
+	g_return_val_if_fail (device != NULL, BRASERO_BURN_ERR);
+
+	priv = BRASERO_JOB_PRIVATE (self);
+	session = brasero_task_ctx_get_session (priv->ctx);
+
+	drive = brasero_burn_session_get_burner (session);
+	path = NCB_DRIVE_GET_CRECORD_DEVICE (drive);
+	*device = g_strdup (path);
+
+	return BRASERO_BURN_OK;
+}
+
+BraseroBurnResult
 brasero_job_get_media (BraseroJob *self, BraseroMedia *media)
 {
 	BraseroBurnSession *session;
