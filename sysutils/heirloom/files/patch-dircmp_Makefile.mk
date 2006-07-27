--- ./dircmp/Makefile.mk.orig	Sat Jun 25 18:48:53 2005
+++ ./dircmp/Makefile.mk	Thu Jul 27 00:59:45 2006
@@ -1,10 +1,10 @@
 all: dircmp
 
 dircmp: dircmp.sh
-	echo '#!$(SHELL)' | cat - dircmp.sh | sed ' \
+	echo '#!$(SHELL)' | cat - dircmp.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
-		s,@DEFLIB@,$(DEFLIB),g' >dircmp
+		s,@DEFLIB@,$(DEFLIB),g" >dircmp
 	chmod 755 dircmp
 
 install: all
