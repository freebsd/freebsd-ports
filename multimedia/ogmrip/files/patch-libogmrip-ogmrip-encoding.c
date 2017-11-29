--- libogmrip/ogmrip-encoding.c.orig	2015-01-10 13:39:43 UTC
+++ libogmrip/ogmrip-encoding.c
@@ -1197,7 +1197,7 @@ ogmrip_encoding_spawn_suspended (OGMRipE
       encoding->priv->task.options,
       OGMRIP_TASK_SUSPEND,
       encoding->priv->task.type,
-      (OGMRipTaskDetail) 0);
+      (OGMRipTaskDetail) 0.0);
 }
 
 static void
@@ -1208,7 +1208,7 @@ ogmrip_encoding_spawn_resumed (OGMRipEnc
       encoding->priv->task.options,
       OGMRIP_TASK_RESUME,
       encoding->priv->task.type,
-      (OGMRipTaskDetail) 0);
+      (OGMRipTaskDetail) 0.0);
 }
 
 static void
@@ -1706,10 +1706,10 @@ ogmrip_encoding_analyze_video_stream (OG
     return OGMJOB_RESULT_ERROR;
 
   ogmrip_encoding_emit_task (encoding, spawn,
-      NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_ANALYZE, (OGMRipTaskDetail) 0);
+      NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_ANALYZE, (OGMRipTaskDetail) 0.0);
   result = ogmrip_video_codec_analyze (OGMRIP_VIDEO_CODEC (spawn), 0) ? OGMJOB_RESULT_SUCCESS : OGMJOB_RESULT_CANCEL;
   ogmrip_encoding_emit_task (encoding, spawn,
-      NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_ANALYZE, (OGMRipTaskDetail) result);
+      NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_ANALYZE, (OGMRipTaskDetail) (gdouble) result);
 
   if (result == OGMJOB_RESULT_SUCCESS)
   {
@@ -1777,9 +1777,9 @@ ogmrip_encoding_extract_chapters (OGMRip
   if (!spawn)
     return OGMJOB_RESULT_ERROR;
 
-  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_CHAPTERS, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_CHAPTERS, (OGMRipTaskDetail) 0.0);
   result = ogmjob_spawn_run (spawn, error);
-  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_CHAPTERS, (OGMRipTaskDetail) result);
+  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_CHAPTERS, (OGMRipTaskDetail) (gdouble) result);
 
   if (result != OGMJOB_RESULT_SUCCESS)
   {
@@ -1871,10 +1871,10 @@ ogmrip_encoding_encode_subp_streams (OGM
         ogmrip_codec_set_options (OGMRIP_CODEC (spawn), encoding->priv->profile_section);
 
       ogmrip_encoding_emit_task (encoding, spawn, (OGMRipOptions *) &data->options,
-          OGMRIP_TASK_RUN, OGMRIP_TASK_SUBP, (OGMRipTaskDetail) 0);
+          OGMRIP_TASK_RUN, OGMRIP_TASK_SUBP, (OGMRipTaskDetail) 0.0);
       result = ogmjob_spawn_run (spawn, error);
       ogmrip_encoding_emit_task (encoding, spawn, (OGMRipOptions *) &data->options,
-          OGMRIP_TASK_COMPLETE, OGMRIP_TASK_SUBP, (OGMRipTaskDetail) result);
+          OGMRIP_TASK_COMPLETE, OGMRIP_TASK_SUBP, (OGMRipTaskDetail) (gdouble) result);
 
       if (result != OGMJOB_RESULT_SUCCESS)
       {
@@ -1987,10 +1987,10 @@ ogmrip_encoding_encode_audio_streams (OG
       ogmrip_codec_set_options (OGMRIP_CODEC (spawn), encoding->priv->profile_section);
 
     ogmrip_encoding_emit_task (encoding, spawn, (OGMRipOptions *) &data->options,
-        OGMRIP_TASK_RUN, OGMRIP_TASK_AUDIO, (OGMRipTaskDetail) 0);
+        OGMRIP_TASK_RUN, OGMRIP_TASK_AUDIO, (OGMRipTaskDetail) 0.0);
     result = ogmjob_spawn_run (spawn, error);
     ogmrip_encoding_emit_task (encoding, spawn, (OGMRipOptions *) &data->options,
-        OGMRIP_TASK_COMPLETE, OGMRIP_TASK_AUDIO, (OGMRipTaskDetail) result);
+        OGMRIP_TASK_COMPLETE, OGMRIP_TASK_AUDIO, (OGMRipTaskDetail) (gdouble) result);
 
     if (result != OGMJOB_RESULT_SUCCESS)
     {
@@ -2058,10 +2058,10 @@ ogmrip_encoding_crop (OGMRipEncoding *en
   {
     case OGMRIP_OPTIONS_AUTOMATIC:
       ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec),
-          NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_CROP, (OGMRipTaskDetail) 0);
+          NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_CROP, (OGMRipTaskDetail) 0.0);
       result = ogmrip_video_codec_autocrop (codec, 0) ? OGMJOB_RESULT_SUCCESS : OGMJOB_RESULT_CANCEL;
       ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec),
