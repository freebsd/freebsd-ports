--- vfs/fish.c.orig	Thu Dec 26 08:21:43 2002
+++ vfs/fish.c	Tue Jun 15 03:15:09 2004
@@ -96,8 +96,7 @@
 	if (strncmp(answer, "### ", 4)) {
 	    was_garbage = 1;
 	    if (string_buf) {
-	        strncpy(string_buf, answer, string_len - 1);
-		*(string_buf + string_len - 1) = 0;
+	        g_strlcpy(string_buf, answer, string_len);
 	    }
 	} else return decode_reply(answer+4, was_garbage);
     }
@@ -668,7 +667,7 @@
 {
     int r;
 
-    r = command (me, super, WAIT_REPLY, cmd);
+    r = command (me, super, WAIT_REPLY, "%s", cmd);
     vfs_add_noncurrent_stamps (&vfs_fish_ops, (vfsid) super, NULL);
     if (r != COMPLETE) ERRNOR (E_REMOTE, -1);
     if (flags & OPT_FLUSH)
