--- saferpay/saferpay.mk.orig	Tue Jul 22 16:08:35 2003
+++ saferpay/saferpay.mk	Tue Jan  6 15:10:05 2004
@@ -1,13 +1,11 @@
 ####### Compiler, tools and options
-CC	=	gcc
-CXX	=	g++
 
-CFLAGS	=	-pipe -fPIC -O2
-CXXFLAGS=	-pipe -fPIC -O2
+CFLAGS		+=	-fPIC
+CXXFLAGS	+=	-fPIC
 INCPATH	=		
 
-LINK	=	g++
-LFLAGS	=	-fPIC -ldl
+LINK	+=	$(CXX) -Lout
+LFLAGS	+=	-fPIC
 LIBS	=	-lidpapp
 MOC	=	$(QTDIR)/bin/moc
 
