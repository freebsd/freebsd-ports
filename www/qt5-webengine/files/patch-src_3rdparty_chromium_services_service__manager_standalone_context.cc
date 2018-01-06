--- src/3rdparty/chromium/services/service_manager/standalone/context.cc.orig	2017-01-26 00:49:17 UTC
+++ src/3rdparty/chromium/services/service_manager/standalone/context.cc
@@ -208,7 +208,7 @@ void Context::Init(std::unique_ptr<InitP
       tracing::mojom::StartupPerformanceDataCollectorPtr collector;
       ConnectToInterface(service_manager(), source_identity, tracing_identity,
                          &collector);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       // CurrentProcessInfo::CreationTime is only defined on some platforms.
       const base::Time creation_time = base::CurrentProcessInfo::CreationTime();
       collector->SetServiceManagerProcessCreationTime(
