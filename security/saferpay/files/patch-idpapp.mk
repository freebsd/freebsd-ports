--- saferpay/idpapp.mk.orig	Tue Jan  6 15:33:08 2004
+++ saferpay/idpapp.mk	Tue Jan  6 15:34:28 2004
@@ -1,17 +1,11 @@
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
 LIBS	=	/usr/lib/libssl.a /usr/lib/libcrypto.a
 AR	=	ar cq
