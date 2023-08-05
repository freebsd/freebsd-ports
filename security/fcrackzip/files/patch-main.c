--- main.c.orig	2023-07-24 19:20:45 UTC
+++ main.c
@@ -351,7 +351,7 @@ usage (int ec)
           "          [-v|--verbose]                be more verbose\n"
           "          [-p|--init-password string]   use string as initial password/file\n"
           "          [-l|--length min-max]         check password with length min to max\n"
-          "          [-u|--use-unzip]              use unzip to weed out wrong passwords\n"
+          "          [-u|--use-libzip]              use libzip to weed out wrong passwords\n"
           "          [-m|--method num]             use method number \"num\" (see below)\n"
           "          [-2|--modulo r/m]             only calculcate 1/m of the password\n"
           "          file...                    the zipfiles to crack\n"
@@ -381,7 +381,7 @@ static struct option options[] =
   {"verbose", no_argument, 0, 'v'},
   {"init-password", required_argument, 0, 'p'},
   {"length", required_argument, 0, 'l'},
-  {"use-unzip", no_argument, 0, 'u'},
+  {"use-libzip", no_argument, 0, 'u'},
   {"method", required_argument, 0, 'm'},
   {"modulo", required_argument, 0, 2},
   {0, 0, 0, 0},
