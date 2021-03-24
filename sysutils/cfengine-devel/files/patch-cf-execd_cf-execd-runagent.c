--- cf-execd/cf-execd-runagent.c.orig	2021-03-19 07:11:45.000000000 -0700
+++ cf-execd/cf-execd-runagent.c	2021-03-24 01:35:29.063038000 -0700
@@ -22,6 +22,12 @@
   included file COSL.txt.
 */
 
+/*
+ * XXX: _WITH_GETLINE is required for FreeBSD-11.
+ * Remove when FreeBSD-11 is EOL.
+ */
+#define _WITH_GETLINE
+
 #include <stdio.h>
 
 #include <logging.h>
