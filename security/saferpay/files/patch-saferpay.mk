--- saferpay/saferpay.mk.orig	Tue Feb 18 16:58:08 2003
+++ saferpay/saferpay.mk	Tue Feb 18 16:58:50 2003
@@ -7,18 +7,11 @@
 
 ####### Compiler, tools and options
 
-#CC	=	/project/gcc31/bin/gcc
-#CXX	=	/project/gcc31/bin/g++
-
-CC	=	gcc
-CXX	=	g++
-
-CFLAGS	=	-pipe -fPIC -O2
-CXXFLAGS=	-pipe -fPIC -O2
+CFLAGS	+=	-fPIC
+CXXFLAGS +=	-fPIC
+LFLAGS	=	-fPIC -Lout
 INCPATH	=		
-#LINK	=	/project/gcc31/bin/g++
-LINK	=	g++
-LFLAGS	=	-fPIC
+LINK	=	$(CXX)
 LIBS	=	-lidpapp
 MOC	=	$(QTDIR)/bin/moc
 
