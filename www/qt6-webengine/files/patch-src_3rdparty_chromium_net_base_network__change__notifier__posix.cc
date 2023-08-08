--- src/3rdparty/chromium/net/base/network_change_notifier_posix.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier_posix.cc
@@ -92,7 +92,7 @@ NetworkChangeNotifierPosix::NetworkChangeCalculatorPar
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPosix::NetworkChangeCalculatorParamsPosix() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::Milliseconds(4000);
