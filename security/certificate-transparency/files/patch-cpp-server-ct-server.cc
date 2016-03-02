--- cpp/server/ct-server.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/server/ct-server.cc
@@ -64,7 +64,7 @@ using cert_trans::TreeSigner;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::function;
 using std::make_shared;
