--- ext/prism/extconf.rb.orig	2023-10-05 01:08:46 UTC
+++ ext/prism/extconf.rb
@@ -75,7 +75,7 @@ module Prism
             # normally we package up the configure and other files in the gem itself
             system("templates/template.rb", exception: true)
           end
-          system("make", target, exception: true)
+          system("gmake", target, exception: true)
         end
       end
 
