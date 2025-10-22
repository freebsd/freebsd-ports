--- net/base/sockaddr_util_posix_unittest.cc.orig	2025-10-21 16:57:35 UTC
+++ net/base/sockaddr_util_posix_unittest.cc
@@ -77,7 +77,8 @@ TEST(FillUnixAddressTest, AbstractLinuxAddress) {
   SockaddrStorage storage;
   std::string path(kMaxUnixAddressPath, '0');
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX?
   EXPECT_TRUE(FillUnixAddress(path, /*use_abstract_namespace=*/true, &storage));
 
   EXPECT_EQ(path.size() + 1U + offsetof(struct sockaddr_un, sun_path),
