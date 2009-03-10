--- ./libs/libmythtv/cardutil.cpp.orig	2008-02-02 12:42:34.000000000 -0500
+++ ./libs/libmythtv/cardutil.cpp	2009-02-23 09:59:26.000000000 -0500
@@ -1473,7 +1473,7 @@
 {
     bool ok;
     QStringList ret;
-    int videofd = open(device.ascii(), O_RDWR);
+    int videofd = open(device.ascii(), O_RDONLY);
     if (videofd < 0)
     {
         ret += QObject::tr("Could not open '%1' "
