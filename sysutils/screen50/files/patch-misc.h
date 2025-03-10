--- misc.h.orig	2024-03-26 16:41:57.000000000 -0700
+++ misc.h	2024-04-03 11:30:19.350562000 -0700
@@ -28,6 +28,9 @@
 int   AddXChar (char *, int);
 int   AddXChars (char *, int, char *);
 
+time_t SessionCreationTime(const char *fifo);
+
+
 #define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
 
 #endif /* SCREEN_MISC_H */
