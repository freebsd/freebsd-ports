Obtained from:	https://github.com/rails/rails/commit/b80a2bdeb955c81649e483f2f020a3d5f407c2f9

--- app/models/active_storage/variant.rb.orig	2021-04-24 11:45:24 UTC
+++ app/models/active_storage/variant.rb
@@ -89,7 +89,7 @@ class ActiveStorage::Variant
   end
 
   def filename
-    ActiveStorage::Filename.new "#{blob.filename.base}.#{variation.format}"
+    ActiveStorage::Filename.new "#{blob.filename.base}.#{variation.format.downcase}"
   end
 
   alias_method :content_type_for_serving, :content_type
