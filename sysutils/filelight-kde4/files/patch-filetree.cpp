--- filelight/filetree.cpp.orig	Fri Aug 29 18:06:32 2003
+++ filelight/filetree.cpp	Fri Aug 29 18:19:06 2003
@@ -77,7 +77,7 @@
 }
 
 
-static int selector( struct dirent64 const *ent )
+static int selector( struct dirent *ent )
 {
   if( (strcmp( ent->d_name, "." ) == 0) || (strcmp( ent->d_name, ".." ) == 0) )
     return 0;
@@ -93,16 +93,16 @@
   if( m_haltScan ) return NULL;
 
   //the 64bit version lets us support more than 2GB files
-  struct dirent64 **eps;
+  struct dirent **eps;
   int n;
 
  
-  n = scandir64( path, &eps, selector, /*alphasort*/ NULL );
+  n = scandir( path, &eps, selector, /*alphasort*/ NULL );
 
   if( n >= 0 ) {
 
     char *new_path, *new_dirname;
-    struct stat64 statbuf;
+    struct stat statbuf;
     unsigned char strlen_path = strlen( path ) + 2; //saves recalculations
     Directory            *cwd = new Directory( dirname );
     Filesize          dirsize = 0;
@@ -121,7 +121,7 @@
 */
       
       //get some more detail about the file with lstat            
-      lstat64( new_path, &statbuf );
+      lstat( new_path, &statbuf );
       statbuf.st_size /= 1024; //using units of kB as 32bit max is 4GB and 64bit ints are expensive
 
       if( S_ISLNK( statbuf.st_mode ) )
@@ -260,8 +260,9 @@
 
 #include <fstab.h>
 #include <mntent.h>
+#ifndef __FreeBSD__
 #include <sys/statfs.h>
-
+#endif
 
 #define INFO_PARTITIONS "/proc/partitions"
 #define INFO_MOUNTED_PARTITIONS "/etc/mtab"	/* on Linux... */
