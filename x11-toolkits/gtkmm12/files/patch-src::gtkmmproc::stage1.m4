--- src/gtkmmproc/stage1.m4.orig	Thu Feb 15 04:42:47 2001
+++ src/gtkmmproc/stage1.m4	Wed Oct 13 02:35:02 2004
@@ -198,7 +198,7 @@
 class __CPPNAME__; 
 class __CPPNAME__`'_Class; 
 }
-namespace Gtk { __NAMESPACE__::__CPPNAME__ *wrap (__CNAME__ *o); }
+namespace Gtk { template<> struct Wrap<__CNAME__> { typedef __NAMESPACE__::__CPPNAME__ CppType; }; }
 dnl
 dnl
 GTKMM_SECTION(PRIVATE)
