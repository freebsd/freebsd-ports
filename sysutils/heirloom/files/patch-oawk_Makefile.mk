--- oawk/Makefile.mk.orig	2004-10-03 02:23:20.000000000 +0800
+++ oawk/Makefile.mk	2013-07-26 18:34:22.000000000 +0800
@@ -4,9 +4,7 @@
 	$(LD) $(LDFLAGS) awk.g.o awk.lx.o b.o main.o token.o tran.o lib.o run.o parse.o proctab.o version.o $(LUXRE) -lm $(LCOMMON) $(LWCHAR) $(LIBS) -o awk
 
 awk.g.c: awk.g.y
-	$(YACC) -d awk.g.y
-	mv -f y.tab.c awk.g.c
-	mv -f y.tab.h awk.g.h
+	$(YACC) -d -o $@ awk.g.y
 
 token.c: awk.h
 	echo '#include "awk.h"' > $@
@@ -78,11 +76,11 @@
 awk.g.o: awk.def
 awk.g.o: awk.def
 awk.lx.o: awk.def
-b.o: awk.def
-lib.o: awk.def
-main.o: awk.def
-parse.o: awk.def
-proc.o: awk.def
+b.o: awk.def awk.h
+lib.o: awk.def awk.h
+main.o: awk.def awk.h
+parse.o: awk.def awk.h
+proc.o: awk.def awk.h
 proctab.o: awk.def
-run.o: awk.def
-tran.o: awk.def
+run.o: awk.def awk.h
+tran.o: awk.def awk.h
