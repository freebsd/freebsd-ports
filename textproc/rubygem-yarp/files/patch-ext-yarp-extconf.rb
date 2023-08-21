--- ext/yarp/extconf.rb.orig	2023-08-18 17:14:49 UTC
+++ ext/yarp/extconf.rb
@@ -70,7 +70,7 @@ module Yarp
             Rake.sh("templates/template.rb")
           end
           Rake.sh("sh", "configure") # explicit "sh" for Windows where shebangs are not supported
-          Rake.sh("make", target)
+          Rake.sh("gmake", target)
         end
       end
 
