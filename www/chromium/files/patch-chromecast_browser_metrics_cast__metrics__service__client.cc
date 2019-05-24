--- chromecast/browser/metrics/cast_metrics_service_client.cc.orig	2019-04-30 22:22:40 UTC
+++ chromecast/browser/metrics/cast_metrics_service_client.cc
@@ -40,9 +40,9 @@
 #include "content/public/common/content_switches.h"
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chromecast/browser/metrics/external_metrics.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
 #include "chromecast/base/android/dumpstate_writer.h"
@@ -62,10 +62,10 @@ const char kMetricsOldClientID[] = "user_experience_me
 const char kClientIdName[] = "Client ID";
 #else
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kExternalUmaEventsRelativePath[] = "metrics/uma-events";
 const char kPlatformUmaEventsPath[] = "/data/share/chrome/metrics/uma-events";
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 const struct ChannelMap {
   const char* chromecast_channel;
@@ -280,19 +280,19 @@ CastMetricsServiceClient::CastMetricsServiceClient(
     scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory)
     : pref_service_(pref_service),
       client_info_loaded_(false),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       external_metrics_(nullptr),
       platform_metrics_(nullptr),
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
       task_runner_(base::ThreadTaskRunnerHandle::Get()),
       url_loader_factory_(url_loader_factory) {
 }
 
 CastMetricsServiceClient::~CastMetricsServiceClient() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DCHECK(!external_metrics_);
   DCHECK(!platform_metrics_);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 void CastMetricsServiceClient::OnApplicationNotIdle() {
@@ -300,13 +300,13 @@ void CastMetricsServiceClient::OnApplicationNotIdle() 
 }
 
 void CastMetricsServiceClient::ProcessExternalEvents(const base::Closure& cb) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   external_metrics_->ProcessExternalEvents(
       base::Bind(&ExternalMetrics::ProcessExternalEvents,
                  base::Unretained(platform_metrics_), cb));
 #else
   cb.Run();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 void CastMetricsServiceClient::SetForceClientId(
@@ -371,7 +371,7 @@ void CastMetricsServiceClient::Initialize() {
   if (IsReportingEnabled())
     metrics_service_->Start();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Start external metrics collection, which feeds data from external
   // processes into the main external metrics.
   external_metrics_ = new ExternalMetrics(
@@ -381,7 +381,7 @@ void CastMetricsServiceClient::Initialize() {
   platform_metrics_ =
       new ExternalMetrics(stability_provider, kPlatformUmaEventsPath);
   platform_metrics_->Start();
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 void CastMetricsServiceClient::Finalize() {
@@ -390,14 +390,14 @@ void CastMetricsServiceClient::Finalize() {
   metrics_service_->RecordCompletedSessionEnd();
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Stop metrics service cleanly before destructing CastMetricsServiceClient.
   // The pointer will be deleted in StopAndDestroy().
   external_metrics_->StopAndDestroy();
   external_metrics_ = nullptr;
   platform_metrics_->StopAndDestroy();
   platform_metrics_ = nullptr;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
   metrics_service_->Stop();
 }
 
