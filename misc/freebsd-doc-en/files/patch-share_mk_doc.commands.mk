--- share/mk/doc.commands.mk.orig	2020-03-21 12:09:18 UTC
+++ share/mk/doc.commands.mk
@@ -139,15 +139,15 @@ PNMTOPSOPTS?=	-noturn ${PNMTOPSFLAGS}
 EPSTOPDF?=	${PREFIX}/bin/epstopdf
 EPSTOPDFOPTS?=	${EPSTOPDFFLAGS}
 #
-PIC2PS?=	${GROFF} -p -S -Wall -mtty-char -man
+PIC2PS?=	${GROFF} -p -P-pa4 -S -Wall -mtty-char -man
 #
 PS2EPS?=	${PREFIX}/bin/gs
 PS2EPSOPTS?=	-q -dNOPAUSE -dSAFER -dDELAYSAFER \
-		-sPAPERSIZE=letter -r72 -sDEVICE=bit \
+		-sPAPERSIZE=a4 -r72 -sDEVICE=bit \
 		-sOutputFile=/dev/null ${PS2EPSFLAGS} ps2epsi.ps
 PS2BBOX?=	${PREFIX}/bin/gs
 PS2BBOXOPTS?=	-q -dNOPAUSE -dBATCH -dSAFER -dDELAYSAFER \
-		-sPAPERSIZE=letter -r72 -sDEVICE=bbox \
+		-sPAPERSIZE=a4 -r72 -sDEVICE=bbox \
 		-sOutputFile=/dev/null ${PS2BBOXFLAGS}
 
 #
