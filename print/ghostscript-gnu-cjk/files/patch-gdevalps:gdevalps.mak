--- gdevalps/gdevalps.mak-5.50.orig	Sat Jan 12 13:21:12 2002
+++ gdevalps/gdevalps.mak-5.50	Sat Jan 12 13:23:45 2002
@@ -2,15 +2,15 @@
 
 alps_=$(GLOBJ)gdevalps.$(OBJ)
 
-md50Mono.dev: $(alps_) page.dev
-	$(SETPDEV) md50Mono $(alps_)
+$(DD)md50Mono.dev: $(alps_) $(DD)page.dev
+	$(SETPDEV) $(DD)md50Mono $(alps_)
 
-md50Eco.dev: $(alps_) page.dev
-	$(SETPDEV) md50Eco $(alps_)
+$(DD)md50Eco.dev: $(alps_) $(DD)page.dev
+	$(SETPDEV) $(DD)md50Eco $(alps_)
 
-md1xMono.dev: $(alps_) page.dev
-	$(SETPDEV) md1xMono $(alps_)
+$(DD)md1xMono.dev: $(alps_) $(DD)page.dev
+	$(SETPDEV) $(DD)md1xMono $(alps_)
 
-$(GLOBJ)gdevalps.$(OBJ): $(GLSRC)gdevalps.c $(PDEVH)
+$(GLOBJ)gdevalps.$(OBJ): $(GLSRC)gdevalps.c  $(gdevprn_h) $(PDEVH)
 	$(GLCC) $(GLO_)gdevalps.$(OBJ) $(C_) $(GLSRC)gdevalps.c
 
