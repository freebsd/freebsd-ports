--- gdevlips/gdevlips.mak.orig	Thu Nov  2 12:12:13 2000
+++ gdevlips/gdevlips.mak	Thu Jan 17 01:29:06 2002
@@ -30,27 +30,6 @@
  $(gscspace_h) $(gsutil_h) $(gsparam_h) $(gsmatrix_h) $(gdevvec_h)\
  $(ghost_h) $(gzstate_h) $(igstate_h)
 	$(GLCC) -DA4 $(GLO_)gdevl4v.$(OBJ) $(C_) $(GLSRC)gdevl4v.c
-
-### ------- Epson ESC/Page printer device ----------------- ###
-
-escpage_=$(GLOBJ)gdevespg.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
-$(GLOBJ)gdevespg.$(OBJ): $(GLSRC)gdevespg.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevespg.$(OBJ) $(C_) $(GLSRC)gdevespg.c
-
-$(GLOBJ)escpage.dev: $(escpage_) $(DD)page.dev
-	$(SETPDEV) $(DD)escpage $(escpage_)
-
-$(GLOBJ)lp2000.dev: $(escpage_) $(DD)page.dev
-	$(SETPDEV) $(DD)lp2000 $(escpage_)
-
-### --- The NEC NPDL language printer device ------ ###
-
-npdl_=$(GLOBJ)gdevnpdl.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
-$(GLOBJ)gdevnpdl.$(OBJ): $(GLSRC)gdevnpdl.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevnpdl.$(OBJ) $(C_) $(GLSRC)gdevnpdl.c
-
-$(GLOBJ)npdl.dev: $(npdl_) $(DD)page.dev
-	$(SETPDEV) $(DD)npdl $(npdl_)
 	
 ### --- The RICOH RPDL language printer device ------ ###
 
