--- pstree.c.orig
+++ pstree.c
@@ -655,8 +655,9 @@
   sprintf(nhead, "%s%s ", head,
 	  head[0] == '\0' ? "" : EXIST(P[idx].sister) ? C->bar : " ");
   
-  for (child = P[idx].child; EXIST(child); child = P[child].sister)
-    PrintTree(child, nhead);
+  if (P[idx].pid)
+    for (child = P[idx].child; EXIST(child); child = P[child].sister)
+      PrintTree(child, nhead);
 }
 
 void Usage(void) {
