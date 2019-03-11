--- test/help_dialog.cxx.orig	2019-03-03 08:40:23 UTC
+++ test/help_dialog.cxx
@@ -46,13 +46,13 @@ main(int  argc,			// I - Number of command-line argume
     strcpy(buf, argv[0]);
     char *slash = strrchr(buf, '/');
     if (slash)
-      strcpy(slash, "/../Resources/help-test.html");
+      strcpy(slash, "/../Resources/help_dialog.html");
     help->load(buf);
   
 #else
   
   if (argc <= 1)
-    help->load("help-test.html");
+    help->load("help_dialog.html");
   else
     help->load(argv[1]);
   
