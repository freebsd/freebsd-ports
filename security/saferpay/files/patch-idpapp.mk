--- saferpay/idpapp.mk.orig	Fri Dec 15 02:54:02 2000
+++ saferpay/idpapp.mk	Wed Sep 12 07:07:24 2001
@@ -7,14 +7,14 @@
 
 ####### Compiler, tools and options
 
-CC	=	gcc
-CXX	=	g++
-CFLAGS	=	-pipe -DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -O2 -fPIC
-CXXFLAGS=	-pipe -DUNIX -O2 -fPIC
-INCPATH	=	-I"./xml" -I"./jni" -I"./ssl" -I"./sxfc"
-LINK	=	g++
+#CC	=	gcc
+#CXX	=	g++
+CFLAGS	+=	-DUNIX -DHAVE_UNISTD_H -DHAVE_STDLIB_H -fPIC
+CXXFLAGS+=	-DUNIX -fPIC
+INCPATH	=	-I"./xml" -I"./jni" -I"/usr/include/openssl/" -I"./sxfc"
+LINK	=	$(CXX)
 LFLAGS	=	-fPIC -shared -Wl,-soname,libidpapp.so.1
-LIBS	=	./ssl/libssl.a ./ssl/libcrypto.a
+LIBS	=	/usr/lib/libssl.a /usr/lib/libcrypto.a
 AR	=	ar cqs
 RANLIB	=	
 MOC	=	$(QTDIR)/bin/moc
