--- agent/mibgroup/mibII/at.c.orig	2008-12-25 10:40:04.000000000 +0900
+++ agent/mibgroup/mibII/at.c	2008-12-25 10:40:59.000000000 +0900
@@ -686,7 +686,11 @@
     mib[2] = 0;
     mib[3] = AF_INET;
     mib[4] = NET_RT_FLAGS;
+#if defined(RTF_LLINFO)
     mib[5] = RTF_LLINFO;
+#else
+    mib[5] = 0;
+#endif
 
     if (at)
         free(at);
