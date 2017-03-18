--- services/service_manager/standalone/context.cc.orig	2017-03-09 20:04:36 UTC
+++ services/service_manager/standalone/context.cc
@@ -218,7 +218,7 @@ void Context::Init(std::unique_ptr<InitP
       tracing::mojom::StartupPerformanceDataCollectorPtr collector;
       BindInterface(service_manager(), source_identity, tracing_identity,
                     &collector);
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       // CurrentProcessInfo::CreationTime is only defined on some platforms.
       const base::Time creation_time = base::CurrentProcessInfo::CreationTime();
       collector->SetServiceManagerProcessCreationTime(
