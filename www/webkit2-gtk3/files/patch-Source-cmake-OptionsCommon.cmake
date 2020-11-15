--- Source/cmake/OptionsCommon.cmake.orig	2020-03-01 08:15:43.203077000 +1300
+++ Source/cmake/OptionsCommon.cmake	2020-03-01 08:14:23.672978000 +1300
@@ -155,7 +155,7 @@
 # Check for symbols
 WEBKIT_CHECK_HAVE_SYMBOL(HAVE_REGEX_H regexec regex.h)
 if (NOT (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin"))
-WEBKIT_CHECK_HAVE_SYMBOL(HAVE_PTHREAD_MAIN_NP pthread_main_np pthread_np.h)
+#WEBKIT_CHECK_HAVE_SYMBOL(HAVE_PTHREAD_MAIN_NP pthread_main_np pthread_np.h)
 endif ()
 # Windows has signal.h but is missing symbols that are used in calls to signal.
 WEBKIT_CHECK_HAVE_SYMBOL(HAVE_SIGNAL_H SIGTRAP signal.h)
