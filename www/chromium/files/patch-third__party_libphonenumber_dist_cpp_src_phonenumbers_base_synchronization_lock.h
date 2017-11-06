--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h.orig	2017-06-05 19:04:19 UTC
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/synchronization/lock.h
@@ -37,7 +37,7 @@ typedef boost::mutex::scoped_lock AutoLock;
 // Dummy lock implementation on non-POSIX platforms. If you are running on a
 // different platform and care about thread-safety, please compile with
 // -DI18N_PHONENUMBERS_USE_BOOST.
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 
 namespace i18n {
 namespace phonenumbers {
