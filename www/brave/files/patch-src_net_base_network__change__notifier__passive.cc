--- src/net/base/network_change_notifier_passive.cc.orig	2026-10-18 18:43:23 UTC
+++ src/net/base/network_change_notifier_passive.cc
@@ -108,7 +108,7 @@ NetworkChangeNotifierPassive::GetAddress
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPassive::NetworkChangeCalculatorParamsPassive() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::Milliseconds(4000);
