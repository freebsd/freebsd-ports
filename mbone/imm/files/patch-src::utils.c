--- src/utils.c.orig	Thu Jul 15 12:37:25 2004
+++ src/utils.c	Thu Jul 15 13:36:09 2004
@@ -20,7 +20,7 @@
  * These notices must be retained in any copies of any part of this software.
  ******************************************************************************/
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
 #ifdef __NetBSD__
@@ -40,47 +40,118 @@
 
 /*----------------------------------------------------------------------------*/
 
-void warn( va_alist )
-va_dcl
+/* Allocate memory for format string buffers */
+int
+vfsalloc(char *fmt, va_list ap)
 {
-    va_list args;
-    char *fmt;
+        char *s;
+        int i, n = 0, len = 0;
 
-    va_start( args );
-    fmt = va_arg( args, char * );
-    fprintf( stderr, "Warning: " );
-    vfprintf( stderr, fmt, args );
-    va_end( args );
+        if (!fmt)
+                return 0;
+
+        s = strchr(fmt, '%');
+
+        while (s) {
+                ++s;
+                ++n;
+
+                switch (*s) {
+                case 'd':
+                        i = va_arg(ap, int);
+                        len += 1 + sizeof(int)<<1;
+                        break;
+                case 's':
+                        len += strlen(va_arg(ap, char *));
+                        break;
+                }
+                s = strchr(s, '%');
+        }
+
+        len += strlen(fmt) - (2 * n);
+
+        return len;
+}
+
+void warn( char *fmt, ... )
+{
+    va_list ap;
+    char *buf, *s;
+    int len;
+
+    if (!fmt)
+            return;
+
+    va_start(ap, fmt);
+    if (!(len = vfsalloc(fmt, ap)))
+            return;
+    va_end(ap);
+        
+    if (!(buf = malloc(len)))
+           return;
+
+    va_start(ap, fmt);              
+    vsprintf(buf, fmt, ap);
+    va_end(ap);
+
+    fprintf(stderr, "Warning: %s\n", buf);
+    free(buf);
 }
 
 /*----------------------------------------------------------------------------*/
 
-void die( va_alist )
-va_dcl
+void die(char *fmt, ... )
 {
-    va_list args;
-    char *fmt;
+    va_list ap;
+    char *buf, *s;
+    int len;
+
+    if (!fmt)
+            return;
+
+    va_start(ap, fmt);
+    if (!(len = vfsalloc(fmt, ap)))
+            return;
+    va_end(ap);
+        
+    if (!(buf = malloc(len)))
+           return;
 
-    va_start( args );
-    fmt = va_arg( args, char * );
-    fprintf( stderr, "Error: " );
-    vfprintf( stderr, fmt, args );
-    exit( 1 );
+    va_start(ap, fmt);              
+    vsprintf(buf, fmt, ap);
+    va_end(ap);
+
+    fprintf(stderr, "Error: %s\n", buf);
+    free(buf);
+    exit(1);
 }
 
 /*----------------------------------------------------------------------------*/
 
-void fatal( va_alist )
-va_dcl
+void fatal(char *fmt, ... )
 {
-    va_list args;
-    char *fmt;
+    va_list ap;
+    char *buf, *s;
+    int len;
+
+    if (!fmt)
+            return;
 
-    va_start( args );
-    fmt = va_arg( args, char * );
-    fprintf( stderr, "Internal Error: " );
-    vfprintf( stderr, fmt, args );
-    exit( 2 );
+    va_start(ap, fmt);
+    if (!(len = vfsalloc(fmt, ap)))
+            return;
+    va_end(ap);
+        
+    if (!(buf = malloc(len)))
+           return;
+
+    va_start(ap, fmt);              
+    vsprintf(buf, fmt, ap);
+    va_end(ap);
+
+    fprintf(stderr, "Internal error: %s\n", buf);
+    free(buf);
+    exit(2);
 }
 
 /*----------------------------------------------------------------------------*/
@@ -142,21 +213,34 @@
     
 /*----------------------------------------------------------------------------*/
 
-void mailmessage( va_alist )
-va_dcl
+void mailmessage(char *fmt, ... )
 {
-    va_list args;
-    char *fmt;
+    va_list ap;
+    char *buf, s;
+    int len;
     FILE *popen(), *fp;
     char cmdline[80];
      if (whome == NULL) whome = getlogin();
 	sprintf(cmdline,"%s %s",mailprog,whome);
 	fp = popen(cmdline,"w");
-    va_start( args );
-    fmt = va_arg( args, char * );
-    fprintf( fp, "MNM Warning: " );
-    vfprintf( fp, fmt, args );
-    va_end( args );
+
+    if (!fmt)
+            return;
+
+    va_start(ap, fmt);
+    if (!(len = vfsalloc(fmt, ap)))
+            return;
+    va_end(ap);
+        
+    if (!(buf = malloc(len)))
+           return;
+
+    va_start(ap, fmt);              
+    vsprintf(buf, fmt, ap);
+    va_end(ap);
+
+    fprintf(fp, "MNM Warning: %s", buf);
+    free(buf);
     pclose(fp);
 }
