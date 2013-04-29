--- lips/gdevlips.mak.orig	2000-11-02 12:12:13.000000000 +0900
+++ lips/gdevlips.mak	2013-04-30 02:57:36.000000000 +0900
@@ -1,17 +1,19 @@
 # ---------------- Laser Printer devices ---------------- #
 # $Id: gdevlips.mak $
 
+lips_opts=-DGS_VERSION_MAJOR=$(GS_VERSION_MAJOR)
+
 $(GLOBJ)gdevlprn.$(OBJ): $(GLSRC)gdevlprn.c $(GLSRC)gdevlprn.h\
  $(gdevprn_h) $(PDEVH)
-	$(GLCC) $(GLO_)gdevlprn.$(OBJ) $(C_) $(GLSRC)gdevlprn.c
+	$(GLCC) $(GLO_)gdevlprn.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevlprn.c
 
 ### --- The Canon LIPS II+/III/IVc/IV printer device --- ###
 
 lipsr_=$(GLOBJ)gdevl4r.$(OBJ) $(GLOBJ)gdevlips.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
-$(GLOBJ)gdevl4r.$(OBJ): $(GLSRC)gdevl4r.c $(GLSRC)gdevlips.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevl4r.$(OBJ) $(C_) $(GLSRC)gdevl4r.c
-$(GLOBJ)gdevlips.$(OBJ): $(GLSRC)gdevlips.c
-	$(GLCC) $(GLO_)gdevlips.$(OBJ) $(C_) $(GLSRC)gdevlips.c
+$(GLOBJ)gdevl4r.$(OBJ): $(arch_h) $(GLSRC)gdevl4r.c $(GLSRC)gdevlips.h $(PDEVH)
+	$(GLCC) -DA4 $(GLO_)gdevl4r.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevl4r.c
+$(GLOBJ)gdevlips.$(OBJ): $(arch_h) $(GLSRC)gdevlips.c
+	$(GLCC) $(GLO_)gdevlips.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevlips.c
 $(DD)lips2p.dev: $(lipsr_) $(DD)page.dev
 	$(SETPDEV) $(DD)lips2p $(lipsr_)
 $(DD)lips3.dev: $(lipsr_) $(DD)page.dev
@@ -29,13 +31,13 @@
 $(GLOBJ)gdevl4v.$(OBJ): $(GLSRC)gdevl4v.c $(GLSRC)gdevlips.h $(GDEV) $(math__h)\
  $(gscspace_h) $(gsutil_h) $(gsparam_h) $(gsmatrix_h) $(gdevvec_h)\
  $(ghost_h) $(gzstate_h) $(igstate_h)
-	$(GLCC) -DA4 $(GLO_)gdevl4v.$(OBJ) $(C_) $(GLSRC)gdevl4v.c
+	$(GLCC) -DA4 $(GLO_)gdevl4v.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevl4v.c
 
 ### ------- Epson ESC/Page printer device ----------------- ###
 
 escpage_=$(GLOBJ)gdevespg.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
 $(GLOBJ)gdevespg.$(OBJ): $(GLSRC)gdevespg.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevespg.$(OBJ) $(C_) $(GLSRC)gdevespg.c
+	$(GLCC) -DA4 $(GLO_)gdevespg.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevespg.c
 
 $(GLOBJ)escpage.dev: $(escpage_) $(DD)page.dev
 	$(SETPDEV) $(DD)escpage $(escpage_)
@@ -47,7 +49,7 @@
 
 npdl_=$(GLOBJ)gdevnpdl.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
 $(GLOBJ)gdevnpdl.$(OBJ): $(GLSRC)gdevnpdl.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevnpdl.$(OBJ) $(C_) $(GLSRC)gdevnpdl.c
+	$(GLCC) -DA4 $(GLO_)gdevnpdl.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevnpdl.c
 
 $(GLOBJ)npdl.dev: $(npdl_) $(DD)page.dev
 	$(SETPDEV) $(DD)npdl $(npdl_)
@@ -56,7 +58,7 @@
 
 rpdl_=$(GLOBJ)gdevrpdl.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
 $(GLOBJ)gdevrpdl.$(OBJ): $(GLSRC)gdevrpdl.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevrpdl.$(OBJ) $(C_) $(GLSRC)gdevrpdl.c
+	$(GLCC) -DA4 $(GLO_)gdevrpdl.$(OBJ) $(C_) $(lips_opts) $(GLSRC)gdevrpdl.c
 
 $(GLOBJ)rpdl.dev: $(rpdl_) $(DD)page.dev
 	$(SETPDEV) $(DD)rpdl $(rpdl_)
