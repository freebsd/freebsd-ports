Use statfs() instead of getfsfile() to get device name from a mount point.

(getfsfile() requires an entry in the fstab file which is often not the case
for removable media)

--- src/dvd_reader.c.orig	2018-01-17 21:35:39 UTC
+++ src/dvd_reader.c
@@ -64,7 +64,7 @@ static inline int _private_gettimeofday( struct timeva
 # include <sys/ucred.h>
 # include <sys/mount.h>
 #elif defined(SYS_BSD)
-# include <fstab.h>
+# include <sys/mount.h>
 #elif defined(__linux__)
 # include <mntent.h>
 # include <paths.h>
@@ -420,7 +420,7 @@ static dvd_reader_t *DVDOpenCommon( const char *ppath,
   } else if( S_ISDIR( fileinfo.st_mode ) ) {
     dvd_reader_t *auth_drive = 0;
 #if defined(SYS_BSD)
-    struct fstab* fe;
+    struct statfs fs;
 #elif defined(__sun) || defined(__linux__)
     FILE *mntfile;
 #endif
@@ -511,14 +511,16 @@ static dvd_reader_t *DVDOpenCommon( const char *ppath,
         }
     }
 #elif defined(SYS_BSD)
-    if( ( fe = getfsfile( path_copy ) ) ) {
-      dev_name = bsd_block2char( fe->fs_spec );
-      fprintf( stderr,
-               "libdvdread: Attempting to use device %s"
-               " mounted on %s for CSS authentication\n",
-               dev_name,
-               fe->fs_file );
-      auth_drive = DVDOpenImageFile( dev_name, NULL, NULL, have_css );
+    if( statfs( path_copy, &fs ) == 0 ) {
+        if( !strcmp( path_copy, fs.f_mntonname ) ) {
+            dev_name = bsd_block2char( fs.f_mntfromname );
+            fprintf( stderr,
+                     "libdvdread: Attempting to use device %s"
+                     " mounted on %s for CSS authentication\n",
+                     dev_name,
+                     fs.f_mntonname );
+            auth_drive = DVDOpenImageFile( dev_name, NULL, NULL, have_css );
+        }
     }
 #elif defined(__sun)
     mntfile = fopen( MNTTAB, "r" );
