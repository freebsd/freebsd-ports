--- sidebar/functions.c.orig   2020-10-04 15:20:02 UTC
+++ sidebar/functions.c
@@ -72,7 +72,7 @@ static struct SbEntry **next_new(struct 
   struct SbEntry **sbep = NULL;
   ARRAY_FOREACH_FROM_TO(sbep, &wdata->entries, begin, end)
   {
-    if ((*sbep)->mailbox->has_new && (*sbep)->mailbox->msg_unread != 0)
+    if ((*sbep)->mailbox->has_new || (*sbep)->mailbox->msg_unread != 0)
       return sbep;
   }
   return NULL;
@@ -143,7 +143,7 @@ static struct SbEntry **prev_new(struct 
   struct SbEntry **sbep = NULL, **prev = NULL;
   ARRAY_FOREACH_FROM_TO(sbep, &wdata->entries, begin, end)
   {
-    if ((*sbep)->mailbox->has_new && (*sbep)->mailbox->msg_unread != 0)
+    if ((*sbep)->mailbox->has_new || (*sbep)->mailbox->msg_unread != 0)
       prev = sbep;
   }
 
