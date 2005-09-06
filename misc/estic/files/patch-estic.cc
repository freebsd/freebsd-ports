--- estic/estic.cc.orig	Wed Mar  5 21:20:42 1997
+++ estic/estic.cc	Tue Sep  6 09:54:21 2005
@@ -80,9 +80,9 @@
 
 
 // Diag mode update
-static const duOff              = 0;
-static const duOn               = 1;
-static const duAuto             = 2;    // Update if version <= 1.93
+static const int duOff              = 0;
+static const int duOn               = 1;
+static const int duAuto             = 2;    // Update if version <= 1.93
 
 static const char VersionStr [] = "1.50";
 static const char VersionID []  = "ESTIC-Version";
