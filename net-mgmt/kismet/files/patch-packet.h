--- packet.h.orig	Wed Aug 18 18:56:26 2004
+++ packet.h	Wed Aug 18 18:56:43 2004
@@ -550,7 +550,7 @@
     // This isn't quite like STL iterators, because I'm too damned lazy to deal with all
     // the nasty STL hoop-jumping.  This does provide a somewhat-stl-ish interface to
     // iterating through the singleton and masked maps
-    friend class iterator {
+    class iterator {
         friend class macmap;
 
     public:
