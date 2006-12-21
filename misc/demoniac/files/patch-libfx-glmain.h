--- libfx/glmain.h.orig	Thu Dec 21 14:42:42 2006
+++ libfx/glmain.h	Thu Dec 21 14:43:00 2006
@@ -113,7 +113,7 @@
 	~GLMain();
 
 	//! kill all instances, reset application
-	void GLMain::clearAll();
+	void clearAll();
 
 	//! register a new effect 
 	int registerFX(FXGeneric *fx, int fxsize);
