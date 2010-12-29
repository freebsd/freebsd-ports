--- ./xbmc/ProgramDatabase.cpp.orig	2010-07-12 22:53:38.000000000 +0200
+++ ./xbmc/ProgramDatabase.cpp	2010-12-01 12:17:34.231763652 +0100
@@ -63,7 +63,7 @@
   catch (...)
   {
     CLog::Log(LOGERROR, "programdatabase::unable to create tables:%u",
-              GetLastError());
+              (unsigned int)GetLastError());
     return false;
   }
 
