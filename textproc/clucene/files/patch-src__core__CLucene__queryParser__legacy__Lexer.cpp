--- src/core/CLucene/queryParser/legacy/Lexer.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/queryParser/legacy/Lexer.cpp	2014-06-24 18:33:06.000000000 -0400
@@ -117,7 +117,7 @@
       if( _istspace(ch)!=0 ) {
          continue;
       }
-      TCHAR buf[2] = {ch,'\0'};
+      TCHAR buf[2] = {TCHAR(ch),'\0'};
       switch(ch) {
          case '+':
             token->set(buf, QueryToken::PLUS);
