--- cpp/server/ct-mirror.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/server/ct-mirror.cc
@@ -98,7 +98,7 @@ using cert_trans::Update;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::chrono::duration;
 using std::chrono::duration_cast;
