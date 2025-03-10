--- src/timing_many.cc.orig	2024-10-15 16:05:53 UTC
+++ src/timing_many.cc
@@ -51,7 +51,7 @@ parse_arguments(int argc, char **argv, int *n, int *k,
 parse_arguments(int argc, char **argv, int *n, int *k, int *num_inputs,
                 int *version, int *fftw_opt, bool * simple_parallelism)
 {
-  char ch;
+  int ch;
   while ((ch = getopt(argc, argv, "htosi:n:k:v:")) != EOF)
     {
       switch (ch)
