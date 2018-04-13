# https://bugs.squid-cache.org/show_bug.cgi?id=4822
# https://patch-diff.githubusercontent.com/raw/squid-cache/squid/pull/158.patch

--- src/ipc/Kid.cc.orig	2018-02-22 18:34:42 UTC
+++ src/ipc/Kid.cc
@@ -90,7 +90,9 @@ Kid::reportStopped() const
     if (hopeless() && Config.hopelessKidRevivalDelay) {
         syslog(LOG_NOTICE, "Squid Parent: %s process %d will not be restarted for %ld "
                "seconds due to repeated, frequent failures",
-               theName.termedBuf(), pid, Config.hopelessKidRevivalDelay);
+               theName.termedBuf(),
+               pid,
+               static_cast<long int>(Config.hopelessKidRevivalDelay));
     }
 }
 
