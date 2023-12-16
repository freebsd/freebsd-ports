--- ext/prism/extconf.rb.orig	2023-12-01 12:09:54 UTC
+++ ext/prism/extconf.rb
@@ -34,7 +34,7 @@ def make(target)
       system("templates/template.rb", exception: true)
     end
 
-    system("make", target, exception: true)
+    system("gmake", target, exception: true)
   end
 end
 
