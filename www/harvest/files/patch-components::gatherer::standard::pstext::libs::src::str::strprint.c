--- ./components/gatherer/standard/pstext/libs/src/str/strprint.c.orig	Fri Aug  1 13:34:23 2003
+++ ./components/gatherer/standard/pstext/libs/src/str/strprint.c	Fri Aug  1 13:47:29 2003
@@ -62,6 +62,13 @@
 }
 
 
+#ifdef __STRICT_ANSI__
+void strx_print( int ccp, char *buf, int len, char *format, ... )
+{
+	va_list ap ;
+
+	va_start( ap, *format ) ;
+#else
 void strx_print( ccp, buf, len, format, va_alist )
 	int *ccp ;
 	char *buf ;
@@ -70,13 +77,19 @@
 	va_dcl
 {
 	va_list ap ;
-
 	va_start( ap ) ;
+#endif
 	strx_printv( ccp, buf, len, format, ap ) ;
 	va_end( ap ) ;
 }
 
+#ifdef __STRICT_ANSI__
+char *strx_sprint( char *buf, int len, char *format, ... )
+{
+	va_list ap ;
 
+	va_start( ap, *format ) ;
+#else
 char *strx_sprint( buf, len, format, va_alist )
 	char *buf ;
 	int len ;
@@ -86,6 +99,7 @@
 	va_list ap ;
 
 	va_start( ap ) ;
+#endif
 	strx_printv( INT_NULL, buf, len, format, ap ) ;
 	va_end( ap ) ;
 	return( buf ) ;
@@ -102,7 +116,14 @@
 	return( buf ) ;
 }
 
+#ifdef __STRICT_ANSI__
+int strx_nprint( char *buf, int len, char *format, ... )
+{
+	int cc ;
+	va_list ap ;
 
+	va_start( ap, *format ) ;
+#else
 int strx_nprint( buf, len, format, va_alist )
 	char *buf ;
 	int len ;
@@ -113,6 +134,7 @@
 	va_list ap ;
 
 	va_start( ap ) ;
+#endif
 	strx_printv( &cc, buf, len, format, ap ) ;
 	va_end( ap ) ;
 	return( cc ) ;
@@ -137,6 +159,13 @@
  * Group 2: the str_* functions
  */
 
+#ifdef __STRICT_ANSI__
+void str_print( int ccp, char *buf, char *format, ... )
+{
+	va_list ap ;
+
+	va_start( ap, *format ) ;
+#else
 void str_print( ccp, buf, format, va_alist )
 	int *ccp ;
 	char *buf ;
@@ -146,6 +175,7 @@
 	va_list ap ;
 
 	va_start( ap ) ;
+#endif
 	strx_printv( ccp, buf, 0, format, ap ) ;
 	va_end( ap ) ;
 }
@@ -160,7 +190,13 @@
 	strx_printv( ccp, buf, 0, format, ap ) ;
 }
 
+#ifdef __STRICT_ANSI__
+char *str_sprint( char *buf, char *format, ... )
+{
+	va_list ap ;
 
+	va_start( ap, *format ) ;
+#else
 char *str_sprint( buf, format, va_alist )
 	char *buf ;
 	char *format ;
@@ -169,6 +205,7 @@
 	va_list ap ;
 
 	va_start( ap ) ;
+#endif
 	strx_printv( INT_NULL, buf, 0, format, ap ) ;
 	va_end( ap ) ;
 	return( buf ) ;
@@ -184,7 +221,14 @@
 	return( buf ) ;
 }
 
+#ifdef __STRICT_ANSI__
+int str_nprint( char *buf, char *format, ... )
+{
+	int cc ;
+	va_list ap ;
 
+	va_start( ap, *format) ;
+#else
 int str_nprint( buf, format, va_alist )
 	char *buf ;
 	char *format ;
@@ -194,6 +238,7 @@
 	va_list ap ;
 
 	va_start( ap ) ;
+#endif
 	strx_printv( &cc, buf, 0, format, ap ) ;
 	va_end( ap ) ;
 	return( cc ) ;
