diff -ru --exclude *.bak --exclude Makefile --exclude Makefile.in work.old/buhg/dirnu.c work/buhg/dirnu.c
--- work.old/buhg/dirnu.c	Thu Jan 16 00:07:51 2003
+++ buhg/dirnu.c	Tue Jan 21 21:42:50 2003
@@ -415,7 +415,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_8_1.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_8_1.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -1805,7 +1805,7 @@
    {
     case FK1:   /*Помощь*/
      GDITE();
-     sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_8_1_1.txt");
+     sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_8_1_1.txt");
      prosf(strsql);
      clear();
      goto naz;
@@ -2133,7 +2133,7 @@
  {
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"zarp2_8_1_3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"zarp2_8_1_3.txt");
    prosf(strsql);
    goto naz;
 
