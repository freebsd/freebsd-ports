
$FreeBSD$

--- docsis_snmp.c.orig	Tue Feb 11 16:36:30 2003
+++ docsis_snmp.c	Thu Feb 27 19:17:23 2003
@@ -206,6 +206,7 @@
   static char outbuf[1024];
   char *cp;
 
+    badtype = 0;
   memset (outbuf, 0, 1024);
 
   vp = (struct variable_list *) malloc (sizeof (struct variable_list));
