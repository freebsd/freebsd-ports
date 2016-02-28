--- dpinger.c.orig	2016-02-28 05:29:33 UTC
+++ dpinger.c
@@ -1018,7 +1018,7 @@ parse_args(
 
         default:
             usage();
-            fatal(NULL);
+            exit(EXIT_FAILURE);
         }
     }
 
@@ -1026,7 +1026,7 @@ parse_args(
     if (argc != optind + 1)
     {
         usage();
-        fatal(NULL);
+        exit(EXIT_FAILURE);
     }
     dest_arg = argv[optind];
 
