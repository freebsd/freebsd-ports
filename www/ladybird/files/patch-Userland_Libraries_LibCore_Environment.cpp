--- Userland/Libraries/LibCore/Environment.cpp.orig	2024-05-05 05:45:42 UTC
+++ Userland/Libraries/LibCore/Environment.cpp
@@ -13,7 +13,7 @@
 #if defined(AK_OS_MACOS) || defined(AK_OS_IOS)
 #    include <crt_externs.h>
 #else
-extern char** environ;
+extern "C" char** environ;
 #endif
 
 namespace Core::Environment {
@@ -93,7 +93,7 @@ Optional<StringView> get(StringView name, [[maybe_unus
     builder.append('\0');
     // Note the explicit null terminators above.
 
-#if defined(AK_OS_MACOS) || defined(AK_OS_ANDROID)
+#if defined(AK_OS_MACOS) || defined(AK_OS_ANDROID) || defined(__FreeBSD__) && __FreeBSD__ < 14
     char* result = ::getenv(builder.string_view().characters_without_null_termination());
 #else
     char* result;
@@ -158,10 +158,12 @@ ErrorOr<void> clear()
     for (size_t environ_size = 0; environment[environ_size]; ++environ_size) {
         environment[environ_size] = NULL;
     }
-#else
+#elif __FreeBSD__ >= 14
     auto rc = ::clearenv();
     if (rc < 0)
         return Error::from_errno(errno);
+#else
+    environ = NULL;
 #endif
     return {};
 }
