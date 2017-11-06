--- tests/signond-tests/mock-ac-plugin/access-control-manager.h.orig	2015-10-14 15:57:12 UTC
+++ tests/signond-tests/mock-ac-plugin/access-control-manager.h
@@ -25,6 +25,9 @@
 
 #include <SignOn/AbstractAccessControlManager>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 class AccessControlManager: public SignOn::AbstractAccessControlManager
 {
     Q_OBJECT
