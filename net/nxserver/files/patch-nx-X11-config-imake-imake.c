--- nx-X11/config/imake/imake.c.orig	2002-12-16 23:48:28.000000000 +0100
+++ nx-X11/config/imake/imake.c	2008-04-11 21:05:32.000000000 +0200
@@ -1146,6 +1146,7 @@
 static void
 get_binary_format(FILE *inFile)
 {
+#if 0
   int mib[2];
   size_t len;
   int osrel = 0;
@@ -1173,6 +1174,9 @@
   if (objprog)
     pclose(objprog);
 
+#else
+  int iself = 1;
+#endif
   fprintf(inFile, "#define DefaultToElfFormat %s\n", iself ? "YES" : "NO");
 }
 #endif
