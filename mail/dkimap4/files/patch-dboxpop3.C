--- dkpop3/dboxpop3.C.orig	Thu Jan 25 22:53:06 2001
+++ dkpop3/dboxpop3.C	Mon Apr 22 02:07:19 2002
@@ -348,6 +348,7 @@
         if(logged_in())
           return;
 
+	movemail();
         cout << "+OK Welcome\r\n";
        }
      }
