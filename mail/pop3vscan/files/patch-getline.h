--- getline.h.orig	2002-06-12 00:19:05 UTC
+++ getline.h
@@ -71,6 +71,7 @@ typedef struct linebuf {
  *			      You can call getline again, but it will return
  *			      the rest of that line and not the next one!
  */
+#define getline folke_getline
 int getline(int fd, struct linebuf * l);
 
 /* writes line to fd
