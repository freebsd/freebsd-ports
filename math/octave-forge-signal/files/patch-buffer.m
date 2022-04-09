--- ../inst/buffer.m.orig	2022-04-08 21:56:59.940849000 -0500
+++ ../inst/buffer.m	2022-04-08 21:57:48.381303000 -0500
@@ -120,7 +120,7 @@
           endwhile
           [i, j] = ind2sub([n-p, m], l);
           if (all ([i, j] == [n-p, m]))
-            off --;
+            off--;
           endif
           y (:, end - off + 2 : end) = [];
         else
