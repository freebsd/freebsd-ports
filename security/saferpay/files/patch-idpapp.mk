--- saferpay/idpapp.mk.orig	Tue Jul 22 07:07:20 2003
+++ saferpay/idpapp.mk	Sat Mar 13 18:15:44 2004
@@ -1,19 +1,13 @@
 ####### Compiler, tools and options
 
-SSLVERSION = openssl-0.9.7b
-SSLEAYDIR = ./ssl
-SSLINCDIR = -I ./ssl
+SSLINCDIR = -I /usr/include/openssl
 
-
-CC	=	gcc
-CXX	=	g++
-
-CFLAGS	=	-pipe -DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -O2 -fPIC
-CXXFLAGS=	-pipe -DUNIX -O2 -fPIC
+CFLAGS	+=	-pipe -DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -O2 -fPIC
+CXXFLAGS+=	-pipe -DUNIX -O2 -fPIC
 INCPATH	=	-I"./xml" -I"./jni" -I"./sxfc" $(SSLINCDIR)
-LINK	=	g++
+LINK	+=	${CXX}
 LFLAGS	=	-fPIC -shared
-LIBS	=	/usr/lib/libssl.a /usr/lib/libcrypto.a
+LIBS	=	-lssl -lcrypto
 AR	=	ar cq
 RANLIB	=	
 MOC	=	moc
