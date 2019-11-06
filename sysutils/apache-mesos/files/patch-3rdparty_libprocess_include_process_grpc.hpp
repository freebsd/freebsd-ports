--- 3rdparty/libprocess/include/process/grpc.hpp.orig	2019-11-04 22:31:46 UTC
+++ 3rdparty/libprocess/include/process/grpc.hpp
@@ -90,7 +90,7 @@ struct MethodTraits; // Undefined.
 
 template <typename Stub, typename Request, typename Response>
 struct MethodTraits<
-    std::unique_ptr<::grpc::ClientAsyncResponseReader<Response>>(Stub::*)(
+    std::unique_ptr<::grpc_impl::ClientAsyncResponseReader<Response>>(Stub::*)(
         ::grpc::ClientContext*,
         const Request&,
         ::grpc::CompletionQueue*)>
@@ -235,7 +235,7 @@ class Runtime (public)
           std::shared_ptr<Response> response(new Response());
           std::shared_ptr<::grpc::Status> status(new ::grpc::Status());
 
-          std::shared_ptr<::grpc::ClientAsyncResponseReader<Response>> reader =
+          std::shared_ptr<::grpc_impl::ClientAsyncResponseReader<Response>> reader =
             (typename internal::MethodTraits<Method>::stub_type(
                 connection.channel).*method)(context.get(), request, queue);
 
