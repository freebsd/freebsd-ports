--- libpbe/src/SmtpClient.cc.orig	2008-05-24 14:24:47.000000000 +0200
+++ libpbe/src/SmtpClient.cc	2013-03-30 17:41:19.000000000 +0100
@@ -22,6 +22,7 @@
 
 #include <syslog.h>
 #include <unistd.h>
+#include <stdio.h>
 
 #ifdef __OpenBSD__
 // Is this really needed?
