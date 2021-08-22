--- remoting/host/scoped_url_forwarder.cc.orig	2021-07-28 08:18:58 UTC
+++ remoting/host/scoped_url_forwarder.cc
@@ -13,7 +13,7 @@ ScopedUrlForwarder::ScopedUrlForwarder() = default;
 
 ScopedUrlForwarder::~ScopedUrlForwarder() = default;
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 // static
 std::unique_ptr<ScopedUrlForwarder> ScopedUrlForwarder::Create() {
@@ -22,6 +22,6 @@ std::unique_ptr<ScopedUrlForwarder> ScopedUrlForwarder
   return base::WrapUnique(new ScopedUrlForwarder());
 }
 
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
 }  // namespace remoting
