--- drivers.c.orig	Tue Apr 27 09:22:02 2004
+++ drivers.c	Tue Apr 27 09:32:19 2004
@@ -47,7 +47,7 @@
 #include <sys/errno.h>
 
 int id = 0; /* interface id */
-int len = 0; /* sizeof libmibdata */
+size_t len = 0; /* sizeof libmibdata */
 struct ifmibdata *data = NULL;
 
 int sysctl_test(void);
@@ -128,7 +128,7 @@
 
 char* available_drivers(void) {
  int ind = 0;
- int len = 0;
+ size_t len = 0;
  char *string, *ptr;
  while(drivers[ind].name != NULL) {
   len += strlen(drivers[ind].name) + 1;
@@ -464,7 +464,8 @@
 
 int sysctl_test(void) {
   struct ifmibdata tempndata;
-  int numifaces, len2;
+  int numifaces;
+  size_t len2;
   int mib[5], datamib[6];
   int i;
 
