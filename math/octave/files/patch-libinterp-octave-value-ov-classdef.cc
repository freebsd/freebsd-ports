--- libinterp/octave-value/ov-classdef.cc.orig	2015-07-21 17:05:21.000000000 +0900
+++ libinterp/octave-value/ov-classdef.cc	2015-07-21 17:05:32.000000000 +0900
@@ -1937,6 +1937,11 @@
   return true;
 }
 
+void cdef_object_scalar::mark_as_constructed (const cdef_class& cls)
+{
+  ctor_list.erase (cls);
+}
+
 handle_cdef_object::~handle_cdef_object (void)
 {
 #if DEBUG_TRACE
