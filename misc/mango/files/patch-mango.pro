--- mango.pro.orig	Wed Jan 15 17:01:32 2003
+++ mango.pro	Wed Jan 15 17:01:35 2003
@@ -11,6 +11,7 @@
 
 TEMPLATE =	app
 CONFIG	+= 	qt opengl warn_on debug
+INCLUDEPATH += ${PREFIX}/include/qextmdi
 unix:CONFIG +=	x11
 win32:CONFIG +=	windows
 #REQUIRES =	xml
