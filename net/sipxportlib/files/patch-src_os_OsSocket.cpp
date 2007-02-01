--- ./src/os/OsSocket.cpp.orig	Tue Jan  2 17:37:30 2007
+++ ./src/os/OsSocket.cpp	Sat Jan  6 22:41:02 2007
@@ -165,7 +165,7 @@
 
    int flags = 0;
 
-#if defined(__linux__) || defined(sun)
+#if defined(__linux__) || defined(sun) || defined(__FreeBSD__)
    // We do not want send to throw signals if there is a
    // problem with the socket as this results in the process
    // getting aborted. We just want it to return an error.
@@ -224,7 +224,7 @@
 
    int flags = 0;
 
-#if defined(__linux__) || defined(sun)
+#if defined(__linux__) || defined(sun) || defined(__FreeBSD__)
    // We do not want send to throw signals if there is a
    // problem with the socket as this results in the process
    // getting aborted. We just want it to return an error.
@@ -275,7 +275,7 @@
 
    int flags = 0;
 
-#if defined(__linux__) || defined(sun)
+#if defined(__linux__) || defined(sun) || defined(__FreeBSD__)
    // We do not want send to throw signals if there is a
    // problem with the socket as this results in the process
    // getting aborted. We just want it to return an error.
