diff --git toolkit/xre/nsEmbedFunctions.cpp toolkit/xre/nsEmbedFunctions.cpp
index 9ce6af94637c..44165558f7ec 100644
--- toolkit/xre/nsEmbedFunctions.cpp
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -360,10 +360,12 @@ nsresult XRE_InitChildProcess(int aArgc, char* aArgv[],
           static_cast<CrashReporter::ProcessId>(*crashHelperPidArg);
 #endif  // defined(XP_LINUX) && !defined(MOZ_WIDGET_ANDROID)
 
+#if !defined(XP_FREEBSD)
       exceptionHandlerIsSet = CrashReporter::SetRemoteExceptionHandler(
           std::move(*crashReporterArg), crashHelperPid);
       MOZ_ASSERT(exceptionHandlerIsSet,
                  "Should have been able to set remote exception handler");
+#endif
 
       if (!exceptionHandlerIsSet) {
         // Bug 684322 will add better visibility into this condition
