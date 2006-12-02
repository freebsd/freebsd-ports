--- GroupState.cpp.orig	Tue Mar 14 23:43:08 2000
+++ GroupState.cpp	Fri Dec  1 22:47:05 2006
@@ -24,6 +24,9 @@
 #include <stdlib.h>	// need getenv
 
 using std::string;
+using std::ifstream;
+using std::ofstream;
+using std::ios;
 
 GroupState::GroupState(const string& groupname, const string& max_msg_id)
 	: group(groupname)
