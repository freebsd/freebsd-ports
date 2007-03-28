--- diff3/Makefile.mk.orig	Wed May 24 16:44:17 2006
+++ diff3/Makefile.mk	Wed Mar 28 10:59:08 2007
@@ -1,7 +1,7 @@
 all: diff3 diff3prog
 
 diff3: diff3.sh
-	echo '#!$(SHELL)' | cat - diff3.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g' >diff3
+	echo '#!$(SHELL)' | cat - diff3.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g" >diff3
 	chmod 755 diff3
 
 diff3prog: diff3prog.o
