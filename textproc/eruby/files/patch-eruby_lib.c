--- eruby_lib.c.orig	2003-07-29 05:42:56.000000000 +0200
+++ eruby_lib.c	2009-06-30 12:42:12.000000000 +0200
@@ -34,10 +34,18 @@
 #include <signal.h>
 
 #include "ruby.h"
-#include "regex.h"
 #include "eruby.h"
 #include "config.h"
 
+#if defined(RFLOAT_VALUE)
+#include "ruby/regex.h"
+#undef ismbchar
+#define ismbchar(c,e,enc)	((mbclen(c,e,enc)) != 1)
+#define	ruby_top_self	rb_vm_top_self
+#else
+#include "regex.h"
+#endif
+
 EXTERN VALUE rb_stdin;
 EXTERN VALUE ruby_top_self;
 
@@ -133,6 +141,7 @@
 	    }
 	    s++;
 	    goto again;
+#if !defined(RFLOAT_VALUE)
 	case 'K':
 	    s++;
 	    if (*s == '\0') {
@@ -142,6 +151,7 @@
 	    rb_set_kcode(s);
 	    s++;
 	    goto again;
+#endif
 	case 'C':
 	    s++;
 	    if (isspace(*s)) s++;
@@ -296,18 +306,18 @@
     VALUE s = compiler->lex_input;
     char *beg, *end, *pend;
 
-    if (RSTRING(s)->len == compiler->lex_gets_ptr)
+    if (RSTRING_LEN(s) == compiler->lex_gets_ptr)
 	return Qnil;
-    beg = RSTRING(s)->ptr;
+    beg = RSTRING_PTR(s);
     if (compiler->lex_gets_ptr > 0) {
 	beg += compiler->lex_gets_ptr;
     }
-    pend = RSTRING(s)->ptr + RSTRING(s)->len;
+    pend = RSTRING_PTR(s) + RSTRING_LEN(s);
     end = beg;
     while (end < pend) {
 	if (*end++ == '\n') break;
     }
-    compiler->lex_gets_ptr = end - RSTRING(s)->ptr;
+    compiler->lex_gets_ptr = end - RSTRING_PTR(s);
     return rb_str_new(beg, end - beg);
 }
 
@@ -326,8 +336,8 @@
 
 	    if (NIL_P(v)) return EOF;
 	    compiler->sourceline++;
-	    compiler->lex_pbeg = compiler->lex_p = RSTRING(v)->ptr;
-	    compiler->lex_pend = compiler->lex_p + RSTRING(v)->len;
+	    compiler->lex_pbeg = compiler->lex_p = RSTRING_PTR(v);
+	    compiler->lex_pend = compiler->lex_p + RSTRING_LEN(v);
 	    compiler->lex_lastline = v;
 	}
 	else {
@@ -471,7 +481,7 @@
 	if (c == '!') {
 	    unsigned char *p;
 	    char *argv[2];
-	    char *line = RSTRING(compiler->lex_lastline)->ptr;
+	    char *line = RSTRING_PTR(compiler->lex_lastline);
 
 	    if (line[strlen(line) - 1] == '\n') {
 		line[strlen(line) - 1] = '\0';
@@ -577,8 +587,13 @@
 		if (prevc < 0) output_literal(compiler, "print \"");
 		output_char(compiler, c);
 		prevc = c;
+#if defined(RFLOAT_VALUE)
+                if (ismbchar(c,c+4,OnigEncDefaultCharEncoding)) {
+                    int i, len = mbclen(c,c,OnigEncDefaultCharEncoding) - 1;
+#else
                 if (ismbchar(c)) {
                     int i, len = mbclen(c) - 1;
+#endif
                     
                     for (i = 0; i < len; i++) {
                         c = nextc(compiler);
