--- coreconf/UNIX.mk~
+++ coreconf/UNIX.mk
@@ -42,10 +42,8 @@ AR          = ar cr $@
 LDOPTS     += -L$(SOURCE_LIB_DIR)
 
 ifdef BUILD_OPT
-	OPTIMIZER  += -O
 	DEFINES    += -UDEBUG -DNDEBUG
 else
-	OPTIMIZER  += -g
 	USERNAME   := $(shell whoami)
 	USERNAME   := $(subst -,_,$(USERNAME))
 	DEFINES    += -DDEBUG -UNDEBUG -DDEBUG_$(USERNAME)
