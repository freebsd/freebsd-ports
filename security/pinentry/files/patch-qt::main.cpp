--- qt/main.cpp.orig	Wed Sep 24 20:10:31 2003
+++ qt/main.cpp	Wed Sep 24 20:10:49 2003
@@ -111,7 +111,7 @@
 
 int qt_main( int argc, char *argv[] )
 {
-	secmem_init( 16384*4 ); /* this should be enough, if not, increase it! */
+	secmem_init( 16384*8 ); /* this should be enough, if not, increase it! */
     secmem_set_flags(SECMEM_WARN);
     drop_privs();
     std::set_new_handler(my_new_handler);
