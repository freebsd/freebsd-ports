--- src/accessctl.c.orig	2015-09-13 08:43:04 UTC
+++ src/accessctl.c
@@ -34,7 +34,7 @@
 static char const ident[]="$Id: accessctl.c 521 2015-09-13 08:43:04Z hb9xar $";
 
 /* configuration storage */
-struct siproxd_config configuration;
+extern struct siproxd_config configuration;
 
 
 /*
