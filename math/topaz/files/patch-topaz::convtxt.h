--- topaz/convtxt.h.orig	Wed Dec  4 23:02:26 2002
+++ topaz/convtxt.h	Fri Dec 27 04:33:13 2002
@@ -25,6 +25,8 @@
 #define __convtxt_h
 #include <string>
 
+using namespace std;
+
 extern bool tosavetxt(char *in, string *out);
 extern bool fromsavetxt(char *in, string *out);
 extern char *topazfgets(char *s, int size, FILE *fp);
