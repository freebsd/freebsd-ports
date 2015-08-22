--- src/cpca_gdev.mak.orig	2002-05-07 00:30:00.000000000 +0900
+++ src/cpca_gdev.mak	2013-04-30 02:22:40.000000000 +0900
@@ -50,10 +50,10 @@
 	$(GLCC) -DA4 $(GLO_)cpca_gdevl4v.$(OBJ) $(C_) $(GLSRC)cpca_gdevl4v.c
 
 #--- cpca_gdevlips.c ---#
-$(GLOBJ)cpca_gdevlips.$(OBJ): $(GLSRC)cpca_gdevlips.c $(GLSRC)cpca_gdevlips.h
+$(GLOBJ)cpca_gdevlips.$(OBJ): $(GLSRC)std.h $(GLGEN)arch.h $(GLSRC)cpca_gdevlips.c $(GLSRC)cpca_gdevlips.h
 	$(GLCC) $(GLO_)cpca_gdevlips.$(OBJ) $(C_) $(GLSRC)cpca_gdevlips.c
 
 #--- cpca_mk_cmd.c ---#
-$(GLOBJ)cpca_mk_cmd.$(OBJ): $(GLSRC)cpca_mk_cmd.c $(GLSRC)cpca_mk.h
+$(GLOBJ)cpca_mk_cmd.$(OBJ): $(GLSRC)std.h $(GLGEN)arch.h $(GLSRC)cpca_mk_cmd.c $(GLSRC)cpca_mk.h
 	$(GLCC) -fpack-struct $(GLO_)cpca_mk_cmd.$(OBJ) $(C_) $(GLSRC)cpca_mk_cmd.c
 
