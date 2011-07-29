--- main.c.orig	2011-07-26 02:17:43.000000000 +0000
+++ main.c	2011-07-26 02:20:01.000000000 +0000
@@ -167,18 +167,18 @@
     unsigned c;
     VALUE lasterr = rb_gv_get("$!");
     VALUE message = rb_obj_as_string(lasterr);
-    VALUE ary = rb_funcall( ruby_errinfo, rb_intern("backtrace"), 0);
+    VALUE ary = rb_funcall( rb_errinfo, rb_intern("backtrace"), 0);
 
-    if( ! strcmp(RSTRING(message)->ptr, "exit"))
+    if( ! strcmp(RSTRING_PTR(message), "exit"))
     {
       quitMe(1);
       return;
     }
 
-    printf( "usbhotkey: %s\n", RSTRING(message)->ptr);
+    printf( "usbhotkey: %s\n", RSTRING_PTR(message));
     printf( "usbhotkey: Backtrace:\n");
-    for( c=0; c<RARRAY(ary)->len; c++) 
-      printf( "usbhotkey: \tfrom %s\n", RSTRING(RARRAY(ary)->ptr[c])->ptr);
+    for( c=0; c<RARRAY_LEN(ary); c++) 
+      printf( "usbhotkey: \tfrom %s\n", RSTRING_PTR(RARRAY_PTR(ary)[c]));
     errorHelp( "Error executing start script\n");
   }
 }
