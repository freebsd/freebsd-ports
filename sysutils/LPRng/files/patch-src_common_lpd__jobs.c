
$FreeBSD$

--- src/common/lpd_jobs.c.orig	Mon Dec 30 20:33:17 2002
+++ src/common/lpd_jobs.c	Mon Dec 30 20:33:27 2002
@@ -189,7 +189,6 @@
 {   
     struct line_list *l, *r;
 	int tr, tl;
-	tr = (int)p;
 	l = ((struct line_list **)left)[0];
 	r = ((struct line_list **)right)[0];
 	tl = Find_flag_value(l,DONE_TIME,Value_sep);
