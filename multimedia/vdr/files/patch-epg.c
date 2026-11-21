--- epg.c.orig	2026-06-01 16:59:58 UTC
+++ epg.c
@@ -31,7 +31,11 @@ cString tComponent::ToString(void)
 bool tComponent::FromString(const char *s)
 {
   unsigned int Stream, Type;
-  int n = sscanf(s, "%X %02X %7s %m[^\n]", &Stream, &Type, language, &description); // 7 = MAXLANGCODE2 - 1
+  // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate a buffer that is large enough
+  // (description is freed below if it hasn't been assigned)
+  free(description);
+  description = MALLOC(char, strlen(s) + 1);
+  int n = sscanf(s, "%X %02X %7s %[^\n]", &Stream, &Type, language, description); // 7 = MAXLANGCODE2 - 1
   if (n != 4 || isempty(description)) {
      free(description);
      description = NULL;
