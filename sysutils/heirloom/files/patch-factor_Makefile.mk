--- factor/Makefile.mk.orig	2012-12-03 10:01:29.000000000 +0100
+++ factor/Makefile.mk	2012-12-03 10:01:48.000000000 +0100
@@ -22,7 +22,7 @@
 	$(CC) ___build$$$$.c -lm -o ___build$$$$ >/dev/null 2>&1 ; \
 	if test $$? = 0 && test -f ___build$$$$ ; \
 	then	\
-		echo '#if !defined (__dietlibc__) && !defined (_AIX)' >>config.h ; \
+		echo '#if !defined (__dietlibc__) && !defined (_AIX) && !defined (__FreeBSD__)' >>config.h ; \
 		echo '#define	USE_LONG_DOUBLE' >>config.h ; \
 		echo '#endif' >>config.h ; \
 	fi ; \
