--- Source/WebCore/xml/XPathGrammar.y.orig	2011-08-06 10:38:59.000000000 +0000
+++ Source/WebCore/xml/XPathGrammar.y	2013-02-26 10:32:32.000000000 +0000
@@ -36,6 +36,7 @@
 #include "XPathParser.h"
 #include "XPathPath.h"
 #include "XPathPredicate.h"
+#include "XPathStep.h"
 #include "XPathVariableReference.h"
 #include <wtf/FastMalloc.h>
 
@@ -46,8 +47,6 @@
 #define YYLTYPE_IS_TRIVIAL 1
 #define YYDEBUG 0
 #define YYMAXDEPTH 10000
-#define YYPARSE_PARAM parserParameter
-#define PARSER static_cast<Parser*>(parserParameter)
 
 using namespace WebCore;
 using namespace XPath;
@@ -55,6 +54,7 @@
 %}
 
 %pure_parser
+%parse-param { WebCore::XPath::Parser* parser }
 
 %union
 {
@@ -73,7 +73,7 @@
 %{
 
 static int xpathyylex(YYSTYPE* yylval) { return Parser::current()->lex(yylval); }
-static void xpathyyerror(const char*) { }
+static void xpathyyerror(void*, const char*) { }
     
 %}
 
@@ -120,7 +120,7 @@
 Expr:
     OrExpr
     {
-        PARSER->m_topExpr = $1;
+        parser->m_topExpr = $1;
     }
     ;
 
@@ -140,7 +140,7 @@
     '/'
     {
         $$ = new LocationPath;
-        PARSER->registerParseNode($$);
+        parser->registerParseNode($$);
     }
     |
     '/' RelativeLocationPath
@@ -152,7 +152,7 @@
     {
         $$ = $2;
         $$->insertFirstStep($1);
-        PARSER->unregisterParseNode($1);
+        parser->unregisterParseNode($1);
     }
     ;
 
@@ -161,22 +161,22 @@
     {
         $$ = new LocationPath;
         $$->appendStep($1);
-        PARSER->unregisterParseNode($1);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->registerParseNode($$);
     }
     |
     RelativeLocationPath '/' Step
     {
         $$->appendStep($3);
-        PARSER->unregisterParseNode($3);
+        parser->unregisterParseNode($3);
     }
     |
     RelativeLocationPath DescendantOrSelf Step
     {
         $$->appendStep($2);
         $$->appendStep($3);
-        PARSER->unregisterParseNode($2);
-        PARSER->unregisterParseNode($3);
+        parser->unregisterParseNode($2);
+        parser->unregisterParseNode($3);
     }
     ;
 
@@ -185,58 +185,58 @@
     {
         if ($2) {
             $$ = new Step(Step::ChildAxis, *$1, *$2);
-            PARSER->deletePredicateVector($2);
+            parser->deletePredicateVector($2);
         } else
             $$ = new Step(Step::ChildAxis, *$1);
-        PARSER->deleteNodeTest($1);
-        PARSER->registerParseNode($$);
+        parser->deleteNodeTest($1);
+        parser->registerParseNode($$);
     }
     |
     NAMETEST OptionalPredicateList
     {
         String localName;
         String namespaceURI;
-        if (!PARSER->expandQName(*$1, localName, namespaceURI)) {
-            PARSER->m_gotNamespaceError = true;
+        if (!parser->expandQName(*$1, localName, namespaceURI)) {
+            parser->m_gotNamespaceError = true;
             YYABORT;
         }
         
         if ($2) {
             $$ = new Step(Step::ChildAxis, Step::NodeTest(Step::NodeTest::NameTest, localName, namespaceURI), *$2);
-            PARSER->deletePredicateVector($2);
+            parser->deletePredicateVector($2);
         } else
             $$ = new Step(Step::ChildAxis, Step::NodeTest(Step::NodeTest::NameTest, localName, namespaceURI));
-        PARSER->deleteString($1);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->registerParseNode($$);
     }
     |
     AxisSpecifier NodeTest OptionalPredicateList
     {
         if ($3) {
             $$ = new Step($1, *$2, *$3);
-            PARSER->deletePredicateVector($3);
+            parser->deletePredicateVector($3);
         } else
             $$ = new Step($1, *$2);
-        PARSER->deleteNodeTest($2);
-        PARSER->registerParseNode($$);
+        parser->deleteNodeTest($2);
+        parser->registerParseNode($$);
     }
     |
     AxisSpecifier NAMETEST OptionalPredicateList
     {
         String localName;
         String namespaceURI;
-        if (!PARSER->expandQName(*$2, localName, namespaceURI)) {
-            PARSER->m_gotNamespaceError = true;
+        if (!parser->expandQName(*$2, localName, namespaceURI)) {
+            parser->m_gotNamespaceError = true;
             YYABORT;
         }
 
         if ($3) {
             $$ = new Step($1, Step::NodeTest(Step::NodeTest::NameTest, localName, namespaceURI), *$3);
-            PARSER->deletePredicateVector($3);
+            parser->deletePredicateVector($3);
         } else
             $$ = new Step($1, Step::NodeTest(Step::NodeTest::NameTest, localName, namespaceURI));
-        PARSER->deleteString($2);
-        PARSER->registerParseNode($$);
+        parser->deleteString($2);
+        parser->registerParseNode($$);
     }
     |
     AbbreviatedStep
@@ -261,23 +261,23 @@
         else if (*$1 == "comment")
             $$ = new Step::NodeTest(Step::NodeTest::CommentNodeTest);
 
-        PARSER->deleteString($1);
-        PARSER->registerNodeTest($$);
+        parser->deleteString($1);
+        parser->registerNodeTest($$);
     }
     |
     PI '(' ')'
     {
         $$ = new Step::NodeTest(Step::NodeTest::ProcessingInstructionNodeTest);
-        PARSER->deleteString($1);        
-        PARSER->registerNodeTest($$);
+        parser->deleteString($1);        
+        parser->registerNodeTest($$);
     }
     |
     PI '(' LITERAL ')'
     {
         $$ = new Step::NodeTest(Step::NodeTest::ProcessingInstructionNodeTest, $3->stripWhiteSpace());
-        PARSER->deleteString($1);        
-        PARSER->deleteString($3);
-        PARSER->registerNodeTest($$);
+        parser->deleteString($1);        
+        parser->deleteString($3);
+        parser->registerNodeTest($$);
     }
     ;
 
@@ -295,14 +295,14 @@
     {
         $$ = new Vector<Predicate*>;
         $$->append(new Predicate($1));
-        PARSER->unregisterParseNode($1);
-        PARSER->registerPredicateVector($$);
+        parser->unregisterParseNode($1);
+        parser->registerPredicateVector($$);
     }
     |
     PredicateList Predicate
     {
         $$->append(new Predicate($2));
-        PARSER->unregisterParseNode($2);
+        parser->unregisterParseNode($2);
     }
     ;
 
@@ -317,7 +317,7 @@
     SLASHSLASH
     {
         $$ = new Step(Step::DescendantOrSelfAxis, Step::NodeTest(Step::NodeTest::AnyNodeTest));
-        PARSER->registerParseNode($$);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -325,13 +325,13 @@
     '.'
     {
         $$ = new Step(Step::SelfAxis, Step::NodeTest(Step::NodeTest::AnyNodeTest));
-        PARSER->registerParseNode($$);
+        parser->registerParseNode($$);
     }
     |
     DOTDOT
     {
         $$ = new Step(Step::ParentAxis, Step::NodeTest(Step::NodeTest::AnyNodeTest));
-        PARSER->registerParseNode($$);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -339,8 +339,8 @@
     VARIABLEREFERENCE
     {
         $$ = new VariableReference(*$1);
-        PARSER->deleteString($1);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->registerParseNode($$);
     }
     |
     '(' Expr ')'
@@ -351,15 +351,15 @@
     LITERAL
     {
         $$ = new StringExpression(*$1);
-        PARSER->deleteString($1);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->registerParseNode($$);
     }
     |
     NUMBER
     {
         $$ = new Number($1->toDouble());
-        PARSER->deleteString($1);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->registerParseNode($$);
     }
     |
     FunctionCall
@@ -371,8 +371,8 @@
         $$ = createFunction(*$1);
         if (!$$)
             YYABORT;
-        PARSER->deleteString($1);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->registerParseNode($$);
     }
     |
     FUNCTIONNAME '(' ArgumentList ')'
@@ -380,9 +380,9 @@
         $$ = createFunction(*$1, *$3);
         if (!$$)
             YYABORT;
-        PARSER->deleteString($1);
-        PARSER->deleteExpressionVector($3);
-        PARSER->registerParseNode($$);
+        parser->deleteString($1);
+        parser->deleteExpressionVector($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -391,14 +391,14 @@
     {
         $$ = new Vector<Expression*>;
         $$->append($1);
-        PARSER->unregisterParseNode($1);
-        PARSER->registerExpressionVector($$);
+        parser->unregisterParseNode($1);
+        parser->registerExpressionVector($$);
     }
     |
     ArgumentList ',' Argument
     {
         $$->append($3);
-        PARSER->unregisterParseNode($3);
+        parser->unregisterParseNode($3);
     }
     ;
 
@@ -414,9 +414,9 @@
         $$ = new Union;
         $$->addSubExpression($1);
         $$->addSubExpression($3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -432,9 +432,9 @@
     {
         $3->setAbsolute(true);
         $$ = new Path(static_cast<Filter*>($1), $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     |
     FilterExpr DescendantOrSelf RelativeLocationPath
@@ -442,10 +442,10 @@
         $3->insertFirstStep($2);
         $3->setAbsolute(true);
         $$ = new Path(static_cast<Filter*>($1), $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($2);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($2);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -455,9 +455,9 @@
     PrimaryExpr PredicateList
     {
         $$ = new Filter($1, *$2);
-        PARSER->unregisterParseNode($1);
-        PARSER->deletePredicateVector($2);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->deletePredicateVector($2);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -467,9 +467,9 @@
     OrExpr OR AndExpr
     {
         $$ = new LogicalOp(LogicalOp::OP_Or, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -479,9 +479,9 @@
     AndExpr AND EqualityExpr
     {
         $$ = new LogicalOp(LogicalOp::OP_And, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -491,9 +491,9 @@
     EqualityExpr EQOP RelationalExpr
     {
         $$ = new EqTestOp($2, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -503,9 +503,9 @@
     RelationalExpr RELOP AdditiveExpr
     {
         $$ = new EqTestOp($2, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -515,17 +515,17 @@
     AdditiveExpr PLUS MultiplicativeExpr
     {
         $$ = new NumericOp(NumericOp::OP_Add, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     |
     AdditiveExpr MINUS MultiplicativeExpr
     {
         $$ = new NumericOp(NumericOp::OP_Sub, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -535,9 +535,9 @@
     MultiplicativeExpr MULOP UnaryExpr
     {
         $$ = new NumericOp($2, $1, $3);
-        PARSER->unregisterParseNode($1);
-        PARSER->unregisterParseNode($3);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($1);
+        parser->unregisterParseNode($3);
+        parser->registerParseNode($$);
     }
     ;
 
@@ -548,8 +548,8 @@
     {
         $$ = new Negative;
         $$->addSubExpression($2);
-        PARSER->unregisterParseNode($2);
-        PARSER->registerParseNode($$);
+        parser->unregisterParseNode($2);
+        parser->registerParseNode($$);
     }
     ;
 
