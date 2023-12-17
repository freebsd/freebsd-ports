--- Userland/Libraries/LibCore/StandardPaths.cpp.orig	2023-12-17 14:07:18 UTC
+++ Userland/Libraries/LibCore/StandardPaths.cpp
@@ -12,6 +12,7 @@
 #include <AK/StringBuilder.h>
 #include <LibCore/SessionManagement.h>
 #include <LibCore/StandardPaths.h>
+#include <LibCore/System.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -107,6 +108,10 @@ ErrorOr<DeprecatedString> StandardPaths::runtime_direc
 #elif defined(AK_OS_MACOS)
     builder.append(home_directory());
     builder.append("/Library/Application Support"sv);
+#elif defined(AK_OS_FREEBSD)
+    auto uid = getuid();
+    builder.appendff("/tmp/{}", uid);
+    (void)Core::System::mkdir(builder.string_view(), 0700);
 #elif defined(AK_OS_HAIKU)
     builder.append("/boot/system/var/shared_memory"sv);
 #else
