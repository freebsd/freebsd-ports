--- src/drivers.c	Thu Apr 20 23:51:30 2006
+++ ../wmnd-0.4.12-p/src/drivers.c	Thu Apr  5 22:05:34 2007
@@ -570,7 +570,8 @@
   struct freebsd_sysctl_drvdata* drdata;
   int numifaces, numrfaces = 0;
   int mib[5], datamib[6];
-  int i, len, len2;
+  int i; 
+  size_t len, len2;
 
   mib[0] = CTL_NET;
   mib[1] = PF_LINK;
@@ -636,7 +637,7 @@
 {
   struct freebsd_sysctl_drvdata* drdata = dev->drvdata;
   int datamib[6];
-  int len;
+  size_t len;
 
   *ip = *op = *ib = *ob = 0;
 
