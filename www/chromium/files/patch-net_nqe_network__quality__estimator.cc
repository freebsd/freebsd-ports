--- net/nqe/network_quality_estimator.cc.orig	2019-03-17 14:51:31 UTC
+++ net/nqe/network_quality_estimator.cc
@@ -99,7 +99,7 @@ nqe::internal::NetworkID DoGetCurrentNetworkID() {
       case NetworkChangeNotifier::ConnectionType::CONNECTION_ETHERNET:
         break;
       case NetworkChangeNotifier::ConnectionType::CONNECTION_WIFI:
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
         network_id.id = GetWifiSSID();
 #endif
         break;
