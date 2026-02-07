--- lib/ipvalidator.h.orig	2020-01-29 20:40:04 UTC
+++ lib/ipvalidator.h
@@ -13,6 +13,11 @@
 #include <QString>
 #include <QValidator>
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 /* Validating IPv4/6 is not as trivial as thought.
  * - The QHostAddress class requires the network library
  *   and i don't want to add many megabytes for this validator
