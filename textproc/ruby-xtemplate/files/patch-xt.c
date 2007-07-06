--- ext/xt.c.orig	Wed May 30 19:05:12 2007
+++ ext/xt.c	Wed May 30 19:07:43 2007
@@ -243,11 +243,12 @@
     return rb_funcall(children, i_collect, 0);
 }
 
+static VALUE rb_xt_xnode_deep_dup(int, VALUE[], VALUE);
+
 static VALUE
 rb_xt_xnode_deep_dup_ii(VALUE child, VALUE data)
 {
     VALUE node = data;
-    static VALUE rb_xt_xnode_deep_dup(int, VALUE[], VALUE);
 
     if( rb_obj_is_kind_of(child, rb_cXNode) ){
 	VALUE argv[1] = {node};
