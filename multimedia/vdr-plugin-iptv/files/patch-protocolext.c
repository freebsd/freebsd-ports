--- a/protocolext.c
+++ b/protocolext.c
@@ -82,6 +82,7 @@ void cIptvProtocolExt::TerminateScript(v
           error("Script '%s' won't terminate - killing it!", *scriptFile);
           kill(pid, SIGKILL);
           }
+#ifdef linux
        // Clear wait status to make sure child exit status is accessible
        memset(&waitStatus, '\0', sizeof(waitStatus));
        // Wait for child termination
@@ -94,6 +95,17 @@ void cIptvProtocolExt::TerminateScript(v
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
