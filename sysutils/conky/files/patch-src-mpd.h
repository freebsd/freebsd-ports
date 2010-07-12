--- src/mpd.h.orig
+++ src/mpd.h
@@ -31,7 +31,7 @@ int mpd_set_port(const char *);
 void init_mpd(void);
 struct mpd_s *mpd_get_info(void);
 void free_mpd(void);
-void update_mpd(void);
+int update_mpd(void);
 
 void print_mpd_elapsed(struct text_object *, char *, int);
 void print_mpd_length(struct text_object *, char *, int);
