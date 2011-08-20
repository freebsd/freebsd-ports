--- diseqc.c.orig
+++ diseqc.c
@@ -108,7 +108,7 @@ const char *cDiseqc::Codes(const char *s
               errno = 0;
               int n = strtol(t, &p, 16);
               if (!errno && p != t && 0 <= n && n <= 255) {
-                 if (parsing) {
+                 if (!parsing) {
                     codes[NumCodes++] = uchar(n);
                     numCodes = NumCodes;
                     }
