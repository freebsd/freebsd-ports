--- lips/gdevlips.mak.orig	Thu Nov  2 12:12:13 2000
+++ lips/gdevlips.mak	Wed Feb 13 07:29:36 2002
@@ -43,15 +43,6 @@
 $(GLOBJ)lp2000.dev: $(escpage_) $(DD)page.dev
 	$(SETPDEV) $(DD)lp2000 $(escpage_)
 
-### --- The NEC NPDL language printer device ------ ###
-
-npdl_=$(GLOBJ)gdevnpdl.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
-$(GLOBJ)gdevnpdl.$(OBJ): $(GLSRC)gdevnpdl.c $(GLSRC)gdevlprn.h $(PDEVH)
-	$(GLCC) -DA4 $(GLO_)gdevnpdl.$(OBJ) $(C_) $(GLSRC)gdevnpdl.c
-
-$(GLOBJ)npdl.dev: $(npdl_) $(DD)page.dev
-	$(SETPDEV) $(DD)npdl $(npdl_)
-	
 ### --- The RICOH RPDL language printer device ------ ###
 
 rpdl_=$(GLOBJ)gdevrpdl.$(OBJ) $(GLOBJ)gdevlprn.$(OBJ)
