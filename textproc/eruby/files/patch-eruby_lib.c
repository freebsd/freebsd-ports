--- eruby_lib.c.orig	2011-07-27 01:20:00.000000000 +0000
+++ eruby_lib.c	2011-07-27 01:27:56.000000000 +0000
@@ -34,10 +34,18 @@
 #include <signal.h>
 
 #include "ruby.h"
-#include "regex.h"
 #include "eruby.h"
 #include "config.h"
 
+#if defined(WITH_RUBY_19)
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
 
@@ -144,6 +152,7 @@
 	    }
 	    s++;
 	    goto again;
+#if !defined(WITH_RUBY_19)
 	case 'K':
 	    s++;
 	    if (*s == '\0') {
@@ -153,6 +162,7 @@
 	    rb_set_kcode(s);
 	    s++;
 	    goto again;
+#endif
 	case 'C':
 	    s++;
 	    if (isspace(*s)) s++;
@@ -397,7 +407,7 @@
 static void compile_error(eruby_compiler_t *compiler, char *msg)
 {
     rb_raise(eERubyCompileError, "%s:%d:%s",
-	     STR2CSTR(compiler->sourcefile), compiler->sourceline, msg);
+	     StringValuePtr(compiler->sourcefile), compiler->sourceline, msg);
 }
 
 static void parse_embedded_program(eruby_compiler_t *compiler,
@@ -592,8 +602,13 @@
 		if (prevc < 0) output_literal(compiler, "print \"");
 		output_char(compiler, c);
 		prevc = c;
+#if defined(WITH_RUBY_19)
+                if (ismbchar(c,c+4,OnigEncDefaultCharEncoding)) {
+                    int i, len = mbclen(c,c,OnigEncDefaultCharEncoding) - 1;
+#else
                 if (ismbchar(c)) {
                     int i, len = mbclen(c) - 1;
+#endif
                     
                     for (i = 0; i < len; i++) {
                         c = nextc(compiler);
@@ -697,7 +712,7 @@
     VALUE compiler, file, code;
 
     compiler = eruby_compiler_new();
-    file = rb_file_open(STR2CSTR(filename), "r");
+    file = rb_file_open(StringValuePtr(filename), "r");
     code = eruby_compiler_compile_file(compiler, file);
     rb_funcall(ruby_top_self, rb_intern("eval"), 3, code, Qnil, filename);
     return Qnil;
