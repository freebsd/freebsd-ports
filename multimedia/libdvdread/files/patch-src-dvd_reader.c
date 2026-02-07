Use statfs() instead of getfsfile() to get device name from a mount point.

(getfsfile() requires an entry in the fstab file which is often not the case
for removable media)

--- src/dvd_reader.c.orig	2020-03-04 18:57:19 UTC
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
@@ -435,7 +435,7 @@ static dvd_reader_t *DVDOpenCommon( void *priv,
     return ctx;
   } else if( S_ISDIR( fileinfo.st_mode ) ) {
 #if defined(SYS_BSD)
-    struct fstab* fe;
+    struct statfs fs;
 #elif defined(__sun) || defined(__linux__)
     FILE *mntfile;
 #endif
@@ -525,13 +525,15 @@ static dvd_reader_t *DVDOpenCommon( void *priv,
         }
     }
 #elif defined(SYS_BSD)
-    if( ( fe = getfsfile( path_copy ) ) ) {
-      dev_name = bsd_block2char( fe->fs_spec );
-      Log3(ctx, "Attempting to use device %s"
-               " mounted on %s for CSS authentication",
-               dev_name,
-               fe->fs_file );
-      ctx->rd = DVDOpenImageFile( ctx, dev_name, NULL, have_css );
+    if( statfs( path_copy, &fs ) == 0 ) {
+        if( !strcmp( path_copy, fs.f_mntonname ) ) {
+            dev_name = bsd_block2char( fs.f_mntfromname );
+            Log3(ctx, "Attempting to use device %s"
+                     " mounted on %s for CSS authentication",
+                     dev_name,
+                     fs.f_mntonname );
+            ctx->rd = DVDOpenImageFile( ctx, dev_name, NULL, have_css );
+        }
     }
 #elif defined(__sun)
     mntfile = fopen( MNTTAB, "r" );
