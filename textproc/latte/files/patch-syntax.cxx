--- syntax.cxx.orig	Fri Oct 22 13:21:27 1999
+++ syntax.cxx	Fri Mar 19 01:17:52 2004
@@ -26,6 +26,9 @@
 #include <stdlib.h>
 #include <latte-iosfwd.h>
 #include <unistd.h>
+#include <iostream>
+
+using namespace std;
 
 /* Use prototypes in function declarations. */
 #define YY_USE_PROTOS
@@ -145,7 +148,7 @@
 
 struct yy_buffer_state
 	{
-	istream* yy_input_file;
+	std::istream* yy_input_file;
 
 	char *yy_ch_buf;		/* input buffer */
 	char *yy_buf_pos;		/* current position in input buffer */
@@ -945,7 +948,7 @@
 		} /* end of scanning one token */
 	} /* end of yylex */
 
-yyFlexLexer::yyFlexLexer( istream* arg_yyin, ostream* arg_yyout )
+yyFlexLexer::yyFlexLexer( std::istream* arg_yyin, std::ostream* arg_yyout )
 	{
 	yyin = arg_yyin;
 	yyout = arg_yyout;
@@ -980,7 +983,7 @@
 	yy_delete_buffer( yy_current_buffer );
 	}
 
-void yyFlexLexer::switch_streams( istream* new_in, ostream* new_out )
+void yyFlexLexer::switch_streams( std::istream* new_in, std::ostream* new_out )
 	{
 	if ( new_in )
 		{
@@ -1329,7 +1332,7 @@
 	}
 
 
-void yyFlexLexer::yyrestart( istream* input_file )
+void yyFlexLexer::yyrestart( std::istream* input_file )
 	{
 	if ( ! yy_current_buffer )
 		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );
@@ -1373,7 +1376,7 @@
 	}
 
 
-YY_BUFFER_STATE yyFlexLexer::yy_create_buffer( istream* file, int size )
+YY_BUFFER_STATE yyFlexLexer::yy_create_buffer( std::istream* file, int size )
 	{
 	YY_BUFFER_STATE b;
 
@@ -1414,7 +1417,7 @@
 
 
 extern "C" int isatty YY_PROTO(( int ));
-void yyFlexLexer::yy_init_buffer( YY_BUFFER_STATE b, istream* file )
+void yyFlexLexer::yy_init_buffer( YY_BUFFER_STATE b, std::istream* file )
 
 	{
 	yy_flush_buffer( b );
