--- scribus/desaxe/digester.cpp.orig	2023-07-26 15:32:48 UTC
+++ scribus/desaxe/digester.cpp
@@ -448,7 +448,7 @@ automata::NFA<nfa_state_t, token_t>* RuleState::create
 	return nfa;
 }
 
-struct CreateDFAState : public std::unary_function <std::set<nfa_state_t>, dfa_state_t> {
+struct CreateDFAState : public std::__unary_function <std::set<nfa_state_t>, dfa_state_t> {
 
 	CreateDFAState(const std::vector<rule_t>& rules, const std::vector<nfa_state_t>& accepting) 
 	: n(0), rules_(rules), accepting_(accepting) 
