--- wmweather+.c.old	Tue Mar 30 05:17:20 2004
+++ wmweather+.c	Thu Jul 22 17:26:54 2004
@@ -104,7 +104,7 @@
 /**********************************
  * Prototypes
  **********************************/
-void usage(int i) __THROW __attribute__ ((__noreturn__));
+void usage(int i);
 void printversion(void);
 int readconf(char *file);
 int parse_option(char *option, char *value);
