--- libs/libmythtv/cardutil.cpp~	Tue Jul 18 22:05:04 2006
+++ libs/libmythtv/cardutil.cpp	Fri Feb 23 11:40:25 2007
@@ -588,7 +588,7 @@
 {
     bool ok;
     QStringList ret;
-    int videofd = open(device.ascii(), O_RDWR);
+    int videofd = open(device.ascii(), O_RDONLY);
     if (videofd < 0)
     {
         ret += QObject::tr("Could not open '%1' "
