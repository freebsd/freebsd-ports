--- saferpay/saferpay.mk.orig	Fri Dec 15 02:54:13 2000
+++ saferpay/saferpay.mk	Wed Sep 12 07:07:34 2001
@@ -7,13 +7,13 @@
 
 ####### Compiler, tools and options
 
-CC	=	gcc
-CXX	=	g++
-CFLAGS	=	-pipe -O2
-CXXFLAGS=	-pipe -O2
+#CC	=	gcc
+#CXX	=	g++
+#CFLAGS	=	-pipe -O2
+#CXXFLAGS=	-pipe -O2
 INCPATH	=	
-LINK	=	g++
-LFLAGS	=	
+LINK	=	$(CXX)
+LFLAGS	=	-Lout
 LIBS	=	-lidpapp
 MOC	=	$(QTDIR)/bin/moc
 
