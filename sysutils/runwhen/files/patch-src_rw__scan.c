--- src/rw_scan.c.orig	2020-04-22 21:45:48 UTC
+++ src/rw_scan.c
@@ -14,7 +14,7 @@ void rw_scan(tain_t* stamp, char const* text) {
   char const* x;
   switch (text[0]) {
     case '$':
-      x=env_get(text+1);
+      x=getenv(text+1);
       if (x==NULLP) DIE_MALFORMED("timestamp", text);
       text=x;
       i=tain_scan(text, stamp);
