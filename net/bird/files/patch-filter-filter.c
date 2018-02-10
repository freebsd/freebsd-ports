--- filter/filter.c.orig	2018-02-07 16:42:34.914441000 +0100
+++ filter/filter.c	2018-02-07 16:43:07.274018000 +0100
@@ -1559,6 +1559,7 @@
   case P('<','='): TWOARGS; break;
 
   case '!': ONEARG; break;
+  case P('!', '~'):
   case '~': TWOARGS; break;
   case P('d','e'): ONEARG; break;
 
