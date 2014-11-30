Allow building with bison 3
Obtained from http://trac.webkit.org/changeset/154109/trunk/Source/ThirdParty/ANGLE/src/compiler/glslang.y

--- Source/ThirdParty/ANGLE/src/compiler/glslang.y.orig	2012-08-20 16:26:06 UTC
+++ Source/ThirdParty/ANGLE/src/compiler/glslang.y
@@ -32,6 +32,7 @@ WHICH GENERATES THE GLSL ES PARSER (glsl
 %expect 1 /* One shift reduce conflict because of if | else */
 %pure-parser
 %parse-param {TParseContext* context}
+%lex-param {YYLEX_PARAM}
 
 %union {
     struct {
