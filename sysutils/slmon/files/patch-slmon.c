--- slmon.c.orig	Tue Aug 17 13:40:46 2004
+++ slmon.c	Tue Aug 17 13:41:44 2004
@@ -337,6 +337,7 @@
 	conf.map = conf.map_x;
 	break;
     default:
+	break;
     }
 }
 
@@ -514,6 +515,7 @@
 	conf.sort_func = slmon_cmp_user_asc;
 	break;
     default:
+	break;
     }
 }
 
