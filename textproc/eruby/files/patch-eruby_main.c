--- eruby_main.c.orig	2010-02-17 16:59:10.000000000 +0100
+++ eruby_main.c	2010-02-17 17:11:08.000000000 +0100
@@ -29,20 +29,37 @@
 #endif
 
 #include "ruby.h"
+#if defined(WITH_RUBY_19)
+#define RUBY_VERSION_CODE 190
+#endif
+#if RUBY_VERSION_CODE < 190
 #include "re.h"
+#endif
 #include "regex.h"
+#if RUBY_VERSION_CODE < 190
 #include "version.h"
+#endif
 
 #include "eruby.h"
 #include "eruby_logo.h"
 
+#if RUBY_VERSION_CODE < 190
 EXTERN VALUE ruby_errinfo;
+static VALUE rb_errinfo(void)
+{
+  return ruby_errinfo;
+}
+#endif
 EXTERN VALUE rb_stdout;
 #if RUBY_VERSION_CODE < 180
 EXTERN VALUE rb_defout;
 #endif
 EXTERN VALUE rb_load_path;
+#if RUBY_VERSION_CODE < 190
 EXTERN VALUE ruby_top_self;
+#else
+#define ruby_top_self	rb_vm_top_self()
+#endif
 
 /* copied from eval.c */
 #define TAG_RETURN	0x1
@@ -92,6 +109,13 @@
 
 static void error_pos(FILE *out, int cgi)
 {
+#if RUBY_VERSION_CODE >= 190
+    const char *sourcefile = rb_sourcefile();
+    int sourceline = rb_sourceline();
+#else
+    const char *sourcefile = ruby_sourcefile;
+    int sourceline = ruby_sourceline;
+#endif
     char buff[BUFSIZ];
 #if RUBY_VERSION_CODE >= 190
     ID last_func = rb_frame_this_func();
@@ -99,13 +123,13 @@
     ID last_func = rb_frame_last_func();
 #endif
 
-    if (ruby_sourcefile) {
+    if (sourcefile) {
 	if (last_func) {
-	    snprintf(buff, BUFSIZ, "%s:%d:in `%s'", ruby_sourcefile, ruby_sourceline,
+	    snprintf(buff, BUFSIZ, "%s:%d:in `%s'", sourcefile, sourceline,
 		     rb_id2name(last_func));
 	}
 	else {
-	    snprintf(buff, BUFSIZ, "%s:%d", ruby_sourcefile, ruby_sourceline);
+	    snprintf(buff, BUFSIZ, "%s:%d", sourcefile, sourceline);
 	}
 	if (cgi)
 	    write_escaping_html(out, buff, strlen(buff));
@@ -120,9 +144,9 @@
     VALUE eclass;
     VALUE einfo;
 
-    if (NIL_P(ruby_errinfo)) return;
+    if (NIL_P(rb_errinfo())) return;
 
-    errat = rb_funcall(ruby_errinfo, rb_intern("backtrace"), 0);
+    errat = rb_funcall(rb_errinfo(), rb_intern("backtrace"), 0);
     if (!NIL_P(errat)) {
 	VALUE mesg = RARRAY_PTR(errat)[0];
 
@@ -137,8 +161,8 @@
 	}
     }
 
-    eclass = CLASS_OF(ruby_errinfo);
-    einfo = rb_obj_as_string(ruby_errinfo);
+    eclass = CLASS_OF(rb_errinfo());
+    einfo = rb_obj_as_string(rb_errinfo());
     if (eclass == rb_eRuntimeError && RSTRING_LEN(einfo) == 0) {
 	fprintf(out, ": unhandled exception\n");
     }
@@ -540,7 +564,7 @@
 
 static void error(int state, VALUE code)
 {
-    if (state && !rb_obj_is_kind_of(ruby_errinfo, rb_eSystemExit)) {
+    if (state && !rb_obj_is_kind_of(rb_errinfo(), rb_eSystemExit)) {
 	if (RTEST(ruby_debug) &&
 	    (eruby_mode == MODE_CGI || eruby_mode == MODE_NPHCGI)) {
 	    error_print(stdout, state, 1, eruby_mode, code);
