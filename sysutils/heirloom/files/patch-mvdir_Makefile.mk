--- ./mvdir/Makefile.mk.orig	Sat Jun 25 19:03:27 2005
+++ ./mvdir/Makefile.mk	Thu Jul 27 01:06:15 2006
@@ -1,10 +1,10 @@
 all: mvdir
 
 mvdir: mvdir.sh
-	echo '#!$(SHELL)' | cat - mvdir.sh | sed ' \
+	echo '#!$(SHELL)' | cat - mvdir.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
-		s,@DEFLIB@,$(DEFLIB),g' >mvdir
+		s,@DEFLIB@,$(DEFLIB),g" >mvdir
 	chmod 755 mvdir
 
 install: all
