--- cpp/util/bench_etcd.cc	2015-10-27 10:34:16.495831000 +0100
+++ cpp/util/bench_etcd.cc.orig	2015-10-27 10:33:58.482267000 +0100
@@ -105,7 +105,7 @@ void test_etcd(int thread_num) {
 
 
 int main(int argc, char* argv[]) {
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
   evthread_use_pthreads();
 
