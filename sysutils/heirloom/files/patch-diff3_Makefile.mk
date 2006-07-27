--- ./diff3/Makefile.mk.orig	Thu May 29 21:35:23 2003
+++ ./diff3/Makefile.mk	Thu Jul 27 00:56:30 2006
@@ -1,10 +1,10 @@
 all: diff3 diff3prog
 
 diff3: diff3.sh
-	echo '#!$(SHELL)' | cat - diff3.sh | sed ' \
+	echo '#!$(SHELL)' | cat - diff3.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
-		s,@DEFLIB@,$(DEFLIB),g' >diff3
+		s,@DEFLIB@,$(DEFLIB),g" >diff3
 	chmod 755 diff3
 
 diff3prog: diff3prog.o
