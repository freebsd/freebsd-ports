--- latte-string.h.orig	Fri Oct 22 13:03:49 1999
+++ latte-string.h	Fri Mar 19 01:17:52 2004
@@ -33,20 +33,20 @@
 
 #ifdef latte_use_intrinsic_string
 
-typedef string latte_string;
+typedef std::string latte_string;
 
 #else // latte_use_intrinsic_string
 
-class latte_string : public string {
+class latte_string : public std::string {
  public:
   latte_string() {}
-  latte_string(const char *str) : string(str) {}
-  latte_string(const char *str, size_t n) : string(str, n) {}
-  latte_string(const string &other) : string(other) {}
+  latte_string(const char *str) : std::string(str) {}
+  latte_string(const char *str, size_t n) : std::string(str, n) {}
+  latte_string(const std::string &other) : std::string(other) {}
 
 # ifdef HAVE_TWO_ITERATOR_STRING_CTOR
   latte_string(const const_iterator &a, const const_iterator &b) :
-    string(a, b) {}
+    std::string(a, b) {}
 # else // HAVE_TWO_ITERATOR_STRING_CTOR
   latte_string(const const_iterator &a, const const_iterator &b) {
     for (const_iterator i = a; i != b; ++i)
@@ -59,9 +59,9 @@
 #endif // USE_STRING_REMOVE
 };
 
-#include <iostream.h>
+#include <iostream>
 
-extern ostream &operator << (ostream &, const latte_string &);
+extern std::ostream &operator << (std::ostream &, const latte_string &);
 
 extern bool operator < (const latte_string &, const latte_string &);
 extern bool operator == (const latte_string &, const latte_string &);
