Index: errors.c
diff -u errors.c.orig errors.c
--- errors.c.orig	Mon Mar  4 18:06:58 2002
+++ errors.c	Thu Oct 30 00:52:41 2003
@@ -77,8 +77,12 @@
     MAP(EAI_AGAIN)
     MAP(EAI_FAIL)
     MAP(EAI_MEMORY)
+#ifdef EAI_ADDRFAMILY
     MAP(EAI_ADDRFAMILY)
+#endif
+#if defined(EAI_NODATA) && EAI_NODATA != EAI_NONAME
     MAP(EAI_NODATA)
+#endif
     MAP(EAI_FAMILY)
     MAP(EAI_BADFLAGS)
     MAP(EAI_NONAME)
@@ -98,8 +102,12 @@
     MAP(EAI_AGAIN)
     MAP(EAI_FAIL)
     MAP(EAI_MEMORY)
+#ifdef EAI_ADDRFAMILY
     MAP(EAI_ADDRFAMILY)
+#endif
+#if defined(EAI_NODATA) && EAI_NODATA != EAI_NONAME
     MAP(EAI_NODATA)
+#endif
     MAP(EAI_FAMILY)
     MAP(EAI_BADFLAGS)
     MAP(EAI_NONAME)
