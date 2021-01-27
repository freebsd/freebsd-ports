--- net/nqe/network_quality_estimator_unittest.cc.orig	2021-01-18 21:29:02 UTC
+++ net/nqe/network_quality_estimator_unittest.cc
@@ -2129,7 +2129,7 @@ TEST_F(NetworkQualityEstimatorTest, TestGlobalSocketWa
 // TestTCPSocketRTT requires kernel support for tcp_info struct, and so it is
 // enabled only on certain platforms.
 // ChromeOS is disabled due to crbug.com/986904
-#if (defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID)) && \
+#if (defined(TCP_INFO) || defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)) && \
     !defined(OS_CHROMEOS)
 #define MAYBE_TestTCPSocketRTT TestTCPSocketRTT
 #else
