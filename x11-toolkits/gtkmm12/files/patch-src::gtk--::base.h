--- src/gtk--/base.h.orig	Tue Nov 14 21:23:11 2000
+++ src/gtk--/base.h	Wed Oct 13 05:01:59 2004
@@ -99,12 +99,10 @@
 
 /* Translating API */
 
-/*
 // used to give error on unwrapped types; connect Gtk-- crew
-template <class C> struct NotWrapped;
+template <class C> struct NotWrapped {typedef void Type;};
 // hook for C => C++ translation
 template <class C> struct Wrap {typedef typename NotWrapped<C>::Type CppType;};
-*/
 
 class Object;
 class ObjectClass;
@@ -118,19 +116,19 @@
 
 // Request a specific wrapper for an object.
 template <class Cpp>
-Cpp* wrap_new(typename Cpp::BaseObjectType* o)
+inline Cpp* wrap_new(typename Cpp::BaseObjectType* o)
   {
    return (typename Cpp::CppClassType::wrap_new(o));
   }
 
 // interface to gtk--
-/* 
+ 
 template <class C>
-typename Wrap<C>::CppType* wrap(C* o)
+inline typename Wrap<C>::CppType* wrap(C* o)
   {
     return dynamic_cast<typename Wrap<C>::CppType*>(wrap_auto((GtkObject*)(o)));
   }
-*/
+
 
 /********************************************************************/
 
