--- xdf.cc.orig	Thu Nov 14 00:06:28 2002
+++ xdf.cc	Fri Jan 17 00:56:31 2003
@@ -18,18 +18,18 @@
 #include <stdio.h>
 #include <iostream.h>
 #include <strstream.h>
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <sys/param.h>
 #include <sys/types.h>
-#include <sys/vfs.h>
+// #include <sys/vfs.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <assert.h>
-#include <mntent.h>
+//#include <mntent.h>
 #include <sys/mount.h>
-#include <linux/fs.h>
+#include <fstab.h>
 
 #include "config.H"
 #include "xdf.H"
@@ -74,17 +74,22 @@
 /*{{{  Get Information and create Panel  */
   int row = 0;
 
-  fstab = setmntent( "/etc/fstab", "r");
+  if (! setfsent()) {
+    perror("Couldn't open /etc/fstab!\n");
+    return 255;
+  }
+
 
   mountpoints=0;
-  while ( table = getmntent( fstab ) ) {
-    if ( strcmp( "swap", table->mnt_dir) && strcmp( "/proc", table->mnt_dir) 
-	 && ( strcmp( "nfs", table->mnt_type ) || ( ! no_nfs ) )
-	 && ( strcmp( "iso9660", table->mnt_type ) || ( ! no_iso9660 ) )
+  fstab = getfsent();
+  while ( fstab ) {
+    if ( strcmp( "swap", fstab->fs_file) && strcmp( "/proc", fstab->fs_file)
+      && ( strcmp( "nfs", fstab->fs_vfstype ) || ( ! no_nfs ) )
+      && ( strcmp( "cd9660", fstab->fs_vfstype ) || ( ! no_iso9660 ) )
 	 ){
       par_table[mountpoints] = new Partition;
-      par_table[mountpoints]->name = new char[ strlen(table->mnt_dir) + 1 ];
-      strcpy(par_table[mountpoints]->name, table->mnt_dir);
+      par_table[mountpoints]->name = new char[ strlen(fstab->fs_file) + 1 ];
+      strcpy(par_table[mountpoints]->name, fstab->fs_file);
       statfs(par_table[mountpoints]->name, &stat_buffer);
       par_table[mountpoints]->last_max_value = 
 	par_table[mountpoints]->max_value = ((double)stat_buffer.f_blocks * (double)stat_buffer.f_bsize) / (double) 1024;
@@ -97,8 +102,9 @@
       par_table[mountpoints]->last_value = -1;
       mountpoints++;
     }
+    fstab = getfsent();
   }
-  endmntent( fstab );
+  endfsent();
 
 /*{{{  Title strings  */
 
@@ -230,13 +236,13 @@
     par_table[i]->status = TRUE;
   }
   
-  mtab = setmntent( "/etc/mtab", "r");
-  while ( table = getmntent( mtab ) ){
-    for ( int i = 0 ; i < mountpoints ; ++i ){
-      if ( !strcmp(par_table[i]->name, table->mnt_dir) ) par_table[i]->status = FALSE;
+  mntcount = getmntinfo(&mtab, 0);
+  for (int i = 0; i < mntcount; i++) {
+    for (int j = 0; j < mountpoints; j++) {
+     table = &mtab[i];
+      if (! strcmp(par_table[j]->name, table->f_mntonname)) par_table[j]->status = FALSE;
     }
   }
-  endmntent( mtab );
   
   for ( int i = 0 ; i < mountpoints ; ++i ){
     if ( par_table[i]->status == FALSE && par_table[i]->last_status == TRUE) {
