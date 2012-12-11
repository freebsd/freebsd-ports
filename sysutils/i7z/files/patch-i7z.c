--- ./i7z.c.orig	2012-09-11 08:15:54.000000000 +0200
+++ ./i7z.c	2012-12-11 14:41:28.000000000 +0100
@@ -386,7 +386,11 @@
 
 void modprobing_msr()
 {
+#ifdef __linux__
     system("modprobe msr");
+#elif __FreeBSD__
+    system("kldload cpuctl");
+#endif
 }
 
 //Info: I start from index 1 when i talk about cores on CPU
