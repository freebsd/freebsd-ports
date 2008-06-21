--- archivemount.c.orig	2006-12-28 18:32:47.000000000 +0300
+++ archivemount.c	2008-06-20 20:31:46.000000000 +0400
@@ -19,7 +19,7 @@
 #define _GNU_SOURCE 1
 #endif
 
-#define FUSE_USE_VERSION 22
+#define FUSE_USE_VERSION 25
 #define MAXBUF 4096
 
 #include <fuse.h>
@@ -31,7 +31,9 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
+#ifdef HAVE_STATFS
 #include <sys/statfs.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
@@ -42,6 +44,7 @@
 #include <wchar.h>
 #include <archive.h>
 #include <archive_entry.h>
+#include <limits.h>
 
   /**********/
  /* macros */
@@ -433,9 +436,14 @@
 			strlen( P_tmpdir ) +
 			strlen( "_archivemount" ) +
 			strlen( tmppath ) + 8 );
-	sprintf( *location, "%s/archivemount%s_XXXXXX", P_tmpdir, tmppath );
+	sprintf( *location, "/tmp/archivemount%s_XXXXXX", tmppath );
 	free( tmppath );
-	if( ( fh = mkstemp( *location ) == -1 ) ) {
+
+    char bsdLocation[PATH_MAX];
+
+    strcpy(bsdLocation, *location);
+
+	if( ( fh = mkstemp(bsdLocation ) == -1 ) ) {
 		log( "Could not create temp file name %s: %s",
 				*location, strerror( errno ) );
 		free( *location );
@@ -1449,7 +1457,13 @@
 		return tmp;
 	}
 	/* create temp file */
-	if( mknod( location, mode, rdev ) == -1 ) {
+    if (S_ISREG( mode )) {
+        tmp = open( location, O_CREAT | O_EXCL | O_WRONLY, mode );
+    } else if (S_ISFIFO( mode ))
+        tmp = mkfifo( location, mode );
+    else
+        tmp = mknod( location, mode, rdev );
+	if( tmp == -1 ) {
 		log( "Could not create temporary file %s: %s",
 				location, strerror( errno ) );
 		free( location );
@@ -1604,6 +1618,7 @@
 	return 0;
 }
 
+#ifdef HAVE_STATFS
 static int
 ar_statfs( const char *path, struct statfs *stbuf )
 {
@@ -1613,6 +1628,7 @@
 
 	return -ENOSYS;
 }
+#endif
 
 static int
 ar_rename( const char *from, const char *to )
@@ -1753,7 +1769,9 @@
 	.open		= ar_open,
 	.read		= ar_read,
 	.write		= ar_write,
+#ifdef HAVE_STATFS    
 	.statfs		= ar_statfs,
+#endif    
 	.release	= ar_release,
 	.fsync		= ar_fsync,
 /*
