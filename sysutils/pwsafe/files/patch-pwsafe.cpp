--- pwsafe.cpp.orig	2005-09-30 10:30:56 UTC
+++ pwsafe.cpp
@@ -1019,7 +1019,12 @@ int main(int argc, char **argv) {
       // seed the random number generator
       char rng_filename[1024];
       if (RAND_file_name(rng_filename,sizeof(rng_filename))) {
-        int rc = RAND_load_file(rng_filename,-1);
+        int rc;
+        if (!strlen(rng_filename)) {
+          rc = RAND_load_file("/dev/urandom",1024);
+        } else {
+          rc = RAND_load_file(rng_filename,-1);
+        }
         if (rc) {
           if (arg_verbose > 0) printf("rng seeded with %d bytes from %s\n", rc, rng_filename);
         } else {
