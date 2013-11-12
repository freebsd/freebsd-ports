--- wizd_menu.c.orig	2008-07-02 12:30:10.000000000 +0900
+++ wizd_menu.c	2008-07-02 13:14:51.000000000 +0900
@@ -27,7 +27,9 @@
 #include <errno.h>
 #include <libgen.h>
 #include <regex.h>
+#ifdef __CYGWIN32__
 #include <sys/cygwin.h>
+#endif
 
 #include <dvdread/dvd_reader.h>
 #include <dvdread/ifo_types.h>
@@ -3432,7 +3434,6 @@
 				debug_log_output("ext = '%s'", file_info_p[count].ext);
 			}
 
-	checkmime:
 			if ((mime = lookup_mime_by_ext(file_info_p[count].ext)) == NULL) {
 # ifdef HAVE_W32API
 				if (strcmp(file_info_p[count].ext, "lnk") == 0) {
