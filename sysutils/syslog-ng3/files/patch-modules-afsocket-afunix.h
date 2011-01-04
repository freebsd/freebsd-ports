diff --git a/modules/afsocket/afunix.h b/modules/afsocket/afunix.h
index ddb63bc..fba3e02 100644
--- modules/afsocket/afunix.h
+++ modules/afsocket/afunix.h
@@ -40,7 +40,7 @@ typedef struct _AFUnixSourceDriver
 
 void afunix_sd_set_uid(LogDriver *self, gchar *owner);
 void afunix_sd_set_gid(LogDriver *self, gchar *group);
-void afunix_sd_set_perm(LogDriver *self, mode_t perm);
+void afunix_sd_set_perm(LogDriver *self, gint perm);
 
 LogDriver *afunix_sd_new(gchar *filename, guint32 flags);
 
