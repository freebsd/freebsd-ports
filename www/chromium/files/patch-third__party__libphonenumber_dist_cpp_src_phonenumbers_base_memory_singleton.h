--- third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h.orig	2016-05-27 10:36:15.803726000 -0400
+++ third_party/libphonenumber/dist/cpp/src/phonenumbers/base/memory/singleton.h	2016-05-27 10:36:39.406818000 -0400
@@ -56,7 +56,7 @@
 #include "phonenumbers/base/logging.h"
 #include "phonenumbers/base/thread_checker.h"
 
-#if !defined(__linux__) && !defined(__APPLE__)
+#if !defined(__linux__) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 
 namespace i18n {
 namespace phonenumbers {
