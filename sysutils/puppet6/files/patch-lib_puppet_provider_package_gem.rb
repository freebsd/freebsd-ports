--- lib/puppet/provider/package/gem.rb.orig	2019-04-09 12:24:52 UTC
+++ lib/puppet/provider/package/gem.rb
@@ -128,7 +128,7 @@ Puppet::Type.type(:package).provide :gem, :parent => P
         end
       end
     else
-      command << "--no-rdoc" << "--no-ri" << resource[:name]
+      command << "--no-document" << resource[:name]
     end
 
     output = execute(command, {:failonfail => true, :combine => true, :custom_environment => {"HOME"=>ENV["HOME"]}})
