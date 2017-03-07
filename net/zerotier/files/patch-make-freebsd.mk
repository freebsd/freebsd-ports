--- make-freebsd.mk.orig	2016-07-22 03:29:15 UTC
+++ make-freebsd.mk
@@ -1,5 +1,5 @@
-CC=cc
-CXX=c++
+CC?=cc
+CXX?=c++
 
 INCLUDES=
 DEFS=
@@ -18,6 +18,14 @@ ifeq ($(ZT_ENABLE_CLUSTER),1)
 	DEFS+=-DZT_ENABLE_CLUSTER
 endif
 
+# Build with ZT_ENABLE_NETWORK_CONTROLLER=1 to build with SQLite network controller
+ifeq ($(ZT_ENABLE_NETWORK_CONTROLLER),1)
+	DEFS+=-DZT_ENABLE_NETWORK_CONTROLLER
+	INCLUDES+=-I$(LOCALBASE)/include
+	LDFLAGS+=-L$(LOCALBASE)/lib -lsqlite3
+	OBJS+=controller/SqliteNetworkController.o
+endif
+
 # "make debug" is a shortcut for this
 ifeq ($(ZT_DEBUG),1)
 	DEFS+=-DZT_TRACE
