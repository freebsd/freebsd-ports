--- mh/folder.c.orig	2022-02-12 15:20:43 UTC
+++ mh/folder.c
@@ -806,6 +806,14 @@ action_pack (void)
       mu_error (_("cannot read input mailbox: %s"), mu_strerror (errno));
       return 1;
     }
+
+  if (count == 0)
+    {
+      mu_mailbox_close (mbox);
+      mu_mailbox_destroy (&mbox);
+      return 0;
+    }
+  
   pack_tab = mu_calloc (count, sizeof pack_tab[0]); /* Never freed. No use to
 		 				       try to. */
 
