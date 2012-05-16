--- GG/adobe/string.hpp.orig	2012-01-27 18:32:14.000000000 +0300
+++ GG/adobe/string.hpp	2012-01-27 18:34:30.000000000 +0300
@@ -257,7 +257,7 @@
     /*!
         Move constructor.
     */
-    string_t(move_from<string_t> x) : storage_m(move(x.source.storage_m)) { }
+  string_t(move_from<string_t> x) : storage_m(::adobe::move(x.source.storage_m)) { }
 
         /*!
                 Constructs a string_t from a regular C string (including string literals).
@@ -300,7 +300,7 @@
                 Assignment operator.
          */
 
-        string_t& operator=(string_t s) { storage_m = move(s.storage_m); return *this; }
+  string_t& operator=(string_t s) { storage_m = ::adobe::move(s.storage_m); return *this; }
 
         /*!
                 Conversion operator to std::string.
@@ -464,9 +464,9 @@
         Anything that can be concatenated using string_t::operator+=
         may also be concatenated to a string_t using operator+.
  */
-inline string_t operator+(string_t s1, const string_t& s2)     { return move(s1 += s2); }
-inline string_t operator+(string_t s1, const std::string& s2)  { return move(s1 += s2); }
-inline string_t operator+(string_t s1, const char* s2)         { return move(s1 += s2); }
+inline string_t operator+(string_t s1, const string_t& s2)     { return ::adobe::move(s1 += s2); }
+inline string_t operator+(string_t s1, const std::string& s2)  { return ::adobe::move(s1 += s2); }
+inline string_t operator+(string_t s1, const char* s2)         { return ::adobe::move(s1 += s2); }
 
 /*************************************************************************************************/
 
@@ -559,7 +559,7 @@
     /*!
         Move constructor.
          */
-    string16_t(move_from<string16_t> x) : storage_m(move(x.source.storage_m)) { }
+  string16_t(move_from<string16_t> x) : storage_m(::adobe::move(x.source.storage_m)) { }
 
         /*!
                 Constructs a string16_t from a null-terminated sequence of 16-bit elements.
@@ -595,7 +595,7 @@
                 Assignment operator.
          */
         string16_t& operator=(string16_t s)
-                { storage_m = move(s.storage_m); return *this; }
+  { storage_m = ::adobe::move(s.storage_m); return *this; }
         
         /*!
                 Returns const pointer to a null-terminated sequence of 16-bit elements, identical to
@@ -734,8 +734,8 @@
         may also be concatenated to a string16_t using operator+.
  */
 
-inline string16_t operator+(string16_t s1, const string16_t& s2)      { return move(s1 += s2); }
-inline string16_t operator+(string16_t s1, const boost::uint16_t* s2) { return move(s1 += s2); }
+inline string16_t operator+(string16_t s1, const string16_t& s2)      { return ::adobe::move(s1 += s2); }
+inline string16_t operator+(string16_t s1, const boost::uint16_t* s2) { return ::adobe::move(s1 += s2); }
 
 //!@}
 
