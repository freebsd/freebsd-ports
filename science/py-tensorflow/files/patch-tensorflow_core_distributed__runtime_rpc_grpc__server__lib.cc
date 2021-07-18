--- tensorflow/core/distributed_runtime/rpc/grpc_server_lib.cc.orig	2021-07-08 14:14:12 UTC
+++ tensorflow/core/distributed_runtime/rpc/grpc_server_lib.cc
@@ -487,12 +487,6 @@ class GrpcServerFactory : public ServerFactory {
 class GrpcServerRegistrar {
  public:
   GrpcServerRegistrar() {
-    gpr_allocation_functions alloc_fns;
-    memset(&alloc_fns, 0, sizeof(alloc_fns));
-    alloc_fns.malloc_fn = port::Malloc;
-    alloc_fns.realloc_fn = port::Realloc;
-    alloc_fns.free_fn = port::Free;
-    gpr_set_allocation_functions(alloc_fns);
     ServerFactory::Register("GRPC_SERVER", new GrpcServerFactory());
   }
 };
