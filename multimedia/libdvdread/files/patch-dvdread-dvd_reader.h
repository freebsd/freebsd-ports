--- dvdread/dvd_reader.h.orig	Mon Jun 18 05:29:13 2001
+++ dvdread/dvd_reader.h	Tue Jun 26 23:30:13 2001
@@ -20,6 +20,11 @@
 #ifndef DVD_READER_H_INCLUDED
 #define DVD_READER_H_INCLUDED
 
+#if defined(__FreeBSD__)
+#include <unistd.h>
+typedef off_t off64_t;
+#endif
+
 #include <sys/types.h>
 
 #ifdef __cplusplus
