--- src/3rdparty/chromium/net/base/network_change_notifier_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier_posix.cc
@@ -92,7 +92,7 @@ NetworkChangeNotifierPosix::NetworkChangeCalculatorPar
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPosix::NetworkChangeCalculatorParamsPosix() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::Milliseconds(4000);
