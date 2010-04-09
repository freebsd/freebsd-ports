--- config.m4.orig	2009-03-06 08:25:45.000000000 +0100
+++ config.m4	2009-03-06 08:28:10.000000000 +0100
@@ -32,6 +32,7 @@
 #endif
       ],[
         PHP_PCRE_REGEX=pecl
+	PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
       ],[
         PHP_PCRE_REGEX=no
       ])
