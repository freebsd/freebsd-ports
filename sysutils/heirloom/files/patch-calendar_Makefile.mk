--- calendar/Makefile.mk.orig	Wed May 24 16:43:22 2006
+++ calendar/Makefile.mk	Wed Mar 28 10:58:09 2007
@@ -1,7 +1,7 @@
 all: calendar calprog
 
 calendar: calendar.sh
-	echo '#!$(SHELL)' | cat - calendar.sh | sed ' s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g' >calendar
+	echo '#!$(SHELL)' | cat - calendar.sh | sed " s,@DEFBIN@,$(DEFBIN),g; s,@SV3BIN@,$(SV3BIN),g; s,@DEFLIB@,$(DEFLIB),g" >calendar
 	chmod 755 calendar
 
 calprog: calprog.o
