--- jbsrc/jb.c.orig
+++ jbsrc/jb.c
@@ -444,6 +444,7 @@
   jb_compile_options_add_ldflags(object->compile_options, "-Wl,--export-dynamic");
 
   jb_compile_options_add_libs(object->compile_options, "-lm");
+  jb_compile_options_add_libs(object->compile_options, "-lX11");
 
   jb_compile_options_add_package(object->compile_options, "gettext");
   jb_compile_options_add_package(object->compile_options, "gnome");
