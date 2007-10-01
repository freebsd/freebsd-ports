--- node.c.orig	2004-05-19 12:20:44.000000000 +0200
+++ node.c	2007-10-02 00:27:29.000000000 +0200
@@ -89,7 +89,7 @@
 static int b_collectgarbage(int tab_no);
 static int b_countfree(int tab_no);
 static struct t_node *b_getfree(int tab_no);
-static int fls(int i);
+int fls(int i);
 #ifdef IPV6
 static int node_comp_id(long *a, long *b);
 #endif
@@ -599,7 +599,7 @@
 }
 
 /* fls - find last set bit  --- reverse function of vax ffs */
-static int fls(int i)
+ int fls(int i)
 {
     int index;
 
