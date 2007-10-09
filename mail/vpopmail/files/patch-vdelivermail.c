diff -urN -x .svn ../../../branches/vendor/vpopmail/vdelivermail.c ./vdelivermail.c
--- ../../../branches/vendor/vpopmail/vdelivermail.c	2007-10-07 19:56:56.000000000 +0300
+++ ./vdelivermail.c	2007-10-07 21:18:56.000000000 +0300
@@ -1246,7 +1246,17 @@
          }
 
          /* still in the headers check for spam header */
+#ifndef SPAM_THRESHOLD
          if ( strncmp(&spambuf[j], "X-Spam-Flag: YES", 16 ) == 0 ) return(1);
+#else
+         if ( strncmp(&spambuf[j], "X-Spam-Level: ", 14 ) == 0 ) {
+	   for (k = 0; k < SPAM_THRESHOLD; k++) {
+	     if (spambuf[j + 14 + k] != '*')
+	       return (0);
+	   }
+	   return(1);
+	 }
+#endif
 
          if (spambuf[i+1]!=0) j=i+1;
        }
