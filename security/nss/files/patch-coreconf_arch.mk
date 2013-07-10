--- coreconf/arch.mk.orig	2011-03-03 18:13:52.000000000 +0100
+++ coreconf/arch.mk	2011-03-03 18:14:09.000000000 +0100
@@ -66,7 +66,7 @@
 # Attempt to differentiate between sparc and x86 Solaris
 #
 
-OS_TEST := $(shell uname -m)
+OS_TEST := $(shell uname -p)
 ifeq ($(OS_TEST),i86pc)
     OS_RELEASE := $(shell uname -r)_$(OS_TEST)
 else
