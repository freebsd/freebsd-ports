--- security/coreconf/FreeBSD.mk	Thu Oct 16 23:03:47 2003
+++ security/coreconf/FreeBSD.mk	Thu Oct 16 22:53:11 2003
@@ -44,5 +44,9 @@
 CPU_ARCH		= alpha
 else
+ifeq ($(OS_TEST),amd64)
+CPU_ARCH		= amd64
+else
 CPU_ARCH		= x86
+endif
 endif
 
