--- src/mgr/swmgr.cpp.org	Wed Dec 12 00:43:04 2001
+++ src/mgr/swmgr.cpp	Wed Dec 12 00:44:39 2001
@@ -268,21 +268,21 @@
 	}
 
 
-	// check for systemwide /etc/sword.conf
+	// check for systemwide _INSTDIR_/etc/sword.conf
 
 #ifndef __VISUALC__
 if (debug)
-	cerr << "\nChecking for /etc/sword.conf...";
+	cerr << "\nChecking for "_INSTDIR_"/etc/sword.conf...";
 #endif
 
-	if (!::access("/etc/sword.conf", 04)) {
+	if (!::access(_INSTDIR_"/etc/sword.conf", 04)) {
 
 #ifndef __VISUALC__
 if (debug)
 	cerr << "found\n";
 #endif
 
-		SWConfig etcconf("/etc/sword.conf");
+		SWConfig etcconf(_INSTDIR_"/etc/sword.conf");
 		if ((entry = etcconf.Sections["Install"].find("DataPath")) != etcconf.Sections["Install"].end()) {
 			path = (*entry).second;
 			if (((*entry).second.c_str()[strlen((*entry).second.c_str())-1] != '\\') && ((*entry).second.c_str()[strlen((*entry).second.c_str())-1] != '/'))
@@ -290,7 +290,7 @@
 
 #ifndef __VISUALC__
 if (debug)
-	cerr << "DataPath in /etc/sword.conf is set to: " << path;
+	cerr << "DataPath in "_INSTDIR_"/etc/sword.conf is set to: " << path;
 #endif
 
 #ifndef __VISUALC__
