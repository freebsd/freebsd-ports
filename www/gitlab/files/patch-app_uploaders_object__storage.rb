--- app/uploaders/object_storage.rb.orig	2018-05-31 10:45:20 UTC
+++ app/uploaders/object_storage.rb
@@ -11,7 +11,7 @@ module ObjectStorage
   ObjectStorageUnavailable = Class.new(StandardError)
 
   DIRECT_UPLOAD_TIMEOUT = 4.hours
-  TMP_UPLOAD_PATH = 'tmp/upload'.freeze
+  TMP_UPLOAD_PATH = 'tmp/uploads'.freeze
 
   module Store
     LOCAL = 1
