--- GroupState.h.orig	Tue Mar 14 23:43:08 2000
+++ GroupState.h	Fri Dec  1 22:47:53 2006
@@ -26,6 +26,7 @@
 
 using std::string;
 using std::map;
+using std::less;
 
 typedef map< string, string, less<string> > GroupStateData;
 typedef GroupStateData::value_type StatePair;
