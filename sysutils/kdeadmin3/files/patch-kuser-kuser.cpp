--- kuser/kuser.cpp.orig	Wed Dec 10 22:03:21 2003
+++ kuser/kuser.cpp	Wed Dec 10 22:05:05 2003
@@ -479,6 +479,14 @@
 
   // Start reading passwd file(s)
 
+#ifdef Q_OS_FREEBSD
+  // For FreeBSD, some weird effect in the C++ libraries
+  // eats the first entry of the passwd file on -CURRENT,
+  // which renders KUser a system-destroyer instead of
+  // just a useless tool.
+  setpwent();
+#endif
+
   for(int i = 0; i < MAXFILES; i++) {
     rc = stat(QFile::encodeName(filename), &st);		
     if(rc != 0) {						
