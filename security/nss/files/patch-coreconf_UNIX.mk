--- coreconf/UNIX.mk.orig	2018-08-31 12:55:53 UTC
+++ coreconf/UNIX.mk
@@ -10,10 +10,8 @@ AR          = ar cr $@
 LDOPTS     += -L$(SOURCE_LIB_DIR)
 
 ifdef BUILD_OPT
-	OPTIMIZER  += -O
 	DEFINES    += -UDEBUG -DNDEBUG
 else
-	OPTIMIZER  += -g
 	USERNAME   := $(shell whoami)
 	USERNAME   := $(subst -,_,$(USERNAME))
 	DEFINES    += -DDEBUG -UNDEBUG -DDEBUG_$(USERNAME)
