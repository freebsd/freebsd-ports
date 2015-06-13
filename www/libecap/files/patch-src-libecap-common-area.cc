--- src/libecap/common/area.cc.orig	2015-05-13 16:00:35 UTC
+++ src/libecap/common/area.cc
@@ -14,8 +14,8 @@ const libecap::size_type libecap::nsize 
 
 
 libecap::Area libecap::Area::FromTempString(const std::string &tmp) {
-	shared_ptr<StdStringAreaDetails> details(new StdStringAreaDetails(tmp));
-	return Area(details->owner_.data(), details->owner_.size(), details);
+	shared_ptr<StdStringAreaDetails> detls(new StdStringAreaDetails(tmp));
+	return Area(detls->owner_.data(), detls->owner_.size(), detls);
 }
 
 libecap::Area libecap::Area::FromTempBuffer(const char *start, libecap::size_type size) {
