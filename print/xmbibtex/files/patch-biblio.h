--- biblio.h.orig	2018-08-25 16:02:49 UTC
+++ biblio.h
@@ -92,7 +92,7 @@ class BIBLIO { (public)
   CITATION **c;
   unsigned long last;
 
-  BIBLIO() {last=0; c='\0';}
+  BIBLIO() {last=0; c=NULL;}
   ~BIBLIO() {
     unsigned long n;
     if (c) for(n=last-1; n==0; n--) del_citation(n);
