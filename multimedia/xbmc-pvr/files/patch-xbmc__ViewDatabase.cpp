--- ./xbmc/ViewDatabase.cpp.orig	2010-07-03 13:07:36.000000000 +0200
+++ ./xbmc/ViewDatabase.cpp	2010-12-01 12:17:34.233780060 +0100
@@ -62,7 +62,7 @@
   catch (...)
   {
     CLog::Log(LOGERROR, "%s unable to create tables:%u",
-              __FUNCTION__, GetLastError());
+              __FUNCTION__, (unsigned int)GetLastError());
     return false;
   }
 
