--- src/DFA.cc.orig	2024-10-04 22:44:09 UTC
+++ src/DFA.cc
@@ -2,8 +2,6 @@
 
 #include "zeek/DFA.h"
 
-#include "zeek/zeek-config.h"
-
 #include "zeek/Desc.h"
 #include "zeek/EquivClass.h"
 #include "zeek/Hash.h"
@@ -265,9 +263,9 @@ DFA_State* DFA_State_Cache::Lookup(const NFA_state_lis
 DFA_State* DFA_State_Cache::Lookup(const NFA_state_list& nfas, DigestStr* digest) {
     // We assume that state ID's don't exceed 10 digits, plus
     // we allow one more character for the delimiter.
-    auto id_tag_buf = std::make_unique<u_char[]>(nfas.length() * 11 + 1);
+    auto id_tag_buf = std::make_unique<char[]>(nfas.length() * 11 + 1);
     auto id_tag = id_tag_buf.get();
-    u_char* p = id_tag;
+    char* p = id_tag;
 
     for ( int i = 0; i < nfas.length(); ++i ) {
         NFA_State* n = nfas[i];
@@ -287,7 +285,7 @@ DFA_State* DFA_State_Cache::Lookup(const NFA_state_lis
     // HashKey because the data is copied into the key.
     hash128_t hash;
     KeyedHash::Hash128(id_tag, p - id_tag, &hash);
-    *digest = DigestStr(reinterpret_cast<const unsigned char*>(hash), 16);
+    *digest = DigestStr(reinterpret_cast<const char*>(hash), 16);
 
     auto entry = states.find(*digest);
     if ( entry == states.end() ) {
