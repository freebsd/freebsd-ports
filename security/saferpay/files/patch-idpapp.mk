--- saferpay/idpapp.mk.orig	Thu Aug  8 16:15:49 2002
+++ saferpay/idpapp.mk	Wed Feb 19 11:06:35 2003
@@ -7,24 +7,12 @@
 
 ####### Compiler, tools and options
 
-# new ssl
-SSLVERSION = openssl-0.9.6c
-SSLEAYDIR = ./ssl
-SSLINCDIR = -I ./ssl
+SSLINCDIR = -I /usr/include/openssl
 
-
-
-#CC	=	/project/gcc31/bin/gcc
-#CXX	=	/project/gcc31/bin/g++
-
-CC	=	gcc
-CXX	=	g++
-
-CFLAGS	=	-pipe -DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -O2 -fPIC
-CXXFLAGS=	-pipe -DUNIX -O2 -fPIC
+CFLAGS	+=	-DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -fPIC
+CXXFLAGS +=	-DUNIX -fPIC
 INCPATH	=	-I"./xml" -I"./jni" -I"./sxfc" $(SSLINCDIR)
-#LINK	=	/project/gcc31/bin/g++
-LINK	=	g++
+LINK	=	${CXX}
 LFLAGS	=	-fPIC -shared
 LIBS	=	/usr/lib/libssl.a /usr/lib/libcrypto.a
 AR	=	ar cq
