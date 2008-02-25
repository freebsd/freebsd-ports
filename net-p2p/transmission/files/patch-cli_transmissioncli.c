--- cli/transmissioncli.c.orig	2008-02-25 15:40:42.000000000 -0600
+++ cli/transmissioncli.c	2008-02-25 15:43:35.000000000 -0600
@@ -378,7 +378,7 @@
             { "upload",   required_argument,    NULL, 'u' },
             { "download", required_argument,    NULL, 'd' },
             { "finish",   required_argument,    NULL, 'f' },
-            { "create",   required_argument,    NULL, 'c' },
+            { "create-from", required_argument, NULL, 'c' },
             { "comment",  required_argument,    NULL, 'm' },
             { "announce", required_argument,    NULL, 'a' },
             { "nat-traversal", no_argument,     NULL, 'n' },
