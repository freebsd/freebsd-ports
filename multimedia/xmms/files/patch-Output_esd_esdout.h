--- Output/esd/esdout.h.orig	2004-07-18 20:03:46 UTC
+++ Output/esd/esdout.h
@@ -68,6 +68,7 @@ void esdout_fetch_volume(int *l, int *r)
 void esdout_set_volume(int l, int r);
 void esdout_mixer_init(void);
 void esdout_mixer_init_vol(int l, int r);
+void esdout_reset_playerid(void);
 
 int esdout_playing(void);
 int esdout_free(void);
