--- src/script.c.orig	Mon Dec 13 14:34:09 2004
+++ src/script.c	Fri Jan 14 18:15:51 2005
@@ -153,6 +153,8 @@
     
     if(!NIL_P(ruby_errinfo)) {
     
+      VALUE ary;
+
       lasterr = rb_gv_get("$!"); 
       err = RSTRING(rb_obj_as_string(lasterr))->ptr;
       
@@ -162,7 +164,7 @@
       if_scripts_add(SCRIPTC_ERROR, msg);
       g_free(msg);
       
-      VALUE ary = rb_funcall(ruby_errinfo, rb_intern("backtrace"), 0);
+      ary = rb_funcall(ruby_errinfo, rb_intern("backtrace"), 0);
       debug_msg(1, "script_error: Ruby backtrace:");
       if_scripts_add(SCRIPTC_ERROR, _("Ruby backtrace:"));
       
