--- vdr.c.orig	2026-09-26 17:58:30 UTC
+++ vdr.c
@@ -29,12 +29,16 @@
 #include <grp.h>
 #include <langinfo.h>
 #include <locale.h>
+#ifdef __GLIBC__
 #include <malloc.h>
+#endif
 #include <pwd.h>
 #include <signal.h>
 #include <stdlib.h>
+#ifdef __linux__
 #include <sys/capability.h>
 #include <sys/prctl.h>
+#endif
 #ifdef SDNOTIFY
 #include <systemd/sd-daemon.h>
 #endif
@@ -116,8 +120,10 @@ static bool SetUser(const char *User, bo
         fprintf(stderr, "vdr: cannot set user id %u: %s\n", (unsigned int)user->pw_uid, strerror(errno));
         return false;
         }
+#ifdef __linux__
      if (UserDump && prctl(PR_SET_DUMPABLE, 1, 0, 0, 0) < 0)
         fprintf(stderr, "vdr: warning - cannot set dumpable: %s\n", strerror(errno));
+#endif
      setenv("HOME", user->pw_dir, 1);
      setenv("USER", user->pw_name, 1);
      setenv("LOGNAME", user->pw_name, 1);
@@ -126,6 +132,8 @@ static bool SetUser(const char *User, bo
   return true;
 }
 
+#ifdef __linux__
+
 static bool DropCaps(void)
 {
   // drop all capabilities except selected ones
@@ -169,6 +177,20 @@ static bool SetKeepCaps(bool On)
   return true;
 }
 
+#else // capabilities are Linux specific
+
+static bool DropCaps(void)
+{
+  return true;
+}
+
+static bool SetKeepCaps(bool On)
+{
+  return true;
+}
+
+#endif
+
 static void SignalHandler(int signum)
 {
   switch (signum) {
@@ -1659,7 +1681,9 @@ int main(int argc, char *argv[])
               // Memory cleanup:
               static time_t LastMemoryCleanup = 0;
               if ((Now - LastMemoryCleanup) > MEMCLEANUPDELTA) {
+#ifdef __GLIBC__
                  malloc_trim(0);
+#endif
                  LastMemoryCleanup = Now;
                  }
               }
@@ -1715,7 +1739,7 @@ Exit:
   if (WatchdogTimeout > 0)
      dsyslog("max. latency time %d seconds", MaxLatencyTime);
   if (LastSignal)
-     isyslog("caught signal %d", LastSignal);
+     isyslog("caught signal %d", int(LastSignal));
   if (ShutdownHandler.EmergencyExitRequested())
      esyslog("emergency exit!");
   isyslog("exiting, exit code %d", ShutdownHandler.GetExitCode());
