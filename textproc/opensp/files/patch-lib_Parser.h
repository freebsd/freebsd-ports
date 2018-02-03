--- lib/Parser.h.orig	2005-07-21 14:05:17 UTC
+++ lib/Parser.h
@@ -62,16 +62,16 @@ class Parser : private ParserState {  (public)
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
-  ParserState::instantiateDtd;
+  using ParserState::sdPointer;
+  using ParserState::instanceSyntaxPointer;
+  using ParserState::prologSyntaxPointer;
+  using ParserState::activateLinkType;
+  using ParserState::allLinkTypesActivated;
+  using ParserState::entityManager;
+  using ParserState::entityCatalog;
+  using ParserState::baseDtd;
+  using ParserState::options;
+  using ParserState::instantiateDtd;
   friend class PiAttspecParser;
 private:
   Parser(const Parser &);	// undefined
