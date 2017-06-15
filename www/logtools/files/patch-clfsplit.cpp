--- clfsplit.cpp.orig	2008-06-06 05:33:52 UTC
+++ clfsplit.cpp
@@ -203,7 +203,7 @@ int main(int argc, char **argv)
   MAP m;
   FILE *input = stdin;
   bool new_input = false;
-  optind = 0;
+  optind = 1;
   while(-1 != (int_c = getopt(argc, argv, "d:i:f:s:")) )
   {
     switch(char(int_c))
