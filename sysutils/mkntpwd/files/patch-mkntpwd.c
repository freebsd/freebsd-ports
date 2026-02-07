--- mkntpwd.c.orig	1998-05-12 11:16:07.000000000 +0200
+++ mkntpwd.c	2011-05-17 07:14:19.278025383 +0200
@@ -24,6 +24,8 @@
  * SUCH DAMAGE.
  */
 
+#include <unistd.h>
+
 #include "mkntpwd.h"
 
 void str_to_key(unsigned char *,unsigned char *);
@@ -34,7 +36,7 @@
 void E_P16(unsigned char *p14,unsigned char *p16);
 
 
-void main(int argc, char **argv) {
+int main(int argc, char **argv) {
 	extern char *optarg;
 	int c;
 
@@ -131,7 +133,7 @@
 
 	if (printlan >0) {
 		memset(hashout,'\0',17);
-		E_P16((uchar *)lanpwd,hashout);
+		E_P16((uchar *)lanpwd,(uchar *)hashout);
 		printlanhash(hashout);
 	}
 
@@ -164,9 +166,9 @@
 		}
 		
 		memset(p16,'\0',17);
-		mdfour(p16,hold, uni_len);
+		mdfour(p16,(uchar *)hold, uni_len);
 
-		printlanhash(p16);
+		printlanhash((char *)p16);
 		    
 		free(p16);
 		free(hold);
