--- src/transfer.c.orig	Sun Nov  4 20:30:19 2001
+++ src/transfer.c	Mon Nov 18 11:09:25 2002
@@ -1827,8 +1827,10 @@
     printf("set offset to %ld %d\n", transfer->progress, cnt);
 #endif
     transfer->resume_check = l_malloc(cnt * sizeof(char));
-    transfer->check_length = read(fileno(transfer->file),
-				  transfer->resume_check, cnt);
+    transfer->check_length = fread(transfer->resume_check, 
+                                  sizeof(char),
+                                  cnt,
+                                  transfer->file);
     fclose(transfer->file);
 
     if (transfer->check_length != cnt) {
