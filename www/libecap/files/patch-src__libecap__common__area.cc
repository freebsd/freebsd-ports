--- src/libecap/common/area.cc.orig	2010-12-17 21:08:50.000000000 +0300
+++ src/libecap/common/area.cc	2014-09-12 15:11:20.000000000 +0400
@@ -14,8 +14,8 @@
 
 
 libecap::Area libecap::Area::FromTempString(const std::string &tmp) {
-	shared_ptr<StdStringAreaDetails> details(new StdStringAreaDetails(tmp));
-	return Area(details->owner_.data(), details->owner_.size(), details);
+	shared_ptr<StdStringAreaDetails> detls(new StdStringAreaDetails(tmp));
+	return Area(detls->owner_.data(), detls->owner_.size(), detls);
 }
 
 libecap::Area libecap::Area::FromTempBuffer(const char *start, libecap::size_type size) {
