--- ./contrib/olsr/tools/print_databases.cc.orig	2011-03-16 21:16:01.000000000 +0000
+++ ./contrib/olsr/tools/print_databases.cc	2014-02-26 21:17:13.000000000 +0000
@@ -161,7 +161,8 @@
 };
 
 void
-GetExternals::get(int argc, char *argv[])
+// GetExternals::get(int argc, char *argv[])
+GetExternals::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -172,8 +173,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get external route list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -309,7 +310,8 @@
 };
 
 void
-GetInterfaces::get(int argc, char *argv[])
+// GetInterfaces::get(int argc, char *argv[])
+GetInterfaces::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -320,8 +322,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get interface list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -476,7 +478,8 @@
 };
 
 void
-GetLinks::get(int argc, char *argv[])
+// GetLinks::get(int argc, char *argv[])
+GetLinks::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -487,8 +490,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get link list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -649,7 +652,8 @@
 };
 
 void
-GetMids::get(int argc, char *argv[])
+// GetMids::get(int argc, char *argv[])
+GetMids::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -660,8 +664,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get MID list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -803,7 +807,8 @@
 };
 
 void
-GetNeighbors::get(int argc, char *argv[])
+// GetNeighbors::get(int argc, char *argv[])
+GetNeighbors::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -814,8 +819,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get neighbor list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -979,7 +984,8 @@
 };
 
 void
-GetTopology::get(int argc, char *argv[])
+// GetTopology::get(int argc, char *argv[])
+GetTopology::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -990,8 +996,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get topology list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -1126,7 +1132,8 @@
 };
 
 void
-GetTwohopLinks::get(int argc, char *argv[])
+// GetTwohopLinks::get(int argc, char *argv[])
+GetTwohopLinks::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -1137,8 +1144,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get neighbor list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
@@ -1271,7 +1278,8 @@
 };
 
 void
-GetTwohopNeighbors::get(int argc, char *argv[])
+// GetTwohopNeighbors::get(int argc, char *argv[])
+GetTwohopNeighbors::get(int, char *[])
 {
     XrlOlsr4V0p1Client cl(&this->_xr);
 
@@ -1283,8 +1291,8 @@
     if (! success)
 	XLOG_WARNING("Failed to get two-hop neighbor list.");
 
-    UNUSED(argc);
-    UNUSED(argv);
+    // UNUSED(argc);
+    // UNUSED(argv);
 }
 
 void
