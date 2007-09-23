--- rex/chan.C.orig	2007-09-15 19:54:59.000000000 -0400
+++ rex/chan.C	2007-09-15 19:55:32.000000000 -0400
@@ -366,10 +366,10 @@
       av.push_back (default_shell);
     else {
       warn ("SHELL not set, reverting to sh\n");
-      av.push_back ("sh");
+      av.push_back (const_cast<char *> ("sh"));
     }
     if (argp->av.size () == 1)
-      av.push_back ("-i");
+      av.push_back (const_cast<char *> ("-i"));
   }
   else
     av.push_back (const_cast<char *> (argp->av[0].cstr ()));
