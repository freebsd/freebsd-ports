--- md2k/gdevmd2k.mak-5.50.orig	Sun Nov 19 18:42:20 2000
+++ md2k/gdevmd2k.mak-5.50	Sun Nov 19 18:52:14 2000
@@ -3,11 +3,11 @@
 
 md2k_=$(GLOBJ)gdevmd2k.$(OBJ)
 
-md2k.dev: $(md2k_) page.dev
-	$(SETPDEV) md2k $(md2k_)
+$(DD)md2k.dev: $(md2k_) $(DD)page.dev
+	$(SETPDEV) $(DD)md2k $(md2k_)
 
-md5k.dev: $(md2k_) page.dev
-	$(SETPDEV) md5k $(md2k_)
+$(DD)md5k.dev: $(md2k_) $(DD)page.dev
+	$(SETPDEV) $(DD)md5k $(md2k_)
 
-$(GLOBJ)gdevmd2k.$(OBJ): gdevmd2k.c $(PDEVH) $(gsparam_h)
+$(GLOBJ)gdevmd2k.$(OBJ): $(GLSRC)gdevmd2k.c $(PDEVH) $(gsparam_h)
 	$(GLCC) $(GLO_)gdevmd2k.$(OBJ) $(C_) $(GLSRC)gdevmd2k.c
