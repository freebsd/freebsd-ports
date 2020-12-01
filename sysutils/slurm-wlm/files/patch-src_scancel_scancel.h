--- src/scancel/scancel.h.orig	2020-03-26 21:44:05 UTC
+++ src/scancel/scancel.h
@@ -75,7 +75,7 @@ typedef struct scancel_options {
 	bool *job_pend;		/* Set fi job is pending	*/
 } opt_t;
 
-opt_t opt;
+extern opt_t opt;
 
 /* process options:
  * 1. set defaults
