Obtained from:	https://github.com/rails/rails/commit/b80a2bdeb955c81649e483f2f020a3d5f407c2f9

--- app/models/active_storage/variant_with_record.rb.orig	2021-04-24 11:45:24 UTC
+++ app/models/active_storage/variant_with_record.rb
@@ -33,7 +33,7 @@ class ActiveStorage::VariantWithRecord
     def transform_blob
       blob.open do |input|
         variation.transform(input) do |output|
-          yield io: output, filename: "#{blob.filename.base}.#{variation.format}",
+          yield io: output, filename: "#{blob.filename.base}.#{variation.format.downcase}",
             content_type: variation.content_type, service_name: blob.service.name
         end
       end
