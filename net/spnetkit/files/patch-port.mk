--- ../port/port.mk.orig	2008-02-17 15:31:19.000000000 +0800
+++ ../port/port.mk	2011-06-21 09:21:17.000000000 +0800
@@ -1,9 +1,9 @@
 
 #--------------------------------------------------------------------
 
-CC = gcc
+#CC = gcc
 AR = ar cru
-CFLAGS = -Wall -D_REENTRANT -D_GNU_SOURCE -g -fPIC
+CFLAGS += -Wall -D_REENTRANT -D_GNU_SOURCE -g -fPIC
 SOFLAGS = -shared -Wl,-h,$@
 LDFLAGS = -lstdc++ -lpthread
 
