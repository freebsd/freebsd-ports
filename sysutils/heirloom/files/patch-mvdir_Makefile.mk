--- mvdir/Makefile.mk.orig	Wed May 24 16:45:48 2006
+++ mvdir/Makefile.mk	Wed Mar 28 11:03:32 2007
@@ -1,7 +1,7 @@
 all: mvdir
 
 mvdir: mvdir.sh
-	echo '#!$(SHELL)' | cat - mvdir.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g' >mvdir
+	echo '#!$(SHELL)' | cat - mvdir.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g" >mvdir
 	chmod 755 mvdir
 
 install: all
