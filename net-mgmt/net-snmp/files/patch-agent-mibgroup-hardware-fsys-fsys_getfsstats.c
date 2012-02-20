--- agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2011-09-27 20:53:47.000000000 -0800
+++ agent/mibgroup/hardware/fsys/fsys_getfsstats.c	2012-02-20 01:39:38.000000000 -0900
@@ -150,9 +150,9 @@
         if (!entry)
             continue;
 
-        memcpy( entry->path,   stats[i].f_mntonname,   sizeof(entry->path)  );
+        strncpy( entry->path,   stats[i].f_mntonname,   sizeof(entry->path)  );
         entry->path[sizeof(entry->path)-1] = '\0';
-        memcpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
+        strncpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
         entry->device[sizeof(entry->device)-1] = '\0';
         entry->units = stats[i].f_bsize;    /* or f_frsize */
         entry->size  = stats[i].f_blocks;
@@ -164,7 +164,7 @@
         entry->type = _fs_type( stats[i].f_fstypename );
         entry->flags |= NETSNMP_FS_FLAG_ACTIVE;
 
-        if (! stats[i].NSFS_FLAGS & MNT_LOCAL ) {
+        if (! (stats[i].NSFS_FLAGS & MNT_LOCAL) ) {
             entry->flags |= NETSNMP_FS_FLAG_REMOTE;
         }
         if (  stats[i].NSFS_FLAGS & MNT_RDONLY ) {
@@ -174,5 +174,8 @@
             entry->flags |= NETSNMP_FS_FLAG_BOOTABLE;
         }
         netsnmp_fsys_calculate32(entry);
+	DEBUGMSGTL(("fsys:path", "flags on entry %s: 0x%08x\n", entry->path,
+				entry->flags));
     }
+    free(stats);
 }
