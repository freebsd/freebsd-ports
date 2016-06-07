--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h.orig	2016-05-27 10:37:19.349853000 -0400
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h	2016-05-27 10:37:52.605308000 -0400
@@ -37,7 +37,7 @@
 // Dummy lock implementation on non-POSIX platforms. If you are running on a
 // different platform and care about thread-safety, please compile with
 // -DI18N_PHONENUMBERS_USE_BOOST.
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 
 namespace i18n {
 namespace phonenumbers {
