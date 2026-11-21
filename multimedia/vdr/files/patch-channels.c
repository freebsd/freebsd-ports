--- channels.c.orig	2026-10-27 18:57:48 UTC
+++ channels.c
@@ -27,7 +27,10 @@ tChannelID tChannelID::FromString(const
   int tid;
   int sid;
   int rid = 0;
-  int fields = sscanf(s, "%m[^-]-%d-%d-%d-%d", &sourcebuf, &nid, &tid, &sid, &rid);
+  // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate a buffer that is large enough
+  // for any field (no field can be longer than the whole input string)
+  sourcebuf = MALLOC(char, strlen(s) + 1);
+  int fields = sscanf(s, "%[^-]-%d-%d-%d-%d", sourcebuf, &nid, &tid, &sid, &rid);
   int source = (fields == 4 || fields == 5) ? cSource::FromString(sourcebuf) : -1;
   free(sourcebuf); // allocated as soon as the first field matched, also when the rest didn't
   if (source >= 0)
@@ -637,7 +640,28 @@ bool cChannel::Parse(const char *s)
      char *apidbuf = NULL;
      char *tpidbuf = NULL;
      char *caidbuf = NULL;
-     int fields = sscanf(s, "%m[^:]:%d :%m[^:]:%m[^:] :%d :%m[^:]:%m[^:]:%m[^:]:%m[^:]:%d :%d :%d :%d ", &namebuf, &frequency, &parambuf, &sourcebuf, &srate, &vpidbuf, &apidbuf, &tpidbuf, &caidbuf, &sid, &nid, &tid, &rid);
+     // "%m" isn't supported by every sscanf() (e.g. FreeBSD's), so allocate buffers that are large enough
+     // for any field (no field can be longer than the whole input string)
+     size_t l = strlen(s) + 1;
+     namebuf = MALLOC(char, l);
+     parambuf = MALLOC(char, l);
+     sourcebuf = MALLOC(char, l);
+     vpidbuf = MALLOC(char, l);
+     apidbuf = MALLOC(char, l);
+     tpidbuf = MALLOC(char, l);
+     caidbuf = MALLOC(char, l);
+     int fields = sscanf(s, "%[^:]:%d :%[^:]:%[^:] :%d :%[^:]:%[^:]:%[^:]:%[^:]:%d :%d :%d :%d ", namebuf, &frequency, parambuf, sourcebuf, &srate, vpidbuf, apidbuf, tpidbuf, caidbuf, &sid, &nid, &tid, &rid);
+     if (fields < 9) {
+        // the buffers are only used (and freed) if all of them have been assigned
+        free(namebuf);
+        free(parambuf);
+        free(sourcebuf);
+        free(vpidbuf);
+        free(apidbuf);
+        free(tpidbuf);
+        free(caidbuf);
+        namebuf = parambuf = sourcebuf = vpidbuf = apidbuf = tpidbuf = caidbuf = NULL;
+        }
      if (fields >= 9) {
         if (fields == 9) {
            // allow reading of old format
