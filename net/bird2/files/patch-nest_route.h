--- nest/route.h.orig	2020-08-20 21:16:52 UTC
+++ nest/route.h
@@ -458,7 +458,7 @@ typedef struct rta {
 					   protocol-specific metric is availabe */
 
 
-const char * rta_dest_names[RTD_MAX];
+extern const char * rta_dest_names[RTD_MAX];
 
 static inline const char *rta_dest_name(uint n)
 { return (n < RTD_MAX) ? rta_dest_names[n] : "???"; }
