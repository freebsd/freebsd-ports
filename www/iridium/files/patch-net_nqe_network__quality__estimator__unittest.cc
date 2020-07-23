--- net/nqe/network_quality_estimator_unittest.cc.orig	2020-03-16 18:39:54 UTC
+++ net/nqe/network_quality_estimator_unittest.cc
@@ -2107,7 +2107,7 @@ TEST_F(NetworkQualityEstimatorTest, TestGlobalSocketWa
 // TestTCPSocketRTT requires kernel support for tcp_info struct, and so it is
 // enabled only on certain platforms.
 // ChromeOS is disabled due to crbug.com/986904
-#if (defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID)) && \
+#if (defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)) && \
     !defined(OS_CHROMEOS)
 #define MAYBE_TestTCPSocketRTT TestTCPSocketRTT
 #else
