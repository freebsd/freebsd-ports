--- services/shell/runner/init.cc.orig	2016-08-05 14:09:25.990401000 -0400
+++ services/shell/runner/init.cc	2016-08-05 14:09:42.644514000 -0400
@@ -77,6 +77,7 @@
 void CallLibraryEarlyInitialization(base::NativeLibrary app_library) {
   // Do whatever warming that the mojo application wants.
 
+#if !defined(__FreeBSD__)
 #if ICU_UTIL_DATA_IMPL == ICU_UTIL_DATA_FILE
   typedef void (*LibraryEarlyInitFunction)(const uint8_t*);
   LibraryEarlyInitFunction init_function =
@@ -90,6 +91,7 @@
     init_function(icu_data);
   }
 #endif  // ICU_UTIL_DATA_IMPL == ICU_UTIL_DATA_FILE
+#endif
 
   // TODO(erg): All chromium binaries load base. We might want to make a
   // general system for other people.
