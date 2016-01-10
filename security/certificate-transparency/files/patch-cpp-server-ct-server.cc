--- cpp/server/ct-server.cc.orig	2015-10-24 17:48:38.840376000 +0200
+++ cpp/server/ct-server.cc	2015-10-24 17:49:03.684762000 +0200
@@ -116,7 +116,7 @@ using cert_trans::Update;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::chrono::duration;
 using std::chrono::duration_cast;
