--- dvdread/dvd_reader.c.orig	Fri Jun 22 02:40:48 2001
+++ dvdread/dvd_reader.c	Mon Jun 25 22:57:38 2001
@@ -30,6 +30,9 @@
 #if defined(__sun)
 #include <sys/mnttab.h>
 #define MNT_FILE MNTTAB
+#elif defined(__FreeBSD__)
+#undef MNT_FILE
+#include <fstab.h>
 #else
 #include <mntent.h>
 #define MNT_FILE MOUNTED
@@ -183,7 +186,11 @@
     } else if( S_ISDIR( fileinfo.st_mode ) ) {
         dvd_reader_t *auth_drive = 0;
         char *path_copy = strdup( path );
+#if defined(__FreeBSD__)
+        struct fstab* fe;
+#else
         FILE *mntfile;
+#endif        
 
         /**
          * If we're being asked to open a directory, check if that directory is
@@ -204,6 +211,16 @@
             }
         }
 
+#if defined(__FreeBSD__)
+        if ((fe = getfsfile(path_copy))) {
+            fprintf(stderr,
+                    "libdvdread: Attempting to use block "
+                    "device %s on %s for CSS authentication.\n",
+                    fe->fs_spec,
+                    fe->fs_file);
+            auth_drive = DVDOpenImageFile(fe->fs_file);
+        }
+#else
         mntfile = fopen( MNT_FILE, "r" );
         if( mntfile ) {
 #if defined(__sun)
@@ -234,7 +251,7 @@
 #endif
             fclose( mntfile );
         }
-
+#endif
         free( path_copy );
 
         /**
@@ -600,21 +617,39 @@
 
         if( offset < dvd_file->title_sizes[ i ] ) {
             if( ( offset + block_count ) <= dvd_file->title_sizes[ i ] ) {
+#if defined(__FreeBSD__)
+                lseek(dvd_file->title_fds[i],
+                      offset * DVD_VIDEO_LB_LEN,
+                      SEEK_SET);
+#else                
                 lseek64( dvd_file->title_fds[ i ], offset
                          * (int64_t) DVD_VIDEO_LB_LEN, SEEK_SET );
+#endif                
                 ret = read( dvd_file->title_fds[ i ], data,
                             block_count * DVD_VIDEO_LB_LEN );
                 break;
             } else {
 
                 /* Read part 1 */
+#if defined(__FreeBSD__)
+                lseek(dvd_file->title_fds[i],
+                      offset * DVD_VIDEO_LB_LEN,
+                      SEEK_SET);
+#else
                 lseek64( dvd_file->title_fds[ i ], offset
                          * (int64_t) DVD_VIDEO_LB_LEN, SEEK_SET );
+#endif                
                 ret = read( dvd_file->title_fds[ i ], data,
                             dvd_file->title_sizes[ i ] - offset );
 
                 /* Read part 2 */
+#if defined(__FreeBSD__)
+                lseek(dvd_file->title_fds[i + 1],
+                      0,
+                      SEEK_SET);
+#else
                 lseek64( dvd_file->title_fds[ i + 1 ], 0, SEEK_SET );
+#endif                
                 ret += read( dvd_file->title_fds[ i + 1 ],
                              &(data[ ( dvd_file->title_sizes[ i ] - offset )
                              * DVD_VIDEO_LB_LEN ]),
@@ -653,7 +688,11 @@
         dvd_file->seek_pos = offset;
         return offset;
     } else {
+#if defined(__FreeBSD__)        
+        return lseek(dvd_file->title_fds[0], offset, SEEK_SET);
+#else
         return lseek64( dvd_file->title_fds[ 0 ], offset, SEEK_SET );
+#endif        
     }
 }
 
