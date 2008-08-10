--- mk/sk.global.mk.orig	2008-08-09 08:27:47.000000000 -0400
+++ mk/sk.global.mk	2008-08-09 08:29:12.000000000 -0400
@@ -51,10 +51,6 @@
 .PATH: ${.CURDIR}/${BASE_DIR}/mk/src
 PICFLAGS = -fpic
 
-.if ${OSTYPE} == "FreeBSD"
-.include    <bsd.sys.mk>
-.endif
-
 CXX?= c++
 
 AR?= ar
