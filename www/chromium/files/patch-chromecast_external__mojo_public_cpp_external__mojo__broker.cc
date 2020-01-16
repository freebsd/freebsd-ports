--- chromecast/external_mojo/public/cpp/external_mojo_broker.cc.orig	2019-12-17 19:25:44 UTC
+++ chromecast/external_mojo/public/cpp/external_mojo_broker.cc
@@ -7,7 +7,7 @@
 #include <map>
 #include <utility>
 
-#if OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/stat.h>
 #endif
 
@@ -398,7 +398,7 @@ ExternalMojoBroker::ExternalMojoBroker(const std::stri
       named_channel.TakeServerEndpoint();
   DCHECK(server_endpoint.is_valid());
 
-#if OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
   chmod(broker_path.c_str(), 0770);
 #endif
 
