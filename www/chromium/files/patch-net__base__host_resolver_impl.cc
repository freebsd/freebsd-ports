--- ./net/base/host_resolver_impl.cc.orig	2010-12-16 02:11:31.000000000 +0100
+++ ./net/base/host_resolver_impl.cc	2010-12-20 20:15:08.000000000 +0100
@@ -199,13 +199,11 @@
 std::vector<int> GetAllGetAddrinfoOSErrors() {
   int os_errors[] = {
 #if defined(OS_POSIX)
-    EAI_ADDRFAMILY,
     EAI_AGAIN,
     EAI_BADFLAGS,
     EAI_FAIL,
     EAI_FAMILY,
     EAI_MEMORY,
-    EAI_NODATA,
     EAI_NONAME,
     EAI_SERVICE,
     EAI_SOCKTYPE,
@@ -919,7 +917,7 @@
 #if defined(OS_WIN)
   EnsureWinsockInit();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (HaveOnlyLoopbackAddresses())
     additional_resolver_flags_ |= HOST_RESOLVER_LOOPBACK_ONLY;
 #endif
@@ -1316,7 +1314,7 @@
     ipv6_probe_job_ = new IPv6ProbeJob(this);
     ipv6_probe_job_->Start();
   }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   if (HaveOnlyLoopbackAddresses()) {
     additional_resolver_flags_ |= HOST_RESOLVER_LOOPBACK_ONLY;
   } else {
