--- google_apis/gcm/engine/heartbeat_manager.cc.orig	2021-12-14 11:45:06 UTC
+++ google_apis/gcm/engine/heartbeat_manager.cc
@@ -32,13 +32,13 @@ const int kMinClientHeartbeatIntervalMs = 1000 * 30;  
 // Minimum time spent sleeping before we force a new heartbeat.
 const int kMinSuspendTimeMs = 1000 * 10; // 10 seconds.
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // The period at which to check if the heartbeat time has passed. Used to
 // protect against platforms where the timer is delayed by the system being
 // suspended.  Only needed on linux because the other OSes provide a standard
 // way to be notified of system suspend and resume events.
 const int kHeartbeatMissedCheckMs = 1000 * 60 * 5;  // 5 minutes.
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 }  // namespace
 
@@ -192,7 +192,7 @@ void HeartbeatManager::RestartTimer() {
       base::BindRepeating(&HeartbeatManager::OnHeartbeatTriggered,
                           weak_ptr_factory_.GetWeakPtr()));
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Windows, Mac, Android, iOS, and Chrome OS all provide a way to be notified
   // when the system is suspending or resuming.  The only one that does not is
   // Linux so we need to poll to check for missed heartbeats.
@@ -201,7 +201,7 @@ void HeartbeatManager::RestartTimer() {
       base::BindOnce(&HeartbeatManager::CheckForMissedHeartbeat,
                      weak_ptr_factory_.GetWeakPtr()),
       base::Milliseconds(kHeartbeatMissedCheckMs));
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 }
 
 void HeartbeatManager::CheckForMissedHeartbeat() {
@@ -217,14 +217,14 @@ void HeartbeatManager::CheckForMissedHeartbeat() {
     return;
   }
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Otherwise check again later.
   io_task_runner_->PostDelayedTask(
       FROM_HERE,
       base::BindOnce(&HeartbeatManager::CheckForMissedHeartbeat,
                      weak_ptr_factory_.GetWeakPtr()),
       base::Milliseconds(kHeartbeatMissedCheckMs));
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 }
 
 void HeartbeatManager::UpdateHeartbeatInterval() {
