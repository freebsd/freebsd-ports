--- shstring.h.orig	Fri Oct 22 13:04:38 1999
+++ shstring.h	Fri Mar 19 01:17:52 2004
@@ -26,7 +26,7 @@
 
 #include <latte-string.h>
 #include <functional>
-#include <iostream.h>
+#include <iostream>
 
 #include <refcount.h>
 
@@ -38,7 +38,7 @@
   shstring();
   shstring(const char *);
   shstring(const char *, size_t);
-  shstring(const string &);
+  shstring(const std::string &);
   shstring(const shstring &);
   shstring(const const_iterator &, const const_iterator &);
 
@@ -51,7 +51,10 @@
   bool empty() const { return null() || rep->empty(); }
 
   bool operator < (const shstring &) const;
+  bool operator <= (const shstring &) const;
   bool operator == (const shstring &other) const;
+  bool operator > (const shstring &) const;
+  bool operator >= (const shstring &) const;
 
   iterator begin() { return rep->begin(); }
   const_iterator begin() const { return rep->begin(); }
@@ -69,24 +72,24 @@
    public:
     Rep(const char *);
     Rep(const char *, size_t);
-    Rep(const string &);
-    Rep(const string::const_iterator &,
-	const string::const_iterator &);
+    Rep(const std::string &);
+    Rep(const std::string::const_iterator &,
+	const std::string::const_iterator &);
 
     latte_string &str() { return *this; }
     const latte_string &str() const { return *this; }
 
    private:
-    friend ostream &operator << (ostream &, const shstring &);
+    friend std::ostream &operator << (std::ostream &, const shstring &);
     friend class shstring;
   };
 
   Refcounter<Rep> rep;
 
-  friend ostream &operator << (ostream &, const shstring &);
+  friend std::ostream &operator << (std::ostream &, const shstring &);
 };
 
-extern ostream &
-operator << (ostream &, const shstring &);
+extern std::ostream &
+operator << (std::ostream &, const shstring &);
 
 #endif // SHSTRING_H
