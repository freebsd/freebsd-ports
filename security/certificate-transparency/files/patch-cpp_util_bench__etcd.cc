--- cpp/util/bench_etcd.cc.orig	2016-02-02 11:35:23 UTC
+++ cpp/util/bench_etcd.cc
@@ -105,7 +105,7 @@ void test_etcd(int thread_num) {
 
 
 int main(int argc, char* argv[]) {
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
   evthread_use_pthreads();
 
