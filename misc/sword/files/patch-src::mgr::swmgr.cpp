--- src/mgr/swmgr.cpp.orig	Tue May 22 22:05:15 2001
+++ src/mgr/swmgr.cpp	Tue May 22 22:05:53 2001
@@ -263,25 +263,25 @@
 	}
 
 
-	// check for systemwide /etc/sword.conf
+	// check for systemwide /usr/local/etc/sword.conf
 
 if (debug)
-	cerr << "\nChecking for /etc/sword.conf...";
+	cerr << "\nChecking for /usr/local/etc/sword.conf...";
 
-	if ((fd = ::open("/etc/sword.conf", O_RDONLY)) > 0) {
+	if ((fd = ::open("/usr/local/etc/sword.conf", O_RDONLY)) > 0) {
 		::close(fd);
 
 if (debug)
 	cerr << "found\n";
 
-		SWConfig etcconf("/etc/sword.conf");
+		SWConfig etcconf("/usr/local/etc/sword.conf");
 		if ((entry = etcconf.Sections["Install"].find("DataPath")) != etcconf.Sections["Install"].end()) {
 			path = (*entry).second;
 			if (((*entry).second.c_str()[strlen((*entry).second.c_str())-1] != '\\') && ((*entry).second.c_str()[strlen((*entry).second.c_str())-1] != '/'))
 				path += "/";
 
 if (debug)
-	cerr << "DataPath in /etc/sword.conf is set to: " << path;
+	cerr << "DataPath in /usr/local/etc/sword.conf is set to: " << path;
 
 if (debug)
 	cerr << "\nChecking for mods.conf in DataPath ";
