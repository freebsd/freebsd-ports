--- ./chrome/browser/ui/gtk/accelerators_gtk.h.orig	2014-04-24 22:34:59.000000000 +0200
+++ ./chrome/browser/ui/gtk/accelerators_gtk.h	2014-04-24 23:23:43.000000000 +0200
@@ -10,6 +10,8 @@
 #include "base/containers/hash_tables.h"
 #include "ui/base/accelerators/accelerator.h"
 
+#include <vector>
+
 template <typename T> struct DefaultSingletonTraits;
 
 class AcceleratorsGtk {
