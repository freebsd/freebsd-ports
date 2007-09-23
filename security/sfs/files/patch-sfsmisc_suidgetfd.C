--- sfsmisc/suidgetfd.C.orig	2001-02-07 02:48:01.000000000 -0500
+++ sfsmisc/suidgetfd.C	2007-09-15 19:11:34.000000000 -0400
@@ -42,7 +42,7 @@
   close_on_exec (fds[0]);
 
   str path = fix_exec_path ("suidconnect");
-  char *av[] = { "suidconnect", const_cast<char *> (prog.cstr ()), NULL };
+  char *av[] = { const_cast<char *> ("suidconnect"), const_cast<char *> (prog.cstr ()), NULL };
   if (spawn (path, av, fds[1]) == -1) {
     close (fds[0]);
     close (fds[1]);
@@ -64,7 +64,7 @@
   close_on_exec (fds[0]);
 
   str path = fix_exec_path ("suidconnect");
-  char *av[] = { "suidconnect", const_cast<char *> (prog.cstr ()), NULL };
+  char *av[] = { const_cast<char *> ("suidconnect"), const_cast<char *> (prog.cstr ()), NULL };
   if (spawn (path, av, fds[1]) == -1)
     fatal << path << ": " << strerror (errno) << "\n";
   close (fds[1]);
