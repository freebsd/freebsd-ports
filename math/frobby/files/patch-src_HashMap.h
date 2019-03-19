--- src/HashMap.h.orig	2018-09-05 21:12:33 UTC
+++ src/HashMap.h
@@ -34,55 +34,10 @@
 template<class Key>
 class FrobbyHash {};
 
-// *********************************************************
-#ifdef __GNUC__ // Only GCC defines this macro
-#include "hash_map/hash_map"
-#include <string>
-
-template<>
-class FrobbyHash<string> : public __gnu_cxx::hash<string> {
-};
-
-template<class Key, class Value>
-class HashMap : public __gnu_cxx::hash_map<Key, Value,
-  FrobbyHash<Key> > {
-};
-
-#else
-
-// *********************************************************
-#ifdef _MSC_VER // Only Microsoft C++ defines this macro
-#include <hash_map>
-#include <string>
-
-template<class Key>
-class HashWrapper : public stdext::hash_compare<Key, ::std::less<Key> >, FrobbyHash<Key> {
-public:
-  size_t operator()(const Key& key) const {
-    return FrobbyHash<typename Key>::operator()(key);
-  }
-
-  bool operator()(const Key& a, const Key& b) const {
-    return stdext::hash_compare<Key, ::std::less<Key> >::operator()(a, b);
-  }
-};
-
-template<>
-class HashWrapper<string> : public stdext::hash_compare<string, ::std::less<string> > {
-};
-
-template<class Key, class Value>
-class HashMap : public stdext::hash_map<Key, Value, HashWrapper<Key> > {
-};
-
-// *********************************************************
-#else // Fall-back for unknown compilers
 #include <map>
 template<class Key, class Value>
 class HashMap : public std::map<Key, Value> {
 };
-#endif
-#endif
 
 
 #endif
