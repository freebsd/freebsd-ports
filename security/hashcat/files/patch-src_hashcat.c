--- src/hashcat.c.orig	2016-06-28 09:47:32 UTC
+++ src/hashcat.c
@@ -6,7 +6,7 @@
  * License.....: MIT
  */
 
-#ifdef DARWIN
+#if defined(DARWIN) || defined(__FreeBSD__)
 #include <stdio.h>
 #endif
 
@@ -6134,7 +6134,7 @@ int main (int argc, char **argv)
 
   char *exec_path = get_exec_path ();
 
-  #ifdef LINUX
+  #if defined(LINUX) || defined(__FreeBSD__)
 
   char *resolved_install_folder = realpath (INSTALL_FOLDER, NULL);
   char *resolved_exec_path      = realpath (exec_path, NULL);
