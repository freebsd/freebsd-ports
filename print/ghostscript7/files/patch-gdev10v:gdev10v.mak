--- gdev10v/gdev10v.mak.orig	Thu Oct 12 11:17:50 2000
+++ gdev10v/gdev10v.mak	Thu Oct 12 11:21:12 2000
@@ -1,12 +1,13 @@
 ### ----------------- The Canon BubbleJet BJ10v device ----------------- ###
 
-bj10v_=gdev10v.$(OBJ) gdevprn.$(OBJ)
-bj10v.dev: $(bj10v_)
-	$(SHP)gssetdev bj10v $(bj10v_)
-bj10vh.dev: $(bj10v_)
-	$(SHP)gssetdev bj10vh $(bj10v_)
+bj10v_=$(GLOBJ)gdev10v.$(OBJ) $(GLOBJ)gdevprn.$(OBJ)
+$(DD)bj10v.dev: $(bj10v_) $(DD)page.dev
+	$(SETPDEV) $(DD)bj10v $(bj10v_)
+$(DD)bj10vh.dev: $(bj10v_) $(DD)page.dev
+	$(SETPDEV) $(DD)bj10vh $(bj10v_)
 
 # Uncomment the following line if you are using MS-DOS on PC9801 series.
 
-gdev10v.$(OBJ): gdevbj10.c $(PDEVH)
+$(GLOBJ)gdev10v.$(OBJ): $(GLSRC)gdevbj10.c $(PDEVH)
+	$(GLCC) $(GLO_)gdev10v.$(OBJ) $(C_) $(GLSRC)gdev10v.c
 #	$(CCC) -DPC9801 gdev10v.c
