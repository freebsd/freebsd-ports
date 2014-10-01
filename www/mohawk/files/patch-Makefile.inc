--- Makefile.inc.orig	2014-09-15 17:40:01 UTC
+++ Makefile.inc
@@ -16,13 +16,8 @@ OSVERSION!= sysctl -n kern.osreldate
 YFLAGS+= -i
 CLEANFILES+=	parse.i
 .endif
-.if ${OPSYS} == "DragonFly"
-LDFLAGS+= -L${PREFIX}/lib/event2
-LDADD+=   -levent-2.0
-.else
 LDFLAGS+= -L${PREFIX}/lib
 LDADD+=   -levent
-.endif
 
 .elif ${OPSYS} == "NetBSD"
 PREFIX?=  /usr/pkg
