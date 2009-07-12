--- eruby_main.c.orig	2003-12-23 16:10:54.000000000 +0100
+++ eruby_main.c	2009-06-30 12:45:54.000000000 +0200
@@ -29,14 +29,27 @@
 #endif
 
 #include "ruby.h"
+#if defined(RFLOAT_VALUE)
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
@@ -92,15 +105,23 @@
 static void error_pos(FILE *out, int cgi)
 {
     char buff[BUFSIZ];
+#if RUBY_VERSION_CODE >= 190
+    const char *sourcefile = rb_sourcefile();
+    int sourceline = rb_sourceline();
+    ID last_func = rb_frame_callee();
+#else
+    const char *sourcefile = ruby_sourcefile;
+    int sourceline = ruby_sourceline;
     ID last_func = rb_frame_last_func();
+#endif
 
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
@@ -115,38 +136,38 @@
     VALUE eclass;
     VALUE einfo;
 
-    if (NIL_P(ruby_errinfo)) return;
+    if (NIL_P(rb_errinfo())) return;
 
-    errat = rb_funcall(ruby_errinfo, rb_intern("backtrace"), 0);
+    errat = rb_funcall(rb_errinfo(), rb_intern("backtrace"), 0);
     if (!NIL_P(errat)) {
-	VALUE mesg = RARRAY(errat)->ptr[0];
+	VALUE mesg = RARRAY_PTR(errat)[0];
 
 	if (NIL_P(mesg)) {
 	    error_pos(out, cgi);
 	}
 	else {
 	    if (cgi)
-		write_escaping_html(out, RSTRING(mesg)->ptr, RSTRING(mesg)->len);
+		write_escaping_html(out, RSTRING_PTR(mesg), RSTRING_LEN(mesg));
 	    else
-		fwrite(RSTRING(mesg)->ptr, 1, RSTRING(mesg)->len, out);
+		fwrite(RSTRING_PTR(mesg), 1, RSTRING_LEN(mesg), out);
 	}
     }
 
-    eclass = CLASS_OF(ruby_errinfo);
-    einfo = rb_obj_as_string(ruby_errinfo);
-    if (eclass == rb_eRuntimeError && RSTRING(einfo)->len == 0) {
+    eclass = CLASS_OF(rb_errinfo());
+    einfo = rb_obj_as_string(rb_errinfo());
+    if (eclass == rb_eRuntimeError && RSTRING_LEN(einfo) == 0) {
 	fprintf(out, ": unhandled exception\n");
     }
     else {
 	VALUE epath;
 
 	epath = rb_class_path(eclass);
-	if (RSTRING(einfo)->len == 0) {
+	if (RSTRING_LEN(einfo) == 0) {
 	    fprintf(out, ": ");
 	    if (cgi)
-		write_escaping_html(out, RSTRING(epath)->ptr, RSTRING(epath)->len);
+		write_escaping_html(out, RSTRING_PTR(epath), RSTRING_LEN(epath));
 	    else
-		fwrite(RSTRING(epath)->ptr, 1, RSTRING(epath)->len, out);
+		fwrite(RSTRING_PTR(epath), 1, RSTRING_LEN(epath), out);
 	    if (cgi)
 		fprintf(out, "<br>\n");
 	    else
@@ -154,24 +175,24 @@
 	}
 	else {
 	    char *tail  = 0;
-	    int len = RSTRING(einfo)->len;
+	    int len = RSTRING_LEN(einfo);
 
-	    if (RSTRING(epath)->ptr[0] == '#') epath = 0;
-	    if ((tail = strchr(RSTRING(einfo)->ptr, '\n')) != NULL) {
-		len = tail - RSTRING(einfo)->ptr;
+	    if (RSTRING_PTR(epath)[0] == '#') epath = 0;
+	    if ((tail = strchr(RSTRING_PTR(einfo), '\n')) != NULL) {
+		len = tail - RSTRING_PTR(einfo);
 		tail++;		/* skip newline */
 	    }
 	    fprintf(out, ": ");
 	    if (cgi)
-		write_escaping_html(out, RSTRING(einfo)->ptr, len);
+		write_escaping_html(out, RSTRING_PTR(einfo), len);
 	    else
-		fwrite(RSTRING(einfo)->ptr, 1, len, out);
+		fwrite(RSTRING_PTR(einfo), 1, len, out);
 	    if (epath) {
 		fprintf(out, " (");
 		if (cgi)
-		    write_escaping_html(out, RSTRING(epath)->ptr, RSTRING(epath)->len);
+		    write_escaping_html(out, RSTRING_PTR(epath), RSTRING_LEN(epath));
 		else
-		    fwrite(RSTRING(epath)->ptr, 1, RSTRING(epath)->len, out);
+		    fwrite(RSTRING_PTR(epath), 1, RSTRING_LEN(epath), out);
 		if (cgi)
 		    fprintf(out, ")<br>\n");
 		else
@@ -179,9 +200,9 @@
 	    }
 	    if (tail) {
 		if (cgi)
-		    write_escaping_html(out, tail, RSTRING(einfo)->len - len - 1);
+		    write_escaping_html(out, tail, RSTRING_LEN(einfo) - len - 1);
 		else
-		    fwrite(tail, 1, RSTRING(einfo)->len - len - 1, out);
+		    fwrite(tail, 1, RSTRING_LEN(einfo) - len - 1, out);
 		if (cgi)
 		    fprintf(out, "<br>\n");
 		else
@@ -200,38 +221,38 @@
 
 	rb_ary_pop(errat);
 	ep = RARRAY(errat);
-	for (i=1; i<ep->len; i++) {
-	    if (TYPE(ep->ptr[i]) == T_STRING) {
+	for (i=1; i<RARRAY_LEN(ep); i++) {
+	    if (TYPE(RARRAY_PTR(ep)[i]) == T_STRING) {
 		if (cgi) {
 		    fprintf(out, "<div class=\"backtrace\">from ");
 		    write_escaping_html(out,
-					RSTRING(ep->ptr[i])->ptr,
-					RSTRING(ep->ptr[i])->len);
+					RSTRING_PTR(RARRAY_PTR(ep)[i]),
+					RSTRING_LEN(RARRAY_PTR(ep)[i]));
 		}
 		else {
 		    fprintf(out, "        from ");
-		    fwrite(RSTRING(ep->ptr[i])->ptr, 1,
-			   RSTRING(ep->ptr[i])->len, out);
+		    fwrite(RSTRING_PTR(RARRAY_PTR(ep)[i]), 1,
+			   RSTRING_LEN(RARRAY_PTR(ep)[i]), out);
 		}
 		if (cgi)
 		    fprintf(out, "<br></div>\n");
 		else
 		    fprintf(out, "\n");
 	    }
-	    if (i == TRACE_HEAD && ep->len > TRACE_MAX) {
+	    if (i == TRACE_HEAD && RARRAY_LEN(ep) > TRACE_MAX) {
 		char buff[BUFSIZ];
 		if (cgi)
 		    snprintf(buff, BUFSIZ,
 			     "<div class=\"backtrace\">... %ld levels...\n",
-			     ep->len - TRACE_HEAD - TRACE_TAIL);
+			     RARRAY_LEN(ep) - TRACE_HEAD - TRACE_TAIL);
 		else
 		    snprintf(buff, BUFSIZ, "         ... %ld levels...<br></div>\n",
-			     ep->len - TRACE_HEAD - TRACE_TAIL);
+			     RARRAY_LEN(ep) - TRACE_HEAD - TRACE_TAIL);
 		if (cgi)
 		    write_escaping_html(out, buff, strlen(buff));
 		else
 		    fputs(buff, out);
-		i = ep->len - TRACE_TAIL;
+		i = RARRAY_LEN(ep) - TRACE_TAIL;
 	    }
 	}
     }
@@ -251,10 +272,10 @@
     }
 
     if (cgi) {
-	write_escaping_html(out, RSTRING(code)->ptr, RSTRING(code)->len);
+	write_escaping_html(out, RSTRING_PTR(code), RSTRING_LEN(code));
     }
     else {
-	fwrite(RSTRING(code)->ptr, 1, RSTRING(code)->len, out);
+	fwrite(RSTRING_PTR(code), 1, RSTRING_LEN(code), out);
     }
     if (cgi) {
 	fprintf(out, "</code></pre>\n");
@@ -394,15 +415,14 @@
 static VALUE defout_write(VALUE self, VALUE str)
 {
     str = rb_obj_as_string(str);
-    rb_str_cat(self, RSTRING(str)->ptr, RSTRING(str)->len);
+    rb_str_cat(self, RSTRING_PTR(str), RSTRING_LEN(str));
     return Qnil;
 }
 
 static VALUE defout_cancel(VALUE self)
 {
-    if (RSTRING(self)->len == 0) return Qnil;
-    RSTRING(self)->len = 0;
-    RSTRING(self)->ptr[0] = '\0';
+    if (RSTRING_LEN(self) == 0) return Qnil;
+    self = rb_str_new("", 0);
     return Qnil;
 }
 
@@ -556,7 +576,7 @@
 
     Init_stack(&stack_start);
     code = eruby_load(eruby_filename, 0, &state);
-    if (state && !rb_obj_is_kind_of(ruby_errinfo, rb_eSystemExit)) {
+    if (state && !rb_obj_is_kind_of(rb_errinfo(), rb_eSystemExit)) {
 	if (RTEST(ruby_debug) &&
 	    (eruby_mode == MODE_CGI || eruby_mode == MODE_NPHCGI)) {
 	    error_print(stdout, state, 1, eruby_mode, code);
@@ -571,8 +591,8 @@
 	print_generated_code(stderr, code, 0);
     }
 #if RUBY_VERSION_CODE >= 180
-    out = RSTRING(rb_stdout)->ptr;
-    nout = RSTRING(rb_stdout)->len;
+    out = RSTRING_PTR(rb_stdout);
+    nout = RSTRING_LEN(rb_stdout);
 #else
     out = RSTRING(rb_defout)->ptr;
     nout = RSTRING(rb_defout)->len;
