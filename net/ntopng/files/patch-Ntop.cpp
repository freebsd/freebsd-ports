--- Ntop.cpp.orig	2013-11-18 16:49:30.000000000 +0600
+++ Ntop.cpp	2013-11-18 16:50:51.000000000 +0600
@@ -89,12 +89,12 @@
 void Ntop::initTimezone() {
   /*
      Setup timezone differences
-
-     We call it all the time as daylight can change
-     during the night and thus we need to have it "fresh"
   */
-  tzset();
-  time_offset = timezone - (daylight * 3600);
+  time_t curtime;
+  struct tm *loctime;
+  curtime = time (NULL);
+  loctime = localtime (&curtime);
+  time_offset = loctime->tm_gmtoff;
 }
 
 /* ******************************************* */
