--- libk3b/projects/datacd/k3bdatajob.cpp.orig	Tue Jul 12 14:56:13 2005
+++ libk3b/projects/datacd/k3bdatajob.cpp	Tue Jul 12 14:56:35 2005
@@ -98,8 +98,8 @@
 
 K3bDataJob::~K3bDataJob()
 {
-  delete d;
   delete d->tocFile;
+  delete d;
 }
 
 
