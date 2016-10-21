--- cpp/server/ct-server_v2.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/server/ct-server_v2.cc
@@ -66,7 +66,7 @@ using cert_trans::TreeSigner;
 using cert_trans::UrlFetcher;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::function;
 using std::make_shared;
