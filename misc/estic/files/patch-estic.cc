--- estic/estic.cc.orig	Sat Feb 26 18:28:17 2000
+++ estic/estic.cc	Sat Feb 26 18:28:51 2000
@@ -75,9 +75,9 @@
 
 
 // Diag mode update
-static const duOff		= 0;
-static const duOn		= 1;
-static const duAuto		= 2;	// Update if version <= 1.93
+static const int duOff		= 0;
+static const int duOn		= 1;
+static const int duAuto		= 2;	// Update if version <= 1.93
 
 static const char VersionStr [] = "1.30";	// Also valid for 1.40
 static const char VersionID []	= "ESTIC-Version";
