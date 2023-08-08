--- scribus/desaxe/digester.cpp.orig	2023-07-31 21:07:27 UTC
+++ scribus/desaxe/digester.cpp
@@ -448,7 +448,11 @@ automata::NFA<nfa_state_t, token_t>* RuleState::create
 	return nfa;
 }
 
+#if __cplusplus >= 201703L // ISO C++ 2017 or newer.
+struct CreateDFAState : public std::__unary_function <std::set<nfa_state_t>, dfa_state_t> {
+#else
 struct CreateDFAState : public std::unary_function <std::set<nfa_state_t>, dfa_state_t> {
+#endif
 
 	CreateDFAState(const std::vector<rule_t>& rules, const std::vector<nfa_state_t>& accepting) 
 	: n(0), rules_(rules), accepting_(accepting) 
