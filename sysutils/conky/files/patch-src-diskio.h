--- src/diskio.h.orig
+++ src/diskio.h
@@ -47,7 +47,7 @@ struct diskio_stat {
 extern struct diskio_stat stats;
 
 struct diskio_stat *prepare_diskio_stat(const char *);
-void update_diskio(void);
+int update_diskio(void);
 void clear_diskio_stats(void);
 void update_diskio_values(struct diskio_stat *, unsigned int, unsigned int);
 
