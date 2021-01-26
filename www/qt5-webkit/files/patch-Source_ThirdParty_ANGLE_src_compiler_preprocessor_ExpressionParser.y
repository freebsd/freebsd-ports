--- Source/ThirdParty/ANGLE/src/compiler/preprocessor/ExpressionParser.y.orig	2020-03-04 17:16:37 UTC
+++ Source/ThirdParty/ANGLE/src/compiler/preprocessor/ExpressionParser.y
@@ -68,7 +68,7 @@ struct Context
 }  // namespace
 %}
 
-%pure-parser
+%define api.pure
 %name-prefix "pp"
 %parse-param {Context *context}
 %lex-param {Context *context}
