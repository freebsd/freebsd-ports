--- cpp/server/xjson-server.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/server/xjson-server.cc
@@ -63,7 +63,7 @@ using cert_trans::UrlFetcher;
 using cert_trans::XJsonHttpHandler;
 using ct::ClusterNodeState;
 using ct::SignedTreeHead;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::bind;
 using std::function;
 using std::make_shared;
