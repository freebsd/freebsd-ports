--- src/DFA.h.orig	2024-10-04 22:44:09 UTC
+++ src/DFA.h
@@ -2,7 +2,7 @@
 
 #pragma once
 
-#include <sys/types.h> // for u_char
+#include <sys/types.h>
 #include <cassert>
 #include <map>
 #include <string>
@@ -18,7 +18,7 @@ class DFA_Machine;
 
 // Transitions to the uncomputed state indicate that we haven't yet
 // computed the state to go to.
-#define DFA_UNCOMPUTED_STATE -2
+#define DFA_UNCOMPUTED_STATE (-2)
 #define DFA_UNCOMPUTED_STATE_PTR ((DFA_State*)DFA_UNCOMPUTED_STATE)
 
 class DFA_State : public Obj {
@@ -67,7 +67,7 @@ class DFA_State : public Obj { (protected)
     DFA_State* mark;
 };
 
-using DigestStr = std::basic_string<u_char>;
+using DigestStr = std::string;
 
 struct DFA_State_Cache_Stats {
     // Sum of all NFA states
