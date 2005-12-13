--- src/base/ftsynth.c.orig	Tue Dec 13 00:44:56 2005
+++ src/base/ftsynth.c	Tue Dec 13 00:45:05 2005
@@ -123,7 +123,6 @@
     if ( !error )
     {
       slot->advance.x += xstr;
-      slot->advance.y += ystr;
 
       slot->metrics.width        += xstr;
       slot->metrics.height       += ystr;
