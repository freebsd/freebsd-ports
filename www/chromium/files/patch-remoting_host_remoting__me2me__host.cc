--- remoting/host/remoting_me2me_host.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/remoting_me2me_host.cc
@@ -160,7 +160,7 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
@@ -172,7 +172,7 @@
 #endif  // defined(REMOTING_USE_X11)
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "remoting/host/linux/certificate_watcher.h"
 #include "remoting/host/linux/pulse_audio_capturer.h"
@@ -187,7 +187,7 @@
 #include "remoting/host/pairing_registry_delegate_win.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/host_wtmpdb_logger.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -524,7 +524,7 @@ class HostProcess : public ConfigWatcher::Delegate,
   std::unique_ptr<AgentProcessBrokerClient> agent_process_broker_client_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -590,7 +590,7 @@ class HostProcess : public ConfigWatcher::Delegate,
   std::unique_ptr<FtlEchoMessageListener> ftl_echo_message_listener_;
 
   std::unique_ptr<HostEventLogger> host_event_logger_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<HostWtmpdbLogger> host_wtmpdb_logger_;
 #endif
   std::unique_ptr<HostPowerSaveBlocker> power_save_blocker_;
@@ -669,7 +669,7 @@ HostProcess::HostProcess(std::unique_ptr<ChromotingHos
       exit_code_out_(exit_code_out),
       shutdown_watchdog_(shutdown_watchdog) {
 #if BUILDFLAG(REMOTING_MULTI_PROCESS)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enable_peer_connection_process_ = multi_process_;
 #elif BUILDFLAG(IS_WIN)
   if (base::CommandLine::ForCurrentProcess()->HasSwitch(
@@ -955,7 +955,7 @@ void HostProcess::ShutdownOnNetworkThread() {
   DCHECK(context_->network_task_runner()->BelongsToCurrentThread());
   ProtobufHttpClient::SetCreateClientCertStoreCallback({});
   config_watcher_.reset();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   cert_watcher_.reset();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -1061,7 +1061,7 @@ void HostProcess::CreateAuthenticatorFactory() {
             context_->url_loader_factory(), service_account_email_,
             oauth_refresh_token_));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!cert_watcher_) {
       cert_watcher_ = std::make_unique<CertificateWatcher>(
           base::BindRepeating(&HostProcess::ShutdownHost,
@@ -1227,7 +1227,7 @@ void HostProcess::StartOnUiThread() {
       base::BindRepeating(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::BindRepeating(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // For multi-process hosts, `PulseAudioCapturer` will be initialized by the
   // desktop process.
   if (!multi_process_) {
@@ -1295,7 +1295,7 @@ void HostProcess::ShutdownOnUiThread() {
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1303,7 +1303,7 @@ void HostProcess::ShutdownOnUiThread() {
   PulseAudioCapturer::InitializePipeReader(nullptr);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   context_->input_task_runner()->PostTask(
       FROM_HERE,
       base::BindOnce([]() { delete ui::X11EventSource::GetInstance(); }));
@@ -1946,7 +1946,7 @@ void HostProcess::InitializeSignaling() {
   zombie_host_detector_ = std::make_unique<ZombieHostDetector>(base::BindOnce(
       &HostProcess::OnZombieStateDetected, base::Unretained(this)));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO: joedow - Remove Linux scope after this codepath has been stabilized.
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->HasSwitch(kEnableCorpMessaging)) {
@@ -2039,7 +2039,7 @@ void HostProcess::StartHost() {
 
   SetState(HOST_STARTED);
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   if (webrtc::DesktopCapturer::IsRunningUnderWayland()) {
     if (GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
       GnomeRemoteDesktopSession::GetInstance()->Init(
@@ -2226,7 +2226,7 @@ void HostProcess::StartHost() {
                           base::Unretained(this)),
       &local_session_policies_provider_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->HasSwitch(kEnableWtmpdb)) {
     host_wtmpdb_logger_ =
@@ -2264,7 +2264,7 @@ void HostProcess::StartHost() {
   // addresses.
   host_->Start(*host_owner_emails_.begin());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For Multi-process hosts and Mac, ChromotingHostServices connections are
   // handled by another process, then the message pipe is forwarded to the
   // network process.
@@ -2439,7 +2439,7 @@ int HostProcessMain(bool multi_process) {
                                                    : " (single-process)");
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_CHROMEOS)
   // For the multi-process host, screen capturing and UI rendering should be
   // done by the desktop process.
   if (!multi_process) {
@@ -2496,7 +2496,7 @@ int HostProcessMain(bool multi_process) {
   std::unique_ptr<net::NetworkChangeNotifier> network_change_notifier(
       net::NetworkChangeNotifier::CreateIfNeeded());
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
