--- Makefile.m4.orig	2013-01-15 00:37:00.032987000 +0100
+++ Makefile.m4	2013-01-15 00:44:01.343576000 +0100
@@ -13,6 +13,7 @@
 ifelse(substr(OS,0,7),[MINGW32],[define([OS],[MINGW32])])
 ifelse(OS,NetBSD,[define([OS],[BSD])CXXFLAGS+=-D__unix])
 ifelse(OS,OpenBSD,[define([OS],[BSD])])
+ifelse(OS,DragonFly,[define([OS],[BSD])LDLIBS=-lcam])
 ifelse(OS,FreeBSD,[define([OS],[BSD])LDLIBS=-lcam])
 ifelse(OS,IRIX64,[define([OS],[IRIX])])
 
