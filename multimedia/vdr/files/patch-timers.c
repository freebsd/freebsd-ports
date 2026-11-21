--- timers.c.orig	2026-06-01 16:59:58 UTC
+++ timers.c
@@ -466,7 +466,20 @@ bool cTimer::Parse(const char *s)
      s = s2;
      }
   bool result = false;
-  if (8 <= sscanf(s, "%u :%m[^:]:%m[^:]:%d :%d :%d :%d :%m[^:\n]:%m[^\n]", &flags, &channelbuffer, &daybuffer, &start, &stop, &priority, &lifetime, &filebuffer, &aux)) {
+  // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate buffers that are large enough
+  // for any field (no field can be longer than the whole input string)
+  size_t l = strlen(s) + 1;
+  channelbuffer = MALLOC(char, l);
+  daybuffer = MALLOC(char, l);
+  filebuffer = MALLOC(char, l);
+  aux = MALLOC(char, l);
+  int fields = sscanf(s, "%u :%[^:]:%[^:]:%d :%d :%d :%d :%[^:\n]:%[^\n]", &flags, channelbuffer, daybuffer, &start, &stop, &priority, &lifetime, filebuffer, aux);
+  if (fields < 9) {
+     // like "%m", leave aux at NULL if it hasn't been assigned
+     free(aux);
+     aux = NULL;
+     }
+  if (8 <= fields) {
      if (aux && !*skipspace(aux)) {
         free(aux);
         aux = NULL;
