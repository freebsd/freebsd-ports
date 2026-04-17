commit cf2fba7d3f8414cfc993b6a2d9ab01b43f6669d5
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    we need signal.h and BinaryPath.h

diff --git ipc/glue/ForkServer.cpp ipc/glue/ForkServer.cpp
index d18fab02d686..837d0ac62f40 100644
--- ipc/glue/ForkServer.cpp
+++ ipc/glue/ForkServer.cpp
@@ -22,12 +22,15 @@
 #include <string.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#if defined(XP_FREEBSD)
+#include <signal.h>
+#endif
 
 #if defined(XP_LINUX) && defined(MOZ_SANDBOX)
 #  include "mozilla/SandboxLaunch.h"
 #endif
 
-#if defined(XP_OPENBSD)
+#if defined(XP_OPENBSD) || defined(XP_FREEBSD)
 #  include "BinaryPath.h"
 #  include <err.h>
 #endif
@@ -76,7 +79,7 @@ ForkServer::ForkServer(int* aArgc, char*** aArgv) : mArgc(aArgc), mArgv(aArgv) {
  */
 static void ForkServerPreload(int& aArgc, char** aArgv) {
   Omnijar::ChildProcessInit(aArgc, aArgv);
-#if defined(XP_OPENBSD)
+#if defined(XP_OPENBSD) || defined(XP_FREEBSD)
   char binaryPath[MAXPATHLEN];
   nsresult rv = mozilla::BinaryPath::Get(binaryPath);
   if (NS_FAILED(rv)) {
