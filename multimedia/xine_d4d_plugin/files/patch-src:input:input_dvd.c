--- src/input/input_dvd.c.orig	Tue Aug  6 00:20:59 2002
+++ src/input/input_dvd.c	Tue Aug  6 00:21:20 2002
@@ -1133,7 +1133,7 @@
   config_values_t    *config;
   int                 i, fd;
 
-  if (iface != 7) {
+  if (iface != 8) {
     printf ("input_d4d: input plugin doesn't support plugin API version %d.\n",
             iface);
     return NULL;
