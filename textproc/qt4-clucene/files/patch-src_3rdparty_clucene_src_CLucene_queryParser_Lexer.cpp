--- src/3rdparty/clucene/src/CLucene/queryParser/Lexer.cpp.orig	2018-01-19 16:28:34 UTC
+++ src/3rdparty/clucene/src/CLucene/queryParser/Lexer.cpp
@@ -117,7 +117,7 @@ bool Lexer::GetNextToken(QueryToken* tok
       if( _istspace(ch)!=0 ) {
          continue;
       }
-      TCHAR buf[2] = {ch,'\0'};
+      TCHAR buf[2] = {static_cast<TCHAR>(ch),'\0'};
       switch(ch) {
          case '+':
             token->set(buf, QueryToken::PLUS);
