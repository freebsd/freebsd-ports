--- pcre-3.9/chartables.c.orig	2011-04-20 15:10:17 UTC
+++ pcre-3.9/chartables.c
@@ -10,7 +10,7 @@ This file is #included in the compilatio
 character tables which are used when no tables are passed to the compile
 function. */
 
-static unsigned char pcre_default_tables[] = {
+unsigned char pcre_default_tables[] = {
 
 /* This table is a lower casing table. */
 
