--- agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2017-03-22 16:28:29 UTC
+++ agent/mibgroup/hardware/fsys/fsys_getfsstats.c
@@ -116,7 +116,7 @@ netsnmp_fsys_arch_load( void )
     /*
      * Retrieve information about the currently mounted filesystems...
      */
-    n = NSFS_GETFSSTAT( NULL, 0, 0 );
+    n = NSFS_GETFSSTAT( NULL, 0, MNT_NOWAIT );
     if ( n==0 )
         return;
     stats = (struct NSFS_STATFS *)malloc( n * sizeof( struct NSFS_STATFS ));
