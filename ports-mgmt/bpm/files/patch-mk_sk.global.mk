--- mk/sk.global.mk.orig	2004-08-24 04:03:29 UTC
+++ mk/sk.global.mk
@@ -51,10 +51,6 @@ CPPFLAGS+= -I${.CURDIR}/${BASE_DIR}/mk/i
 .PATH: ${.CURDIR}/${BASE_DIR}/mk/src
 PICFLAGS = -fpic
 
-.if ${OSTYPE} == "FreeBSD"
-.include    <bsd.sys.mk>
-.endif
-
 CXX?= c++
 
 AR?= ar
