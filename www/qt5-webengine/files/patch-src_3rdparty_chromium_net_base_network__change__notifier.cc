--- src/3rdparty/chromium/net/base/network_change_notifier.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier.cc
@@ -533,7 +533,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
@@ -753,7 +752,7 @@ void NetworkChangeNotifier::LogOperatorC
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -978,7 +977,7 @@ NetworkChangeNotifier::NetworkChangeNoti
   network_change_calculator_->Init();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
