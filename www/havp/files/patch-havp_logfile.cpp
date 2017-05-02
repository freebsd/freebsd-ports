--- havp/logfile.cpp.orig	2016-06-27 14:16:19.640229000 +0300
+++ havp/logfile.cpp		2016-06-27 14:25:01.272114000 +0300
@@ -52,7 +52,10 @@
         SyslogLevel = GetSyslogLevel();
         SyslogVirusLevel = GetSyslogVirusLevel();
 
-        openlog(Params::GetConfigString("SYSLOGNAME").c_str(), LOG_CONS | LOG_PID, GetSyslogFacility());
+        // FreeBSD don't copy ident, only pointer to ident. So we need store ident itself
+        static string SyslogName;
+        SyslogName = Params::GetConfigString("SYSLOGNAME");
+        openlog(SyslogName.c_str(), LOG_CONS | LOG_PID, GetSyslogFacility());
 
         return true;
     }
