--- pwsafe.cpp.orig	2005-09-30 12:30:56.000000000 +0200
+++ pwsafe.cpp	2014-09-17 15:44:48.000000000 +0200
@@ -1019,7 +1019,12 @@
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
@@ -2111,7 +2116,7 @@
       case '"': out += "&quot;"; break;
       case '&': out += "&amp;"; break;
       case '<': out += "&lt;"; break;
-      case '>': out += "&gt"; break;
+      case '>': out += "&gt;"; break;
       case '\\': out += "\\\\"; break;
       default: out += c;
     }
