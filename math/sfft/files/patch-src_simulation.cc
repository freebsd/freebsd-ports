--- src/simulation.cc.orig	2024-10-15 16:05:30 UTC
+++ src/simulation.cc
@@ -50,7 +50,7 @@ void simulation::setup(int argc, char **argv)
   int version = 1;
   int fftw_opt = FFTW_ESTIMATE;
 
-  char ch;
+  int ch;
   while ((ch = getopt(argc, argv, "hton:k:r:v:")) != EOF)
     {
       switch (ch)
