--- ./psimedia.pro.orig	2009-03-05 05:01:58.000000000 +0300
+++ ./psimedia.pro	2010-09-05 02:14:12.705470018 +0400
@@ -1,6 +1,13 @@
 TEMPLATE = subdirs
 
-SUBDIRS += gstprovider/gstelements/static
-SUBDIRS += demo
+sub_gstelements.subdir = gstprovider/gstelements/static
 
-SUBDIRS += gstprovider
+sub_demo.subdir = demo
+
+sub_gstprovider.subdir = gstprovider
+sub_gstprovider.depends = sub_gstelements
+
+SUBDIRS += sub_gstelements
+# SUBDIRS += sub_demo
+
+SUBDIRS += sub_gstprovider
