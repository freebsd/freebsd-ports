*** smc-milter.c.orig	Thu Mar 10 06:10:48 2005
--- smc-milter.c	Thu Mar 24 12:09:11 2005
***************
*** 65,70 ****
--- 65,74 ----
  #include "relay.h"
  #include "smtp.h"
  
+ #if !defined O_SYNC && defined O_FSYNC
+ 	#define O_SYNC O_FSYNC
+ #endif
+ 
  /* Static variables for config defaults, etc. */
  static int  runmode   = 0;
  static char *smfisock = NULL;
***************
*** 161,166 ****
--- 165,191 ----
  	"<(i?frame|object|embed|applet)[^>]*>",
  	"\\son(\\w+)=[^> ]+", NULL
  };
+ 
+ #ifndef strndup
+ char *strndup(char const* s, size_t n)
+ {
+         void* voided = (void*)s;
+         void* match;
+ 	char *ret;
+ 	size_t len;
+ 
+         if (!s || !n) return NULL;
+ 	match = memchr(voided, 0, n);
+         len =
+                 match
+                 ? (char*)match - s
+                 : n+1;
+         ret = (char*)malloc(len);
+         memcpy(ret, s, len-1);
+         ret[len] = '\0';
+         return ret;
+ }
+ #endif
  
  void 
  signal_handler (int sig) {
