--- makefiles/Makefile.third_party.unix.mk.orig	2020-06-12 13:05:43 UTC
+++ makefiles/Makefile.third_party.unix.mk
@@ -73,7 +73,8 @@ ifeq ($(wildcard $(UNIX_OSI_DIR)/include/osi/coin/OsiS
 else
 	$(info OSI: found)
 endif
-ifeq ($(wildcard $(UNIX_CLP_DIR)/include/clp/coin/ClpModel.hpp $(UNIX_CLP_DIR)/include/coin/ClpSimplex.hpp),)
+ifeq ($(wildcard $(UNIX_CLP_DIR)/include/coin/ClpModel.hpp $(UNIX_CLP_DIR)/include/coin/ClpSimplex.hpp),)
+	$(info CLP: NOT found: UNIX_CLP_DIR=$(UNIX_CLP_DIR))
 	$(error Third party Clp files was not found! did you run 'make third_party' or set UNIX_CLP_DIR ?)
 else
 	$(info CLP: found)
@@ -83,7 +84,7 @@ ifeq ($(wildcard $(UNIX_CGL_DIR)/include/cgl/coin/CglP
 else
 	$(info CGL: found)
 endif
-ifeq ($(wildcard $(UNIX_CBC_DIR)/include/cbc/coin/CbcModel.hpp $(UNIX_CBC_DIR)/include/coin/CbcModel.hpp),)
+ifeq ($(wildcard $(UNIX_CBC_DIR)/include/coin/CbcModel.hpp $(UNIX_CBC_DIR)/include/coin/CbcModel.hpp),)
 	$(error Third party Cbc files was not found! did you run 'make third_party' or set UNIX_CBC_DIR ?)
 else
 	$(info CBC: found)
