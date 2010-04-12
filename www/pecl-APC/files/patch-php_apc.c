--- ./php_apc.c.orig	2010-04-12 16:41:50.000000000 -0400
+++ ./php_apc.c	2010-04-12 16:41:56.000000000 -0400
@@ -955,7 +955,6 @@
 
 #ifdef ZEND_ENGINE_2
 /* {{{ arginfo */
-static
 ZEND_BEGIN_ARG_INFO(php_apc_fetch_arginfo, 0)
     ZEND_ARG_INFO(0, "key")
     ZEND_ARG_INFO(1, "success")
