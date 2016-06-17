--- src/gdevdmpr.mak.orig	1997-05-27 09:56:00.000000000 +0900
+++ src/gdevdmpr.mak	2013-04-30 02:18:35.000000000 +0900
@@ -1,8 +1,12 @@
 ### ---------------- Dot matrix printer device ---------------- ###
-dmprt_=gdevdmpr.$(OBJ) dviprlib.$(OBJ) gdevprn.$(OBJ)
+dmprt_=$(GLOBJ)gdevdmpr.$(OBJ) $(GLOBJ)dviprlib.$(OBJ) $(GLOBJ)gdevprn.$(OBJ)
 
-dmprt.dev: $(dmprt_)
-	$(SETDEV) dmprt $(dmprt_)
-	$(ADDMOD) dmprt -ps dmp_init
-gdevdmpr.$(OBJ): gdevdmpr.c dviprlib.h $(PDEVH)
-dviprlib.$(OBJ): dviprlib.c dviprlib.h
+$(DD)dmprt.dev: $(dmprt_)
+	$(SETDEV) $(DD)dmprt $(dmprt_)
+	$(ADDMOD) $(DD)dmprt -ps dmp_init
+
+$(GLOBJ)gdevdmpr.$(OBJ): $(GLSRC)gdevdmpr.c $(GLSRC)dviprlib.h $(PDEVH)
+	$(GLCC) $(GLO_)gdevdmpr.$(OBJ) $(C_) $(GLSRC)gdevdmpr.c
+
+$(GLOBJ)dviprlib.$(OBJ): $(arch_h) $(GLSRC)dviprlib.c $(GLSRC)dviprlib.h
+	$(GLCC) $(GLO_)dviprlib.$(OBJ) $(C_) $(GLSRC)dviprlib.c
