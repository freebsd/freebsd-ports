--- lib/puppet/provider/package/gem.rb.orig
+++ lib/puppet/provider/package/gem.rb
@@ -128,7 +128,7 @@
         end
       end
     else
-      command << "--no-rdoc" << "--no-ri" << resource[:name]
+      command << "--no-document" << resource[:name]
     end
 
     output = execute(command, {:failonfail => true, :combine => true, :custom_environment => {"HOME"=>ENV["HOME"]}})
