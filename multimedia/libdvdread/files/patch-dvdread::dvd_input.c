--- dvdread/dvd_input.c.orig	Sun Jul 13 14:42:27 2003
+++ dvdread/dvd_input.c	Sun Jul 13 14:42:41 2003
@@ -297,14 +297,7 @@
     
     dvdcss_version = (char **)dlsym(dvdcss_library, U_S "dvdcss_interface_2");
 
-    if(dlsym(dvdcss_library, U_S "dvdcss_crack")) {
-      fprintf(stderr, 
-	      "libdvdread: Old (pre-0.0.2) version of libdvdcss found.\n"
-	      "libdvdread: You should get the latest version from "
-	      "http://www.videolan.org/\n" );
-      dlclose(dvdcss_library);
-      dvdcss_library = NULL;
-    } else if(!DVDcss_open  || !DVDcss_close || !DVDcss_title || !DVDcss_seek
+    if(!DVDcss_open  || !DVDcss_close || !DVDcss_title || !DVDcss_seek
 	      || !DVDcss_read || !DVDcss_error || !dvdcss_version) {
       fprintf(stderr,  "libdvdread: Missing symbols in libdvdcss.so.2, "
 	      "this shouldn't happen !\n");
