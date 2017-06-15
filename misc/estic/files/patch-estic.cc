--- estic/estic.cc.orig	1997-03-05 20:20:42 UTC
+++ estic/estic.cc
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
