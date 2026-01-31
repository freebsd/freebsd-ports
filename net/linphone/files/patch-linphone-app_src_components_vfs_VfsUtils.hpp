--- linphone-app/src/components/vfs/VfsUtils.hpp.orig	2025-12-26 08:02:03 UTC
+++ linphone-app/src/components/vfs/VfsUtils.hpp
@@ -26,7 +26,7 @@
 #ifdef QTKEYCHAIN_USE_BUILD_INTERFACE
 #include <keychain.h>
 #elif defined(QTKEYCHAIN_TARGET_NAME)
-#define KEYCHAIN_HEADER <QTKEYCHAIN_TARGET_NAME/keychain.h>
+#define KEYCHAIN_HEADER <qt5keychain/keychain.h>
 #include KEYCHAIN_HEADER
 #else
 #include <EQt5Keychain/keychain.h>
