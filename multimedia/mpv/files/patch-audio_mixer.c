--- audio/mixer.c.orig	2016-03-29 14:12:22 UTC
+++ audio/mixer.c
@@ -57,8 +57,8 @@ struct mixer *mixer_init(void *talloc_ct
     *mixer = (struct mixer) {
         .log = mp_log_new(mixer, global->log, "mixer"),
         .opts = global->opts,
-        .vol_l = 100,
-        .vol_r = 100,
+        .vol_l = -1,
+        .vol_r = -1,
         .driver = "",
     };
     return mixer;
