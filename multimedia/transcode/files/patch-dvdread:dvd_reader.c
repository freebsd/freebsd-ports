--- dvdread/dvd_reader.c.orig	Wed Feb 19 10:27:09 2003
+++ dvdread/dvd_reader.c	Wed Feb 19 10:27:36 2003
@@ -140,15 +140,7 @@
             dvdcss_error = (char* (*)(dvdcss_handle))
                                 dlsym( dvdcss_library, U_S "dvdcss_error" );
 
-            if( dlsym( dvdcss_library, U_S "dvdcss_crack" ) ) {
-                fprintf( stderr, "libdvdread: Old (pre-0.0.2) version of "
-                                 "libdvdcss found.\n"
-                                 "libdvdread: You should get the "
-                                 "latest version from "
-                                 "http://www.videolan.org/\n" );
-                dlclose( dvdcss_library );
-                dvdcss_library = 0;
-            } else if( !dvdcss_open  || !dvdcss_close || !dvdcss_seek ||
+            if( !dvdcss_open  || !dvdcss_close || !dvdcss_seek ||
                        !dvdcss_title || !dvdcss_read  || !dvdcss_error ) {
 
                 fprintf( stderr, "libdvdread: Unknown incompatible version "
