--- src/pslib.c.orig	Tue Jul 20 20:54:56 2004
+++ src/pslib.c	Mon Nov  1 22:38:48 2004
@@ -4557,8 +4557,8 @@
 PS_begin_template(PSDoc *psdoc, float width, float height) {
 	PSImage *pstemplate;
 	char buffer[20];
-	buffer[0] = '\0';
 	int templateid;
+	buffer[0] = '\0';
 
 	if(NULL == psdoc) {
 		ps_error(psdoc, PS_RuntimeError, _("PSDoc is null."));
@@ -4729,8 +4729,8 @@
 	PSPattern *pspattern;
 	char buffer[20];
 	int patternid;
-	buffer[0] = '\0';
 	PSShading *psshading;
+	buffer[0] = '\0';
 
 	if(NULL == psdoc) {
 		ps_error(psdoc, PS_RuntimeError, _("PSDoc is null."));
