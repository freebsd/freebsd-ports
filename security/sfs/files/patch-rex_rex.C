--- rex/rex.C.orig	2002-11-19 14:58:44.000000000 -0500
+++ rex/rex.C	2007-09-15 19:48:38.000000000 -0400
@@ -746,7 +746,7 @@
   vec<str> cmd2vec (str cmdstr) {
     char *cmd = const_cast<char *> (cmdstr.cstr ());
     vec<str> cmdvec;
-    char *word, *sep = "\t ";
+    char *word, *sep = const_cast<char *> ("\t ");
     for (word = strtok(cmd, sep); word; word = strtok(NULL, sep))
       cmdvec.push_back (word);
     return cmdvec;
@@ -962,7 +962,7 @@
 main (int argc, char **argv)
 {
   setprogname (argv[0]);
-  putenv ("POSIXLY_CORRECT=1");	// Prevents Linux from reordering options
+  putenv (const_cast<char *> ("POSIXLY_CORRECT=1"));	// Prevents Linux from reordering options
   sfsconst_init ();
 
   int ch;
