--- Mk/ov.vars.mk.orig	Sat Sep  3 12:22:17 2005
+++ Mk/ov.vars.mk	Sun Sep  4 00:49:19 2005
@@ -8,9 +8,9 @@
 
 DATA_INST_PATH?=$(INST_PATH)/$(IMID)
 
-INC=-I../../Headers -I/usr/local/include
+INC=-I/usr/X11R6/include -I/usr/X11R6/include/OpenVanilla -I/usr/local/include
 
-CFLAGS=-O2 -Wall $(INC)
+CFLAGS+=-O2 -Wall $(INC)
 
 GCC=/usr/bin/gcc
 GPP=/usr/bin/g++
