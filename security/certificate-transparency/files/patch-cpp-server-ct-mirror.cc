--- cpp/server/ct-mirror.cc.orig	2015-10-24 17:49:55.279261000 +0200
+++ cpp/server/ct-mirror.cc	2015-10-24 17:50:05.284510000 +0200
@@ -124,7 +124,7 @@ using cert_trans::Update;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::chrono::duration;
 using std::chrono::duration_cast;
