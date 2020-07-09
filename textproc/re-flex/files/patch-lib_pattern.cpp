--- lib/pattern.cpp.orig	2020-07-09 08:32:41 UTC
+++ lib/pattern.cpp
@@ -2065,7 +2065,7 @@ void Pattern::encode_dfa(DFA::State *start)
     // add final dead state (HALT opcode) only when needed, i.e. skip dead state if all chars 0-255 are already covered
     if (hi <= 0xFF)
     {
-      state->edges[hi] = std::pair<Char,DFA::State*>(0xFF, reinterpret_cast<DFA::State*>(NULL));
+      state->edges[hi] = std::pair<Char,DFA::State*>(0xFF, nullptr);
       ++nop_;
     }
 #else
