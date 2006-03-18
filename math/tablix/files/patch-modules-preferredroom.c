--- modules/preferredroom.c.orig	Sat Feb 18 11:56:01 2006
+++ modules/preferredroom.c	Sat Feb 18 11:57:00 2006
@@ -182,6 +182,8 @@
 int module_init(moduleoption *opt) 
 {
 	int c;
+	fitnessfunc *fitness;
+
 	ptroom=malloc(sizeof(*ptroom)*restype_find("teacher")->resnum);
 	for(c=0;c<restype_find("teacher")->resnum;c++) ptroom[c]=-1;
 
@@ -197,8 +199,6 @@
 		return(-1);
 	}
 	
-	fitnessfunc *fitness;
-
 	precalc_new(module_precalc);
 
 	handler_res_new("teacher", "preferred-room", gettroom);
