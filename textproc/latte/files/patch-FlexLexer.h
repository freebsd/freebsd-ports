--- FlexLexer.h.orig	Tue Nov 10 06:19:23 1998
+++ FlexLexer.h	Fri Mar 19 01:35:03 2004
@@ -42,7 +42,7 @@
 #ifndef __FLEX_LEXER_H
 // Never included before - need to define base class.
 #define __FLEX_LEXER_H
-#include <iostream.h>
+#include <iostream>
 
 extern "C++" {
 
@@ -59,14 +59,14 @@
 	virtual void
 		yy_switch_to_buffer( struct yy_buffer_state* new_buffer ) = 0;
 	virtual struct yy_buffer_state*
-		yy_create_buffer( istream* s, int size ) = 0;
+		yy_create_buffer( std::istream* s, int size ) = 0;
 	virtual void yy_delete_buffer( struct yy_buffer_state* b ) = 0;
-	virtual void yyrestart( istream* s ) = 0;
+	virtual void yyrestart( std::istream* s ) = 0;
 
 	virtual int yylex() = 0;
 
 	// Call yylex with new input/output sources.
-	int yylex( istream* new_in, ostream* new_out = 0 )
+	int yylex( std::istream* new_in, std::ostream* new_out = 0 )
 		{
 		switch_streams( new_in, new_out );
 		return yylex();
@@ -74,8 +74,8 @@
 
 	// Switch to new input/output streams.  A nil stream pointer
 	// indicates "keep the current one".
-	virtual void switch_streams( istream* new_in = 0,
-					ostream* new_out = 0 ) = 0;
+	virtual void switch_streams( std::istream* new_in = 0,
+					std::ostream* new_out = 0 ) = 0;
 
 	int lineno() const		{ return yylineno; }
 
@@ -102,17 +102,17 @@
 public:
 	// arg_yyin and arg_yyout default to the cin and cout, but we
 	// only make that assignment when initializing in yylex().
-	yyFlexLexer( istream* arg_yyin = 0, ostream* arg_yyout = 0 );
+	yyFlexLexer( std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0 );
 
 	virtual ~yyFlexLexer();
 
 	void yy_switch_to_buffer( struct yy_buffer_state* new_buffer );
-	struct yy_buffer_state* yy_create_buffer( istream* s, int size );
+	struct yy_buffer_state* yy_create_buffer( std::istream* s, int size );
 	void yy_delete_buffer( struct yy_buffer_state* b );
-	void yyrestart( istream* s );
+	void yyrestart( std::istream* s );
 
 	virtual int yylex();
-	virtual void switch_streams( istream* new_in, ostream* new_out );
+	virtual void switch_streams( std::istream* new_in, std::ostream* new_out );
 
 protected:
 	virtual int LexerInput( char* buf, int max_size );
@@ -123,7 +123,7 @@
 	int yyinput();
 
 	void yy_load_buffer_state();
-	void yy_init_buffer( struct yy_buffer_state* b, istream* s );
+	void yy_init_buffer( struct yy_buffer_state* b, std::istream* s );
 	void yy_flush_buffer( struct yy_buffer_state* b );
 
 	int yy_start_stack_ptr;
@@ -138,8 +138,8 @@
 	yy_state_type yy_try_NUL_trans( yy_state_type current_state );
 	int yy_get_next_buffer();
 
-	istream* yyin;	// input source for default LexerInput
-	ostream* yyout;	// output sink for default LexerOutput
+	std::istream* yyin;	// input source for default LexerInput
+	std::ostream* yyout;	// output sink for default LexerOutput
 
 	struct yy_buffer_state* yy_current_buffer;
 
