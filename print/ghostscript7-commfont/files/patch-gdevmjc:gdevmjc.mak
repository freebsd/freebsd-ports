--- gdevmjc/gdevmjc.mak.orig	Tue May 23 19:19:13 2000
+++ gdevmjc/gdevmjc.mak	Tue May 23 19:19:40 2000
@@ -4,25 +4,22 @@
 # Supports MJ-700V2C, MJ-5000C, MJ-900C, MJ-800C, MJ-500C
 #
 ##
-#
-#  Append this file to Makefile
-#
-##
-MJCSRC = gdevmjc.c mjmtx2.c mjbksep.c mjhtocmy.c mjvtbl.c \
-	mjgrnsp.c mjgrnsp2.c mjespdtc.c mjespdtm.c mjespdty.c mjbarrie.c
+MJCSRC = $(GLSRC)gdevmjc.c $(GLSRC)mjmtx2.c $(GLSRC)mjbksep.c \
+	$(GLSRC)mjhtocmy.c $(GLSRC)mjvtbl.c $(GLSRC)mjgrnsp.c \
+	$(GLSRC)mjgrnsp2.c $(GLSRC)mjespdtc.c $(GLSRC)mjespdtm.c \
+	$(GLSRC)mjespdty.c $(GLSRC)mjbarrie.c
 
-mj700v2c_=gdevmjc.$(OBJ) $(HPPCL)
+mj700v2c_=$(GLOBJ)gdevmjc.$(OBJ) $(HPPCL)
 
 # To make A4 paper the default, change the second line below this to
-gdevmjc.$(OBJ): $(MJCSRC) $(PDEVH) $(gdevpcl_h)
-	$(CCC) -DA4 gdevmjc.c
-
-mjc180.dev: $(mj700v2c_)
-	$(SHP)gssetdev mjc180 $(mj700v2c_)
-mjc360.dev: $(mj700v2c_)
-	$(SHP)gssetdev mjc360 $(mj700v2c_)
-mjc720.dev: $(mj700v2c_)
-	$(SHP)gssetdev mjc720 $(mj700v2c_)
-mj500c.dev: $(mj700v2c_)
-	$(SHP)gssetdev mj500c $(mj700v2c_)
+$(GLOBJ)gdevmjc.$(OBJ): $(MJCSRC) $(PDEVH) $(gdevpcl_h)
+	$(GLCC) -DA4 $(GLO_)gdevmjc.$(OBJ) $(C_) $(GLSRC)gdevmjc.c
 
+$(GLOBJ)mjc180.dev: $(mj700v2c_) $(DD)page.dev
+	$(SETPDEV) $(DD)mjc180 $(mj700v2c_)
+$(GLOBJ)mjc360.dev: $(mj700v2c_) $(DD)page.dev
+	$(SETPDEV) $(DD)mjc360 $(mj700v2c_)
+$(GLOBJ)mjc720.dev: $(mj700v2c_) $(DD)page.dev
+	$(SETPDEV) $(DD)mjc720 $(mj700v2c_)
+$(GLOBJ)mj500c.dev: $(mj700v2c_) $(DD)page.dev
+	$(SETPDEV) $(DD)mj500c $(mj700v2c_)
