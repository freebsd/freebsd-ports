--- xbmc/programs/ProgramDatabase.cpp.orig
+++ xbmc/programs/ProgramDatabase.cpp
@@ -63,7 +63,7 @@
   catch (...)
   {
     CLog::Log(LOGERROR, "programdatabase::unable to create tables:%u",
-              GetLastError());
+              (unsigned int)GetLastError());
     return false;
   }
 
