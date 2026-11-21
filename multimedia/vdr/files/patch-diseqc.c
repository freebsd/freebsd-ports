--- diseqc.c.orig	2026-06-01 16:59:58 UTC
+++ diseqc.c
@@ -228,7 +228,18 @@ bool cDiseqc::Parse(const char *s)
   devices = CurrentDevices;
   bool result = false;
   char *sourcebuf = NULL;
-  int fields = sscanf(s, "%m[^ ] %d %c %d %m[^\n]", &sourcebuf, &slof, &polarization, &lof, &commands);
+  // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate buffers that are large enough
+  // for any field (no field can be longer than the whole input string)
+  size_t l = strlen(s) + 1;
+  sourcebuf = MALLOC(char, l);
+  free(commands);
+  commands = MALLOC(char, l);
+  int fields = sscanf(s, "%[^ ] %d %c %d %[^\n]", sourcebuf, &slof, &polarization, &lof, commands);
+  if (fields < 5) {
+     // like "%m", leave commands at NULL if it hasn't been assigned
+     free(commands);
+     commands = NULL;
+     }
   if (fields == 4)
      commands = NULL; //XXX Apparently sscanf() doesn't work correctly if the last %m argument results in an empty string
   if (4 <= fields && fields <= 5) {
