--- ./calendar/Makefile.mk.orig	Sat May  1 18:58:02 2004
+++ ./calendar/Makefile.mk	Thu Jul 27 00:52:02 2006
@@ -1,10 +1,10 @@
 all: calendar calprog
 
 calendar: calendar.sh
-	echo '#!$(SHELL)' | cat - calendar.sh | sed ' \
+	echo '#!$(SHELL)' | cat - calendar.sh | sed " \
 		s,@DEFBIN@,$(DEFBIN),g; \
 		s,@SV3BIN@,$(SV3BIN),g; \
-		s,@DEFLIB@,$(DEFLIB),g' >calendar
+		s,@DEFLIB@,$(DEFLIB),g" >calendar
 	chmod 755 calendar
 
 calprog: calprog.o
