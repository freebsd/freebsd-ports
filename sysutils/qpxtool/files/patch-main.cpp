--- main.cpp.orig	Tue Mar 14 22:31:43 2006
+++ main.cpp	Thu Mar 23 05:00:58 2006
@@ -34,8 +34,8 @@
 	printf("\n QPxTool-%s\n (c) 2005-2006, Gennady \"ShultZ\" Kozlov",VERSION);
 	printf("\n________________________________________");
 	uname(&sys);
-	printf("\nOS name : %s\nnode    : %s\nrelease : %s\nversion : %s\nmachine : %s\ndomain  : %s",
-		sys.sysname, sys.nodename, sys.release, sys.version, sys.machine, sys.domainname);
+	printf("\nOS name : %s\nnode    : %s\nrelease : %s\nversion : %s\nmachine : %s",
+		sys.sysname, sys.nodename, sys.release, sys.version, sys.machine);
 	printf("\n________________________________________\n");
 
 	QApplication QPT(argc,argv);
