--- Client.cpp.orig	Thu Jul 15 17:12:49 2004
+++ Client.cpp	Thu Jul 15 17:13:53 2004
@@ -278,7 +278,7 @@
     "                for recovery \n");
 }
 
-void main(int argc, char** argv)
+int main(int argc, char** argv)
 {
   int c;
   bool flag_p=false;
@@ -376,6 +376,9 @@
       repin->close_sock();
     } /* infinete loop */
   } /* ping mode */
+
+  /* Default exit value of 0 */
+  return (0);
 }
 
 
