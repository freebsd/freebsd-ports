--- definitions.cxx.orig	Sat Oct 23 08:40:25 1999
+++ definitions.cxx	Fri Mar 19 01:43:37 2004
@@ -30,6 +30,8 @@
 # include <cmath>
 #endif // ENABLE_FLOATING_POINT
 
+using namespace std;
+
 const shstring &
 Latte_Lambda::name() const
 {
@@ -721,7 +723,7 @@
       throw InsufficientArgs(*this, loc);
 
     const Refcounter<Latte_Obj> &obj = *i++;
-    Latte_Str *refstr = obj->as_str();
+    const Latte_Str *refstr = obj->as_str();
 
     long argno = 0;
 
@@ -731,14 +733,14 @@
     while (i != args_end) {
       ++argno;
 
-      Latte_Str *newstr = (*i++)->as_str();
+      const Latte_Str *newstr = (*i++)->as_str();
 
       if (!newstr)
         throw BadType(*this, argno, loc);
 
       if (m_greater) {
         if (m_equal) {
-          if (!(*refstr >= *newstr))
+          if (!(refstr >= newstr))
             return latte_false();
         } else {
           if (!(*refstr > *newstr))
