--- libs/libmythui/mythrender_vdpau.cpp.orig	2010-03-10 09:03:29.000000000 +0100
+++ libs/libmythui/mythrender_vdpau.cpp	2010-04-06 18:25:49.000000000 +0200
@@ -2005,9 +2005,9 @@
     if (!surfaces_owned)
         return;
 
-    VERBOSE(VB_IMPORTANT, LOC +
-        QString("Attempting to reset %1 video surfaces owned by this thread %2")
-            .arg(surfaces_owned).arg(this_thread));
+    //VERBOSE(VB_IMPORTANT, LOC +
+    //    QString("Attempting to reset %1 video surfaces owned by this thread %2")
+    //        .arg(surfaces_owned).arg(this_thread));
 
     // update old surfaces to map old vdpvideosurface to new vdpvideosurface
     QHash<uint, uint>::iterator old;
