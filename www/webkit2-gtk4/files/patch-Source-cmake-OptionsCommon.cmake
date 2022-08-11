--- Source/cmake/OptionsCommon.cmake.orig	2021-09-22 23:05:58 UTC
+++ Source/cmake/OptionsCommon.cmake
@@ -144,7 +144,7 @@ WEBKIT_CHECK_HAVE_FUNCTION(HAVE_VASPRINTF vasprintf)
 # Check for symbols
 WEBKIT_CHECK_HAVE_SYMBOL(HAVE_REGEX_H regexec regex.h)
 if (NOT (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin"))
-    WEBKIT_CHECK_HAVE_SYMBOL(HAVE_PTHREAD_MAIN_NP pthread_main_np pthread_np.h)
+	#WEBKIT_CHECK_HAVE_SYMBOL(HAVE_PTHREAD_MAIN_NP pthread_main_np pthread_np.h)
 endif ()
 WEBKIT_CHECK_HAVE_SYMBOL(HAVE_TIMINGSAFE_BCMP timingsafe_bcmp string.h)
 # Windows has signal.h but is missing symbols that are used in calls to signal.
