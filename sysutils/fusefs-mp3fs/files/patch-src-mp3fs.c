--- src/mp3fs.c	2012-02-18 20:55:29.000000000 +0100
+++ src/mp3fs.c	2012-02-17 21:06:13.000000000 +0100
@@ -38,6 +38,9 @@
 
 #include "transcode.h"
 
+#define	S_ISLNK(m)	(((m) & 0170000) == 0120000)	/* symbolic link */
+#define	S_ISSOCK(m)	(((m) & 0170000) == 0140000)
+
 struct mp3fs_params params = {
     .basepath           = NULL,
     .bitrate            = 128,
