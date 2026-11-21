--- sources.c.orig	2026-06-01 16:59:58 UTC
+++ sources.c
@@ -31,7 +31,19 @@ cSource::~cSource()
 bool cSource::Parse(const char *s)
 {
   char *codeBuf = NULL;
-  if (2 == sscanf(s, "%m[^ ] %m[^\n]", &codeBuf, &description))
+  // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate buffers that are large enough
+  // for any field (no field can be longer than the whole input string)
+  size_t l = strlen(s) + 1;
+  codeBuf = MALLOC(char, l);
+  free(description);
+  description = MALLOC(char, l);
+  int fields = sscanf(s, "%[^ ] %[^\n]", codeBuf, description);
+  if (fields < 2) {
+     // like "%m", leave description at NULL if it hasn't been assigned
+     free(description);
+     description = NULL;
+     }
+  if (2 == fields)
      code = FromString(codeBuf);
   free(codeBuf);
   return code != stNone && description && *description;