-          NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_CROP, (OGMRipTaskDetail) result);
+          NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_CROP, (OGMRipTaskDetail) (gdouble) result);
 
       if (result != OGMJOB_RESULT_SUCCESS)
         return OGMJOB_RESULT_CANCEL;
@@ -2226,9 +2226,9 @@ ogmrip_encoding_encode_video_stream (OGM
   if (encoding->priv->profile_section && encoding->priv->preset == OGMRIP_VIDEO_PRESET_USER)
       ogmrip_codec_set_options (OGMRIP_CODEC (codec), encoding->priv->profile_section);
 
-  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec), NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_VIDEO, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec), NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_VIDEO, (OGMRipTaskDetail) 0.0);
   result = ogmjob_spawn_run (OGMJOB_SPAWN (codec), error);
-  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec), NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_VIDEO, (OGMRipTaskDetail) result);
+  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (codec), NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_VIDEO, (OGMRipTaskDetail) (gdouble) result);
 
   if (result == OGMJOB_RESULT_ERROR && error && !(*error))
     g_set_error (error, OGMRIP_ENCODING_ERROR, OGMRIP_ENCODING_ERROR_UNKNOWN,
@@ -2258,9 +2258,9 @@ ogmrip_encoding_merge (OGMRipEncoding *e
   ogmjob_log_printf ("\nMerging\n");
   ogmjob_log_printf ("-------\n\n");
 
-  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (container), NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_MERGE, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (container), NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_MERGE, (OGMRipTaskDetail) 0.0);
   result = ogmjob_spawn_run (OGMJOB_SPAWN (container), error);
-  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (container), NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_MERGE, (OGMRipTaskDetail) result);
+  ogmrip_encoding_emit_task (encoding, OGMJOB_SPAWN (container), NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_MERGE, (OGMRipTaskDetail) (gdouble) result);
 
   if (cwd)
   {
@@ -2376,7 +2376,7 @@ ogmrip_encoding_test_internal (OGMRipEnc
   relative = ogmrip_encoding_get_relative (encoding);
   ogmrip_encoding_set_relative_internal (encoding, TRUE);
 
-  ogmrip_encoding_emit_task (encoding, NULL, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_TEST, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, NULL, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_TEST, (OGMRipTaskDetail) 0.0);
 
   ogmrip_encoding_set_play_length (encoding, SAMPLE_LENGTH * SAMPLE_PERCENT);
 
@@ -2430,7 +2430,7 @@ ogmrip_encoding_test_internal (OGMRipEnc
     }
   }
 
-  ogmrip_encoding_emit_task (encoding, NULL, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_TEST, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, NULL, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_TEST, (OGMRipTaskDetail) 0.0);
 
   if (result == OGMJOB_RESULT_SUCCESS && files > 0)
   {
@@ -5972,9 +5972,9 @@ ogmrip_encoding_backup (OGMRipEncoding *
 
   OGMRIP_ENCODING_SET_FLAGS (encoding, OGMRIP_ENCODING_BACKUPING);
 
-  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_BACKUP, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_RUN, OGMRIP_TASK_BACKUP, (OGMRipTaskDetail) 0.0);
   result = ogmjob_spawn_run (spawn, error);
-  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_BACKUP, (OGMRipTaskDetail) 0);
+  ogmrip_encoding_emit_task (encoding, spawn, NULL, OGMRIP_TASK_COMPLETE, OGMRIP_TASK_BACKUP, (OGMRipTaskDetail) 0.0);
 
   OGMRIP_ENCODING_UNSET_FLAGS (encoding, OGMRIP_ENCODING_BACKUPING);
 
