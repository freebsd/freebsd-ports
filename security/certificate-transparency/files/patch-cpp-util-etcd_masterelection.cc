--- cpp/util/etcd_masterelection.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/util/etcd_masterelection.cc
@@ -24,7 +24,7 @@ DEFINE_string(node_id, "", "unique node 
 
 
 int main(int argc, char* argv[]) {
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
   evthread_use_pthreads();
   CHECK(!FLAGS_node_id.empty()) << "Must set --node_id";
