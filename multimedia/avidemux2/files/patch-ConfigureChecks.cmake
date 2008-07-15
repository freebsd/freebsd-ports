--- ./ConfigureChecks.cmake.orig	2008-07-05 20:24:01.000000000 +0200
+++ ./ConfigureChecks.cmake	2008-07-10 17:16:26.000000000 +0200
@@ -220,6 +220,43 @@
 ENDIF (NO_NLS)
 
 ########################################
+# Execinfo
+########################################
+MESSAGE(STATUS "<Checking execinfo>")
+MESSAGE(STATUS "<******************************>")
+
+FIND_PATH(LIBEXECINFO_H_DIR execinfo.h $ENV{CXXFLAGS})
+MESSAGE(STATUS "libexecinfo Header Path: ${LIBEXECINFO_H_DIR}")
+
+IF (NOT LIBEXECINFO_H_DIR STREQUAL "LIBEXECINFO_H-NOTFOUND")
+        FIND_LIBRARY(LIBEXECINFO_LIB_DIR execinfo $ENV{CXXFLAGS})
+        MESSAGE(STATUS "libexecinfo Library Path: ${LIBEXECINFO_LIB_DIR}")
+
+        # Try linking without -lexecinfo
+        ADM_COMPILE(execinfo.cpp -I${LIBEXECINFO_H_DIR} "" WITHOUT_LIBEXECINFO outputWithoutLibexecinfo)
+
+        IF (WITHOUT_LIBEXECINFO)
+               SET(HAVE_EXECINFO 1)
+               MESSAGE(STATUS "OK, No lib needed (${ADM_EXECINFO_LIB})")
+        ELSE (WITHOUT_LIBEXECINFO)
+               ADM_COMPILE(execinfo.cpp -I${LIBEXECINFO_H_DIR} ${LIBEXECINFO_LIB_DIR} WITH_LIBEXECINFO outputWithLibexecinfo)
+
+               IF (WITH_LIBEXECINFO)
+                           SET(HAVE_EXECINFO 1)
+                            MESSAGE(STATUS "OK, libexecinfo needed")
+               ELSE (WITH_LIBEXECINFO)
+                            MESSAGE(STATUS "Does not work, without ${outputWithoutLibexecinfo}")
+                            MESSAGE(STATUS "Does not work, with ${outputWithLibexecinfo}")
+                        ENDIF (WITH_LIBEXECINFO)
+                ENDIF (WITHOUT_LIBEXECINFO)
+        ENDIF (NOT LIBEXECINFO_H_DIR STREQUAL "LIBEXECINFO_H-NOTFOUND")
+
+        IF (HAVE_EXECINFO)
+                SET(CMAKE_CLINK_FLAGS "${CFLAGS} -lexecinfo")
+                SET(CMAKE_CXX_LINK_FLAGS "${CXXFLAGS} -lexecinfo")
+        ENDIF(HAVE_EXECINFO)
+
+########################################
 # Locale
 ########################################
 SET(ADM_LOCALE "${CMAKE_INSTALL_PREFIX}/share/locale")
@@ -362,7 +399,9 @@
 # JACK
 ########################################
 IF (NOT ADM_OS_WINDOWS)
+	SET(CMAKE_REQUIRED_FLAGS "-pthread")
 	ADM_CHECK_HL(Jack jack/jack.h  jack jack_client_close USE_JACK)
+	SET(CMAKE_REQUIRED_FLAGS)
 ENDIF (NOT ADM_OS_WINDOWS)
 
 ########################################
@@ -475,7 +514,11 @@
 IF (USE_LATE_BINDING)
 	CHECK_INCLUDE_FILES(dts.h USE_LIBDCA)
 ELSE (USE_LATE_BINDING)
-	ADM_CHECK_HL(libdca dts.h dts dts_init USE_LIBDCA)
+       IF (ADM_BSD_FAMILY)
+               ADM_CHECK_HL(libdca dts.h dts dca_init USE_LIBDCA)
+       ELSE (ADM_BSD_FAMILY)
+               ADM_CHECK_HL(libdca dts.h dts dts_init USE_LIBDCA)
+       ENDIF (ADM_BSD_FAMILY)
 ENDIF (USE_LATE_BINDING)
 
 SET(CMAKE_REQUIRED_LIBRARIES)
@@ -489,7 +532,8 @@
 IF (ADM_OS_WINDOWS)
 	SET(CMAKE_REQUIRED_LIBRARIES "-lm -lpthreadGC2")
 ELSE (ADM_OS_WINDOWS)
-	SET(CMAKE_REQUIRED_LIBRARIES "-lm -lpthread")
+	SET(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} -pthread")
+	SET(CMAKE_REQUIRED_LIBRARIES "-lm")
 ENDIF (ADM_OS_WINDOWS)
 
 ADM_CHECK_HL(x264 x264.h x264 x264_encoder_open USE_X264)
