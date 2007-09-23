--- rex/ptyd.C.orig	2007-09-23 03:02:05.000000000 -0400
+++ rex/ptyd.C	2007-09-23 03:03:45.000000000 -0400
@@ -94,13 +94,13 @@
     return -1;
 
   vec<char *> argv;
-  argv.push_back ("sessreg");
+  argv.push_back (const_cast<char *> ("sessreg"));
   if (add)
-    argv.push_back ("-a");
+    argv.push_back (const_cast<char *> ("-a"));
   else
-    argv.push_back ("-d");
+    argv.push_back (const_cast<char *> ("-d"));
 
-  argv.push_back ("-l");
+  argv.push_back (const_cast<char *> ("-l"));
   if (tty && !strncmp ("/dev/", tty, 5) && tty[5])
     tmp = const_cast<char *> (&tty[5]);
   else {
@@ -110,10 +110,10 @@
   if (tmp)
     argv.push_back (tmp);
   else
-    argv.push_back ("?");
+    argv.push_back (const_cast<char *> ("?"));
 
   if (host) {
-    argv.push_back ("-h");
+    argv.push_back (const_cast<char *> ("-h"));
     argv.push_back (const_cast<char *> (host));
   }
 
@@ -121,7 +121,7 @@
   int slot = myttyslot (tty);
   if (slot > 0) {
     str s = strbuf () << slot;
-    argv.push_back ("-s");
+    argv.push_back (const_cast<char *> ("-s"));
     argv.push_back (const_cast<char *> (s.cstr ()));
   }
 #endif /* USE_TTYENT */
