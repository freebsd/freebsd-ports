--- src/lib/utils.py.orig	Sun Nov 16 03:58:11 2003
+++ src/lib/utils.py	Sun Nov 16 03:58:32 2003
@@ -22,7 +22,7 @@
     previous = None
     while res_len < chars and i < frag_len - 1:
         i += 1
-        current = fragment[i]
+        current = fragment[i].encode('utf-8')
         if in_tag:
             if in_attr:
                 if current == '"':
