--- src/fping.c.orig	2019-02-19 20:54:45 UTC
+++ src/fping.c
@@ -427,7 +427,7 @@ int main(int argc, char** argv)
     while ((c = optparse_long(&optparse_state, longopts, NULL)) != EOF) {
         switch (c) {
         case '4':
-            if (hints_ai_family != AF_UNSPEC) {
+            if (hints_ai_family == AF_INET6) {
                 fprintf(stderr, "%s: can't specify both -4 and -6\n", prog);
                 exit(1);
             }
