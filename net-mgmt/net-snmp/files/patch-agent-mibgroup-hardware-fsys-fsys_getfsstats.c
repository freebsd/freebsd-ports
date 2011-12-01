--- ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2011-11-24 12:01:07.000000000 -0500
+++ ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c	2011-11-24 12:01:20.000000000 -0500
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
