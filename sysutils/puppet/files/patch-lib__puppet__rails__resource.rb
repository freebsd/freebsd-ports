--- ./lib/puppet/rails/resource.rb.orig	2013-10-07 18:00:47.000000000 +0000
+++ ./lib/puppet/rails/resource.rb	2013-12-20 16:47:14.340897154 +0000
@@ -84,7 +84,11 @@
   end
 
   def [](param)
-    super || parameter(param)
+    if param == 'id'
+      super
+    else
+      super || parameter(param)
+    end
   end
 
   # Make sure this resource is equivalent to the provided Parser resource.
