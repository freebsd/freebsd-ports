Index: imap/idled.c
diff -u imap/idled.c.orig imap/idled.c
--- imap/idled.c.orig	Thu Oct 23 03:50:07 2003
+++ imap/idled.c	Tue Jan 13 23:17:21 2004
@@ -409,3 +409,10 @@
     /* never gets here */      
     exit(1);
 }
+
+void printstring(const char *s __attribute__((unused)))
+{
+    /* needed to link against annotate.o */
+    fatal("printstring() executed, but its not used for IDLED!",
+	  EC_SOFTWARE);
+}
