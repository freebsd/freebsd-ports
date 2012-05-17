--- src/include/private/switch_core_pvt.h	2010-06-22 17:19:31.000000000 -0400
+++ src/include/private/switch_core_pvt.h	2010-06-29 11:12:54.000000000 -0400
@@ -209,6 +209,7 @@
 	int32_t sps;
 	int32_t sps_last;
 	switch_log_level_t hard_log_level;
+	char *storage_dir;
 	char *mailer_app;
 	char *mailer_app_args;
 	uint32_t max_dtmf_duration;
