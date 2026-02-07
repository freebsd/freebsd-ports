--- dircmp/Makefile.mk.orig	Wed May 24 16:44:34 2006
+++ dircmp/Makefile.mk	Wed Mar 28 11:00:11 2007
@@ -1,7 +1,7 @@
 all: dircmp
 
 dircmp: dircmp.sh
-	echo '#!$(SHELL)' | cat - dircmp.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g' >dircmp
+	echo '#!$(SHELL)' | cat - dircmp.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g" >dircmp
 	chmod 755 dircmp
 
 install: all
