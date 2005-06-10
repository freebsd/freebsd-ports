--- src/gdevdmpr.mak.orig	Mon May  1 20:24:43 2000
+++ src/gdevdmpr.mak	Mon May  1 20:26:23 2000
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
+$(GLOBJ)dviprlib.$(OBJ): $(GLSRC)dviprlib.c $(GLSRC)dviprlib.h
+	$(GLCC) $(GLO_)dviprlib.$(OBJ) $(C_) $(GLSRC)dviprlib.c
