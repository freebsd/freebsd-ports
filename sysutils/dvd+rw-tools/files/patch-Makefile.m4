--- Makefile.m4.orig	2008-03-02 17:17:09 UTC
+++ Makefile.m4
@@ -13,6 +13,7 @@ ifelse(substr(OS,0,7),[CYGWIN_],[define(
 ifelse(substr(OS,0,7),[MINGW32],[define([OS],[MINGW32])])
 ifelse(OS,NetBSD,[define([OS],[BSD])CXXFLAGS+=-D__unix])
 ifelse(OS,OpenBSD,[define([OS],[BSD])])
+ifelse(OS,DragonFly,[define([OS],[BSD])LDLIBS=-lcam])
 ifelse(OS,FreeBSD,[define([OS],[BSD])LDLIBS=-lcam])
 ifelse(OS,IRIX64,[define([OS],[IRIX])])
 
