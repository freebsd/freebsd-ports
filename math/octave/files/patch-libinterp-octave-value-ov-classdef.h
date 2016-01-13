--- libinterp/octave-value/ov-classdef.h.orig	2015-07-21 17:04:55.000000000 +0900
+++ libinterp/octave-value/ov-classdef.h	2015-07-21 17:05:32.000000000 +0900
@@ -438,7 +438,7 @@
 
   void mark_as_constructed (void) { ctor_list.clear (); }
 
-  void mark_as_constructed (const cdef_class& cls) { ctor_list.erase (cls); }
+  void mark_as_constructed (const cdef_class& cls);
 
   bool is_constructed (void) const { return ctor_list.empty (); }
 
