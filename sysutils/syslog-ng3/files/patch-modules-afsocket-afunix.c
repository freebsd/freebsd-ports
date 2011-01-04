diff --git a/modules/afsocket/afunix.c b/modules/afsocket/afunix.c
index bf54441..b486b6b 100644
--- modules/afsocket/afunix.c
+++ modules/afsocket/afunix.c
@@ -55,7 +55,7 @@ afunix_sd_set_gid(LogDriver *s, gchar *group)
 }
 
 void
-afunix_sd_set_perm(LogDriver *s, mode_t perm)
+afunix_sd_set_perm(LogDriver *s, gint perm)
 {
   AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;
 
