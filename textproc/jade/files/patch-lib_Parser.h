--- lib/Parser.h~	1998-10-01 05:13:28 UTC
+++ lib/Parser.h
@@ -62,15 +62,15 @@ class Parser : private ParserState {  (public)
   Parser(const SgmlParser::Params &);
   Event *nextEvent();
   void parseAll(EventHandler &, const volatile sig_atomic_t *cancelPtr);
-  ParserState::sdPointer;
-  ParserState::instanceSyntaxPointer;
-  ParserState::prologSyntaxPointer;
-  ParserState::activateLinkType;
-  ParserState::allLinkTypesActivated;
-  ParserState::entityManager;
-  ParserState::entityCatalog;
-  ParserState::baseDtd;
-  ParserState::options;
+  using ParserState::sdPointer;
+  using ParserState::instanceSyntaxPointer;
+  using ParserState::prologSyntaxPointer;
+  using ParserState::activateLinkType;
+  using ParserState::allLinkTypesActivated;
+  using ParserState::entityManager;
+  using ParserState::entityCatalog;
+  using ParserState::baseDtd;
+  using ParserState::options;
 private:
   Parser(const Parser &);	// undefined
   void operator=(const Parser &); // undefined
