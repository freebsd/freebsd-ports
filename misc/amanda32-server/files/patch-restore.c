--- restore-src/restore.c.orig	Wed Nov 29 09:49:01 2006
+++ restore-src/restore.c	Wed Nov 29 09:49:19 2006
@@ -1692,13 +1692,13 @@
     seentapes_t *seentapes = NULL;
     int ret;
 
+    if(!prompt_out) prompt_out = stderr;
+
     dbprintf(("search_tapes(prompt_out=%d, prompt_in=%d,  use_changer=%d, "
 	      "tapelist=%p, "
 	      "match_list=%p, flags=%p, features=%p)\n",
 	      fileno(prompt_out), fileno(prompt_in), use_changer, tapelist,
 	      match_list, flags, their_features));
-
-    if(!prompt_out) prompt_out = stderr;
 
     if(flags->blocksize)
 	blocksize = (size_t)flags->blocksize;
