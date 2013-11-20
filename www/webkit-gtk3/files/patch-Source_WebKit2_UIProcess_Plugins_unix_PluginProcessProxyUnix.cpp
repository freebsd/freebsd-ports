--- Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp.orig	2013-06-10 07:21:09.000000000 +0000
+++ Source/WebKit2/UIProcess/Plugins/unix/PluginProcessProxyUnix.cpp	2013-06-10 07:29:32.000000000 +0000
@@ -78,19 +78,23 @@ bool PluginProcessProxy::scanPlugin(cons
     // As a consequence, we make sure that the disposition is set to
     // SIG_DFL before calling g_spawn_sync().
     struct sigaction action;
+#if defined(SIGCLD)
     sigaction(SIGCLD, 0, &action);
     if (action.sa_handler == SIG_IGN) {
         action.sa_handler = SIG_DFL;
         sigaction(SIGCLD, &action, 0);
     }
+#endif
 
     if (!g_spawn_sync(0, argv, 0, G_SPAWN_STDERR_TO_DEV_NULL, 0, 0, &stdOut, 0, &status, 0))
         return false;
 
+#if defined(WEXITSTATUS)
     if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS || !stdOut) {
         free(stdOut);
         return false;
     }
+#endif
 
     String stdOutString(reinterpret_cast<const UChar*>(stdOut));
     free(stdOut);
