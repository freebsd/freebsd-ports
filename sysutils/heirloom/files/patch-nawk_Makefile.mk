--- nawk/Makefile.mk.orig	2005-02-09 23:58:39.000000000 +0800
+++ nawk/Makefile.mk	2013-07-26 18:01:39.000000000 +0800
@@ -12,14 +12,14 @@
 	$(LD) $(LDFLAGS) awk.g.2001.o $(OBJ) version_su3.o $(LUXRE) -lm $(LCOMMON) $(LWCHAR) $(LIBS) -o awk_su3
 
 awk.g.c: awk.g.y
-	$(YACC) -d awk.g.y
-	mv -f y.tab.c awk.g.c
+	$(YACC) -d awk.g.y && mv -f y.tab.c awk.g.c
+
+y.tab.h: awk.g.y | awk.g.c
 	(echo '1i'; echo '#include <inttypes.h>'; echo '.'; echo 'w';) | \
 		ed -s y.tab.h
 
 awk.g.2001.c: awk.g.2001.y awk.g.c
-	$(YACC) awk.g.2001.y
-	mv -f y.tab.c awk.g.2001.c
+	$(YACC) awk.g.2001.y && mv -f y.tab.c awk.g.2001.c
 
 awk.g.2001.y: awk.g.y
 	sed -f rerule.sed <awk.g.y >awk.g.2001.y
