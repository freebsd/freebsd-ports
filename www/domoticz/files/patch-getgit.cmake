--- getgit.cmake.old	2015-12-15 12:12:10.000000000 +0100
+++ getgit.cmake	2015-12-16 13:04:15.081839000 +0100
@@ -1,34 +1,35 @@
 # the git.cmake module is part of the standard distribution
-find_package(Git)
-if(NOT GIT_FOUND)
-  MESSAGE(FATAL_ERROR "Git not found!.")
-endif()
-
-MACRO(Gitversion_GET_REVISION dir variable)
-  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} rev-list HEAD --count
-    OUTPUT_VARIABLE ${variable}
-    OUTPUT_STRIP_TRAILING_WHITESPACE)
-ENDMACRO(Gitversion_GET_REVISION)
-
-MACRO(Gitversion_GET_HASH dir variable)
-  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
-    OUTPUT_VARIABLE ${variable}
-    OUTPUT_STRIP_TRAILING_WHITESPACE)
-ENDMACRO(Gitversion_GET_HASH)
-
-MACRO(Gitversion_GET_DATE dir variable)
-  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} show -s --format=%ct
-    OUTPUT_VARIABLE ${variable}
-    OUTPUT_STRIP_TRAILING_WHITESPACE)
-ENDMACRO(Gitversion_GET_DATE)
-
-Gitversion_GET_REVISION(. ProjectRevision)
-Gitversion_GET_HASH(. ProjectHash)
-Gitversion_GET_DATE(. ProjectDate)
+#find_package(Git)
+#if(NOT GIT_FOUND)
+#  MESSAGE(FATAL_ERROR "Git not found!.")
+#endif()
+#
+#MACRO(Gitversion_GET_REVISION dir variable)
+#  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} rev-list HEAD --count
+#    OUTPUT_VARIABLE ${variable}
+#    OUTPUT_STRIP_TRAILING_WHITESPACE)
+#ENDMACRO(Gitversion_GET_REVISION)
+#
+#MACRO(Gitversion_GET_HASH dir variable)
+#  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
+#    OUTPUT_VARIABLE ${variable}
+#    OUTPUT_STRIP_TRAILING_WHITESPACE)
+#ENDMACRO(Gitversion_GET_HASH)
+#
+#MACRO(Gitversion_GET_DATE dir variable)
+#  EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} show -s --format=%ct
+#    OUTPUT_VARIABLE ${variable}
+#    OUTPUT_STRIP_TRAILING_WHITESPACE)
+#ENDMACRO(Gitversion_GET_DATE)
+#
+#Gitversion_GET_REVISION(. ProjectRevision)
+#Gitversion_GET_HASH(. ProjectHash)
+#Gitversion_GET_DATE(. ProjectDate)
 
 # write a file with the APPVERSION define
-MATH(EXPR ProjectRevision "${ProjectRevision}+2107")
-file(WRITE appversion.h.txt "#define APPVERSION ${ProjectRevision}\n#define APPHASH \"${ProjectHash}\"\n#define APPDATE ${ProjectDate}\n")
+#MATH(EXPR ProjectRevision "${ProjectRevision}+2107")
+#file(WRITE appversion.h.txt "#define APPVERSION ${ProjectRevision}\n#define APPHASH \"${ProjectHash}\"\n#define APPDATE ${ProjectDate}\n")
+file(WRITE appversion.h.txt "#define APPVERSION XXXDOMOTICZXXX\n#define APPHASH \"XXXHASHXXX\"\n#define APPDATE XXXTIMEXXX\n")
 # copy the file to the final header only if the version changes
 # reduces needless rebuilds
 
