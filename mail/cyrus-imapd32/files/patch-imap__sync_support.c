--- imap/sync_support.c.orig	2017-06-22 03:05:45 UTC
+++ imap/sync_support.c
@@ -3491,7 +3491,7 @@ int sync_apply_message(struct dlist *kin
         const char *fname;
 
         /* XXX - complain more? */
-        if (!dlist_tofile(ki, &part, &guid, (ulong *) &size, &fname))
+        if (!dlist_tofile(ki, &part, &guid, (unsigned long *) &size, &fname))
             continue;
 
         part_list = sync_reserve_partlist(reserve_list, part);
@@ -4546,7 +4546,7 @@ static int fetch_file(struct mailbox *ma
         return r;
     }
 
-    if (!dlist_tofile(kin->head, NULL, &guid, (ulong *) &size, &fname)) {
+    if (!dlist_tofile(kin->head, NULL, &guid, (unsigned long *) &size, &fname)) {
         r = IMAP_MAILBOX_NONEXISTENT;
         syslog(LOG_ERR, "IOERROR: fetch_file failed tofile %s", error_message(r));
         goto done;
