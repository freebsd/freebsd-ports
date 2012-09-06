--- lib/puppet/provider/exec.rb.orig    2012-08-21 17:41:17.000000000 -0400
+++ lib/puppet/provider/exec.rb 2012-08-30 12:31:32.000000000 -0400
@@ -66,11 +66,9 @@
   end

   def extractexe(command)
-    if command.is_a? Array
-      command.first
-    elsif match = /^"([^"]+)"|^'([^']+)'/.match(command)
-      # extract whichever of the two sides matched the content.
-      match[1] or match[2]
+    # easy case: command was quoted
+    if command =~ /^"([^"]+)"/
+      $1
     else
       command.split(/ /)[0]
     end
