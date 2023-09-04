--- ext/yarp/extconf.rb.orig	2023-08-29 19:49:53 UTC
+++ ext/yarp/extconf.rb
@@ -75,7 +75,7 @@ module Yarp
             # normally we package up the configure and other files in the gem itself
             system("templates/template.rb", exception: true)
           end
-          system("make", target, exception: true)
+          system("gmake", target, exception: true)
         end
       end
 
