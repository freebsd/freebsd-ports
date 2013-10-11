--- chrome/browser/ui/gtk/accelerators_gtk.h.orig	2013-09-28 19:10:31.000000000 +0200
+++ chrome/browser/ui/gtk/accelerators_gtk.h	2013-10-11 13:42:01.000000000 +0200
@@ -8,6 +8,8 @@
 #include "base/containers/hash_tables.h"
 #include "ui/base/accelerators/accelerator.h"
 
+#include <vector>
+
 template <typename T> struct DefaultSingletonTraits;
 
 class AcceleratorsGtk {
