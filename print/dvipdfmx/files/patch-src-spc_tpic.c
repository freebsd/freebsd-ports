--- src/spc_tpic.c	2005/07/30 11:44:18	1.2
+++ src/spc_tpic.c	2005/10/14 04:55:00	1.3
@@ -1,4 +1,4 @@
-/*  $Header: /home/cvsroot/dvipdfmx/src/spc_tpic.c,v 1.2 2005/07/30 11:44:18 hirata Exp $
+/*  $Header: /home/cvsroot/dvipdfmx/src/spc_tpic.c,v 1.3 2005/10/14 04:55:00 chofchof Exp $
 
     This is dvipdfmx, an eXtended version of dvipdfm by Mark A. Wicks.
 
@@ -743,7 +743,7 @@
   ASSERT(spe && ap && tp);
 
   tp->fill_shape = 1;
-  tp->fill_color = 1.0;
+  tp->fill_color = 0.0;
 
   return  0;
 }
@@ -757,7 +757,7 @@
   ASSERT(spe && ap && tp);
 
   tp->fill_shape = 1;
-  tp->fill_color = 0.0;
+  tp->fill_color = 1.0;
 
   return  0;
 }
