--- cmake/admCheckMiscLibs.cmake.orig
+++ cmake/admCheckMiscLibs.cmake
@@ -103,3 +103,41 @@ ELSE (USE_SYSTEM_SPIDERMONKEY)
 ENDIF (USE_SYSTEM_SPIDERMONKEY)
 
 MESSAGE("")
+########################################
+# Execinfo
+########################################
+MESSAGE(STATUS "Checking for execinfo")
+MESSAGE(STATUS "*********************")
+
+FIND_PATH(LIBEXECINFO_H_DIR execinfo.h $ENV{CXXFLAGS})
+MESSAGE(STATUS "libexecinfo Header Path: ${LIBEXECINFO_H_DIR}")
+
+IF (NOT LIBEXECINFO_H_DIR STREQUAL "LIBEXECINFO_H-NOTFOUND")
+        FIND_LIBRARY(LIBEXECINFO_LIB_DIR execinfo $ENV{CXXFLAGS})
+        MESSAGE(STATUS "libexecinfo Library Path: ${LIBEXECINFO_LIB_DIR}")
+
+        # Try linking without -lexecinfo
+        ADM_COMPILE(execinfo.cpp "" ${LIBEXECINFO_H_DIR} "" WITHOUT_LIBEXECINFO outputWithoutLibexecinfo)
+
+        IF (WITHOUT_LIBEXECINFO)
+               SET(HAVE_EXECINFO 1)
+               MESSAGE(STATUS "OK, No lib needed (${ADM_EXECINFO_LIB})")
+        ELSE (WITHOUT_LIBEXECINFO)
+               ADM_COMPILE(execinfo.cpp "" ${LIBEXECINFO_H_DIR} ${LIBEXECINFO_LIB_DIR} WITH_LIBEXECINFO outputWithLibexecinfo)
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
+MESSAGE("")
