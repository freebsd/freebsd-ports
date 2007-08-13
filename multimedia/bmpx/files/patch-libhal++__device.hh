--- ./libhal++/device.hh.orig	2007-08-08 21:48:40.000000000 +0200
+++ ./libhal++/device.hh	2007-08-08 21:48:51.000000000 +0200
@@ -60,11 +60,7 @@
 
               inline bool operator==(iterator const& other)
               {
-#ifdef HAVE_HAL_058
                 return ((i.idx == other.i.idx) && (i.set == other.i.set));
-#else
-                return ((i.index == other.i.index) && (i.set == other.i.set));
-#endif // HAVE_HAL_058
               }
 
               inline bool operator!=(iterator const& other)
