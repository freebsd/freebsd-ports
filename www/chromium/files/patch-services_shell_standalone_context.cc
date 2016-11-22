--- services/shell/standalone/context.cc.orig	2016-10-06 04:02:24.000000000 +0300
+++ services/shell/standalone/context.cc	2016-10-23 13:44:14.656275000 +0300
@@ -198,7 +198,7 @@
     tracing_remote_interfaces->GetInterface(
         tracing::mojom::StartupPerformanceDataCollector::Name_,
         mojo::GetProxy(&collector).PassMessagePipe());
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     // CurrentProcessInfo::CreationTime is only defined on some platforms.
     const base::Time creation_time = base::CurrentProcessInfo::CreationTime();
     collector->SetShellProcessCreationTime(creation_time.ToInternalValue());
