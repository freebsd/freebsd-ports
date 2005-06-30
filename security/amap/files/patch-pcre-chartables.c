--- pcre-3.9/chartables.c.orig	Wed Jun 29 17:30:09 2005
+++ pcre-3.9/chartables.c	Wed Jun 29 17:30:16 2005
@@ -10,7 +10,7 @@
 character tables which are used when no tables are passed to the compile
 function. */
 
-static unsigned char pcre_default_tables[] = {
+unsigned char pcre_default_tables[] = {
 
 /* This table is a lower casing table. */
 
