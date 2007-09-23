--- agent/ssu.C.orig	2002-08-01 17:09:53.000000000 -0400
+++ agent/ssu.C	2007-09-15 19:44:20.000000000 -0400
@@ -87,7 +87,7 @@
   str cwdopt = getcwdopt ();
 
   vec<char *> av;
-  av.push_back (PATH_SU);
+  av.push_back (const_cast<char *> (PATH_SU));
 
   int ch;
   while ((ch = getopt (argc, argv, "fmlc:")) != -1)
@@ -111,8 +111,8 @@
   if (argc)
     usage ();
 
-  av.push_back ("root");
-  av.push_back ("-c");
+  av.push_back (const_cast<char *> ("root"));
+  av.push_back (const_cast<char *> ("-c"));
   {
     strbuf cbuf ("exec ");
     cbuf << fix_exec_path ("newaid") << " " << uidopt;
