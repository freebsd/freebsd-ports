--- bogosort.c	6 Sep 2002 08:46:36 -0000	1.1.1.3
+++ bogosort.c	6 Sep 2002 08:50:10 -0000	1.3
@@ -77,10 +77,11 @@
 
     /* The name the program was run with */
     /* stripped of any leading path.     */
-    program_name = strrchr(argv[0], '/') + 1;
+    program_name = strrchr(argv[0], '/');
     if (program_name == NULL)
-        program_name = argv[0];
-
+	    program_name = argv[0];
+    else
+	    program_name++;
 
     nextarg = decode_switches(argc, argv);
 
