--- CMake/FindJNI.cmake.orig	2010-06-29 07:44:57 UTC
+++ CMake/FindJNI.cmake
@@ -98,6 +98,7 @@ JAVA_APPEND_LIBRARY_DIRECTORIES(JAVA_AWT
   /usr/lib/jvm/default-java/jre/lib
   /usr/lib/jvm/default-java/lib
   # FreeBSD specific paths for default JVM
+  /usr/local/openjdk8/jre/lib/{libarch}
   /usr/local/openjdk7/jre/lib/{libarch}
   /usr/local/openjdk6/jre/lib/{libarch}
   /usr/local/diablo-jdk1.6.0/jre/lib/{libarch}
@@ -138,6 +139,7 @@ SET(JAVA_AWT_INCLUDE_DIRECTORIES
   # Debian specific path for default JVM
   /usr/lib/jvm/default-java/include
   # FreeBSD specific path for default JVM
+  /usr/local/openjdk8/include
   /usr/local/openjdk7/include
   /usr/local/openjdk6/include
   /usr/local/diablo-jdk1.6.0/include
