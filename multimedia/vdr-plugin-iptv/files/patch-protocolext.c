--- a/protocolext.c
+++ b/protocolext.c
@@ -55,10 +55,17 @@ void cIptvProtocolExt::ExecuteScript(voi
      // Execute the external script
      cString cmd = cString::sprintf("%s %d %d", *scriptFile, scriptParameter, socketPort);
      debug("cIptvProtocolExt::ExecuteScript(child): %s\n", *cmd);
+#ifdef linux
      if (execl("/bin/bash", "sh", "-c", *cmd, (char *)NULL) == -1) {
         error("Script execution failed: %s", *cmd);
         _exit(-1);
         }
+#else
+     if (execl("/bin/sh", "sh", "-c", *cmd, (char *)NULL) == -1) {
+        error("Script execution failed: %s", *cmd);
+        _exit(-1);
+        }
+#endif
      _exit(0);
      }
   else {
@@ -86,6 +93,7 @@ void cIptvProtocolExt::TerminateScript(v
           error("Script '%s' won't terminate - killing it!", *scriptFile);
           kill(pid, SIGKILL);
           }
+#ifdef linux
        // Clear wait status to make sure child exit status is accessible
        memset(&waitStatus, '\0', sizeof(waitStatus));
        // Wait for child termination
@@ -98,6 +106,17 @@ void cIptvProtocolExt::TerminateScript(v
           debug("Child (%d) exited as expected\n", pid);
           waitOver = true;
           }
+#else
+       int status = 0;
+       retval = waitpid(pid, &status, (WNOHANG));
+       ERROR_IF_RET(retval < 0, "waitid()", waitOver = true);
+       // These are the acceptable conditions under which child exit is
+       // regarded as successful
+       if (!retval && (WIFEXITED(status) || WIFSIGNALED(status))) {
+          debug("Child (%d) exited as expected\n", pid);
+          waitOver = true;
+          }
+#endif
        // Unsuccessful wait, avoid busy looping
        if (!waitOver)
           cCondWait::SleepMs(timeoutms);
