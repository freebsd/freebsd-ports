--- components/device_signals/test/signals_contract.cc.orig	2022-12-06 08:09:13 UTC
+++ components/device_signals/test/signals_contract.cc
@@ -164,7 +164,7 @@ GetSignalsContract() {
       base::BindRepeating(VerifyUnset, names::kSecureBootEnabled);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUIDLFLAG(IS_BSD)
   contract[names::kAllowScreenLock] =
       base::BindRepeating(VerifyUnset, names::kAllowScreenLock);
   contract[names::kImei] = base::BindRepeating(VerifyUnset, names::kImei);
