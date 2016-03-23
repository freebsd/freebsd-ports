--- cpp/server/ct-mirror_v2.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/server/ct-mirror_v2.cc
@@ -91,7 +91,7 @@ using cert_trans::Update;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::chrono::duration;
 using std::chrono::duration_cast;
