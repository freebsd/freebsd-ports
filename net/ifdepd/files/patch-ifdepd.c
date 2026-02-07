--- ifdepd.c.orig	2011-04-12 13:24:48 UTC
+++ ifdepd.c
@@ -188,7 +188,7 @@ void int_down(int_name if_name) {
   }
 }
 
-inline void cleanup() {
+static inline void cleanup() {
   if (s_opt != NULL)
     free(s_opt);
   if (d_opt != NULL)
@@ -204,7 +204,7 @@ void usage(const char *progname) {
        progname);
 }
 
-inline int del_count(const char *s, const char d) {
+static inline int del_count(const char *s, const char d) {
   int cnt=0, a;
   for (a=0; s[a] != '\0'; a++)
     if (s[a] == d)
@@ -415,9 +415,10 @@ int main(int argc, char *argv[]) {
       if (!ints_exists(s_ints, s_cnt)) {
         free(s_opt);
 	free(s_ints);
-	if (D)
+	if (D) {
 	  free(d_opt);
 	  free(d_ints);
+	}
 	exit(1);
       }
       break;
@@ -429,9 +430,10 @@ int main(int argc, char *argv[]) {
       if (!ints_exists(d_ints, d_cnt)) {
         free(d_opt);
 	free(d_ints);
-	if (S)
+	if (S) {
 	  free(s_opt);
 	  free(s_ints);
+	}
 	exit(1);
       }
       break;
