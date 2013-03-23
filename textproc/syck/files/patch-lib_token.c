--- lib/token.c.orig	2013-03-14 21:32:08.000000000 +0800
+++ lib/token.c	2013-03-14 21:33:14.000000000 +0800
@@ -200,7 +200,7 @@
     { \
         if ( *indent == '\t' ) \
         { \
-            syckerror("TAB found in your indentation, please remove"); \
+            syckerror(0, "TAB found in your indentation, please remove"); \
             return 0; \
         } \
         else if ( is_newline( ++indent ) ) \
@@ -266,11 +266,11 @@
         return sycklex_yaml_utf8( sycklval, parser );
 
         case syck_yaml_utf16:
-            syckerror( "UTF-16 is not currently supported in Syck.\nPlease contribute code to help this happen!" );
+            syckerror( 0, "UTF-16 is not currently supported in Syck.\nPlease contribute code to help this happen!" );
         break;
 
         case syck_yaml_utf32:
-            syckerror( "UTF-32 is not currently supported in Syck.\nPlease contribute code to help this happen!" );
+            syckerror( 0, "UTF-32 is not currently supported in Syck.\nPlease contribute code to help this happen!" );
         break;
 
         case syck_bytecode_utf8:
@@ -2758,7 +2758,7 @@
 }
 
 void 
-syckerror( const char *msg )
+syckerror( void * parser, const char *msg )
 {
     if ( syck_parser_ptr->error_handler == NULL )
         syck_parser_ptr->error_handler = syck_default_error_handler;
