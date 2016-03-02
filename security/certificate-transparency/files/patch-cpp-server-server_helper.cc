--- cpp/server/server_helper.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/server/server_helper.cc
@@ -4,7 +4,7 @@
 #include "util/fake_etcd.h"
 
 using cert_trans::Server;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using std::string;
 using std::unique_ptr;
 
