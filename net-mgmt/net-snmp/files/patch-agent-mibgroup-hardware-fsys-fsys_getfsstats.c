--- ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig       2011-08-05 10:20:55.000000000 +0200
+++ ./agent/mibgroup/hardware/fsys/fsys_getfsstats.c    2011-08-05 10:21:38.000000000 +0200
@@ -156,7 +156,7 @@
         entry->device[sizeof(entry->device)-1] = '\0';
         entry->units = stats[i].f_bsize;    /* or f_frsize */
         entry->size  = stats[i].f_blocks;
-        entry->used  = stats[i].f_bfree;
+        entry->used  = stats[i].f_blocks - stats[i].f_bfree;
         entry->avail = stats[i].f_bavail;
         entry->inums_total = stats[i].f_files;
         entry->inums_avail = stats[i].f_ffree;