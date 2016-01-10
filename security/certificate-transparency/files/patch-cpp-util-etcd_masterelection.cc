--- cpp/util/etcd_masterelection.cc.orig	2015-10-27 10:32:35.670615000 +0100
+++ cpp/util/etcd_masterelection.cc	2015-10-27 10:33:16.624128000 +0100
@@ -24,7 +24,7 @@ DEFINE_string(node_id, "", "unique node 
 
 
 int main(int argc, char* argv[]) {
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
   evthread_use_pthreads();
   CHECK(!FLAGS_node_id.empty()) << "Must set --node_id";
