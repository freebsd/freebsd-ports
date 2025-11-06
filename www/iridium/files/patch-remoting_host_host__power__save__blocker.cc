--- remoting/host/host_power_save_blocker.cc.orig	2025-11-06 10:11:34 UTC
+++ remoting/host/host_power_save_blocker.cc
@@ -29,7 +29,7 @@ HostPowerSaveBlocker::~HostPowerSaveBlocker() {
 
 void HostPowerSaveBlocker::OnClientConnected(const std::string& jid) {
   // TODO(447203893): Re-enable this on Linux once the bug is fixed.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   blocker_ = std::make_unique<device::PowerSaveBlocker>(
       device::mojom::WakeLockType::kPreventDisplaySleep,
       device::mojom::WakeLockReason::kOther, "Remoting session is active",
