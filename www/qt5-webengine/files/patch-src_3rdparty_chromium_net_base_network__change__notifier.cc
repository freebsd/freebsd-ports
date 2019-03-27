--- src/3rdparty/chromium/net/base/network_change_notifier.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier.cc
@@ -217,7 +217,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
@@ -425,7 +424,7 @@ void NetworkChangeNotifier::LogOperatorCodeHistogram(C
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -674,7 +673,7 @@ NetworkChangeNotifier::NetworkChangeNotifier(
   network_change_calculator_->Init();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
