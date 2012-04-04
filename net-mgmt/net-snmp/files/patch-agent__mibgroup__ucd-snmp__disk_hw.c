--- ./agent/mibgroup/ucd-snmp/disk_hw.c.orig	2011-09-28 00:53:47.000000000 -0400
+++ ./agent/mibgroup/ucd-snmp/disk_hw.c	2012-04-04 06:33:38.000000000 -0400
@@ -137,6 +137,7 @@
   if (disks) {
      free( disks );
      disks = NULL;
+     maxdisks = numdisks = 0;
   }
   allDisksIncluded = 0;
 }
@@ -189,7 +190,7 @@
   if ( entry ) {
       entry->minspace   = minspace;
       entry->minpercent = minpercent;
-      entry->flags     |= ~NETSNMP_FS_FLAG_UCD;
+      entry->flags     |= NETSNMP_FS_FLAG_UCD;
       disks[numdisks++] = entry;
   }
 }
@@ -321,7 +322,7 @@
 
     switch (vp->magic) {
     case MIBINDEX:
-        long_ret = disknum;
+        long_ret = disknum + 1;
         return ((u_char *) (&long_ret));
     case ERRORNAME:            /* DISKPATH */
         *var_len = strlen(entry->path);
@@ -388,8 +389,9 @@
 
     case ERRORFLAG:
         long_ret = 0;
+	val = netsnmp_fsys_avail_ull(entry);
         if (( entry->minspace >= 0 ) &&
-            ( entry->avail < entry->minspace ))
+	    ( val < entry->minspace ))
             long_ret = 1;
         else if (( entry->minpercent >= 0 ) &&
                  (_percent( entry->avail, entry->size ) < entry->minpercent ))
@@ -398,12 +400,13 @@
 
     case ERRORMSG:
         errmsg[0] = 0;
+	val = netsnmp_fsys_avail_ull(entry);
         if (( entry->minspace >= 0 ) &&
-            ( entry->avail < entry->minspace ))
+	    ( val < entry->minspace ))
                 snprintf(errmsg, sizeof(errmsg),
                         "%s: less than %d free (= %d)",
                         entry->path, entry->minspace,
-                        (int) entry->avail);
+			(int) val);
         else if (( entry->minpercent >= 0 ) &&
                  (_percent( entry->avail, entry->size ) < entry->minpercent ))
                 snprintf(errmsg, sizeof(errmsg),
