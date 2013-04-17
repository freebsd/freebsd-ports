--- _keychain_dbus.cpp	2013-03-25 20:32:44.801564594 +0400
+++ keychain_dbus.cpp	2013-03-25 20:32:49.811561714 +0400
@@ -10,7 +10,7 @@
 
 #include <QSettings>
 
-#include <auto_ptr.h>
+#include <memory>
 
 using namespace QKeychain;
 
