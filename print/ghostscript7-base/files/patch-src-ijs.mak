--- src/ijs.mak.orig	2003-01-17 09:49:04.000000000 +0900
+++ src/ijs.mak	2013-04-30 02:24:08.000000000 +0900
@@ -66,7 +66,7 @@
 ijs_client_h=$(IJSSRC)$(D)ijs_client.h
 ijs_server_h=$(IJSSRC)$(D)ijs_server.h
 
-$(IJSOBJ)ijs.$(OBJ) : $(IJSSRC)ijs.c $(IJSDEP) $(ijs_h)
+$(IJSOBJ)ijs.$(OBJ) : ${ECHOGS_XE} $(IJSSRC)ijs.c $(IJSDEP) $(ijs_h)
 #	echo $(IJS_CCFLAGS)
 	$(EXP)$(ECHOGS_XE) $(IJS_CCFLAGS)
 	$(IJS_CC) $(IJSO_)ijs.$(OBJ) $(C_) $(IJSSRC)ijs.c
@@ -79,7 +79,7 @@
     $(IJSDEP) $(ijs_h) $(ijs_server_h)
 	$(IJS_CC) $(IJSO_)ijs_server.$(OBJ) $(C_) $(IJSSRC)ijs_server.c
 
-$(IJSOBJ)ijs_exec_unix.$(OBJ) : $(IJSSRC)ijs_exec_unix.c \
+$(IJSOBJ)ijs_exec_unix.$(OBJ) : $(arch_h) $(IJSSRC)ijs_exec_unix.c \
     $(IJSDEP) $(ijs_h) $(ijs_client_h)
 	$(IJS_CC) $(IJSO_)ijs_exec_unix.$(OBJ) $(C_) $(IJSSRC)ijs_exec_unix.c
 
