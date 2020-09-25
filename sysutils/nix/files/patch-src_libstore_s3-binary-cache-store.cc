--- src/libstore/s3-binary-cache-store.cc.orig	2019-10-10 13:03:46 UTC
+++ src/libstore/s3-binary-cache-store.cc
@@ -44,7 +44,7 @@ R && checkAws(const FormatOrString & fs, Aws::Utils::O
     if (!outcome.IsSuccess())
         throw S3Error(
             outcome.GetError().GetErrorType(),
-            fs.s + ": " + outcome.GetError().GetMessage());
+            fs.s + ": " + outcome.GetError().GetMessage().c_str());
     return outcome.GetResultWithOwnership();
 }
 
@@ -54,8 +54,10 @@ class AwsLogger : public Aws::Utils::Logging::Formatte
 
     void ProcessFormattedStatement(Aws::String && statement) override
     {
-        debug("AWS: %s", chomp(statement));
+        debug("AWS: %s", chomp((const std::string &)statement));
     }
+
+    void Flush() override {}
 };
 
 static void initAWS()
@@ -139,8 +141,8 @@ S3Helper::DownloadResult S3Helper::getObject(
 
     auto request =
         Aws::S3::Model::GetObjectRequest()
-        .WithBucket(bucketName)
-        .WithKey(key);
+        .WithBucket(bucketName.c_str())
+        .WithKey(key.c_str());
 
     request.SetResponseStreamFactory([&]() {
         return Aws::New<std::stringstream>("STRINGSTREAM");
@@ -155,7 +157,7 @@ S3Helper::DownloadResult S3Helper::getObject(
         auto result = checkAws(fmt("AWS error fetching '%s'", key),
             client->GetObject(request));
 
-        res.data = decompress(result.GetContentEncoding(),
+        res.data = decompress(result.GetContentEncoding().c_str(),
             dynamic_cast<std::stringstream &>(result.GetBody()).str());
 
     } catch (S3Error & e) {
@@ -238,8 +240,8 @@ struct S3BinaryCacheStoreImpl : public S3BinaryCacheSt
 
         auto res = s3Helper.client->HeadObject(
             Aws::S3::Model::HeadObjectRequest()
-            .WithBucket(bucketName)
-            .WithKey(path));
+            .WithBucket(bucketName.c_str())
+            .WithKey(path.c_str()));
 
         if (!res.IsSuccess()) {
             auto & error = res.GetError();
@@ -302,7 +304,7 @@ struct S3BinaryCacheStoreImpl : public S3BinaryCacheSt
 
             std::shared_ptr<TransferHandle> transferHandle =
                 transferManager->UploadFile(
-                    stream, bucketName, path, mimeType,
+                    stream, bucketName.c_str(), path.c_str(), mimeType.c_str(),
                     Aws::Map<Aws::String, Aws::String>(),
                     nullptr /*, contentEncoding */);
 
@@ -320,13 +322,13 @@ struct S3BinaryCacheStoreImpl : public S3BinaryCacheSt
 
             auto request =
                 Aws::S3::Model::PutObjectRequest()
-                .WithBucket(bucketName)
-                .WithKey(path);
+                .WithBucket(bucketName.c_str())
+                .WithKey(path.c_str());
 
-            request.SetContentType(mimeType);
+            request.SetContentType(mimeType.c_str());
 
             if (contentEncoding != "")
-                request.SetContentEncoding(contentEncoding);
+                request.SetContentEncoding(contentEncoding.c_str());
 
             auto stream = std::make_shared<istringstream_nocopy>(data);
 
@@ -393,9 +395,9 @@ struct S3BinaryCacheStoreImpl : public S3BinaryCacheSt
             auto res = checkAws(format("AWS error listing bucket '%s'") % bucketName,
                 s3Helper.client->ListObjects(
                     Aws::S3::Model::ListObjectsRequest()
-                    .WithBucket(bucketName)
+                    .WithBucket(bucketName.c_str())
                     .WithDelimiter("/")
-                    .WithMarker(marker)));
+                    .WithMarker(marker.c_str())));
 
             auto & contents = res.GetContents();
 
@@ -404,8 +406,8 @@ struct S3BinaryCacheStoreImpl : public S3BinaryCacheSt
 
             for (auto object : contents) {
                 auto & key = object.GetKey();
-                if (key.size() != 40 || !hasSuffix(key, ".narinfo")) continue;
-                paths.insert(storeDir + "/" + key.substr(0, key.size() - 8));
+                if (key.size() != 40 || !hasSuffix(key.c_str(), ".narinfo")) continue;
+                paths.insert(storeDir + "/" + key.substr(0, key.size() - 8).c_str());
             }
 
             marker = res.GetNextMarker();
