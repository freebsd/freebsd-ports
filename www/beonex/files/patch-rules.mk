$FreeBSD$

Enable compilation under -CURRENT.

author:  Trevor Johnson 

--- config/rules.mk.orig	Thu Aug 29 00:00:31 2002
+++ config/rules.mk	Wed Oct  2 01:15:29 2002
@@ -68,7 +68,6 @@
 topsrcdir		= $(DEPTH)
 endif
 
-CXX=gcc
 LDFLAGS += -Wl,-Bstatic -Wl,-lstdc++ -Wl,-Bdynamic
 
 
