--- src/send.cc.orig	Sat Jan  4 04:58:31 2003
+++ src/send.cc	Sun Nov 28 18:49:02 2004
@@ -166,7 +166,7 @@
   unsigned i = 0;
   args[i++] = program.c_str();
   for(slist::const_iter opt(remote.options); opt; opt++)
-    args[i++] = (*opt).c_str();
+    args[i++] = strdup((*opt).c_str());
   args[i++] = remote.host.c_str();
   args[i++] = 0;
   execv(args[0], (char**)args);
