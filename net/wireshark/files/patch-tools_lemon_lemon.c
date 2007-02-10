--- tools/lemon/lemon.c.orig	Sat Feb 10 01:09:11 2007
+++ tools/lemon/lemon.c	Sat Feb 10 01:09:33 2007
@@ -2146,6 +2146,7 @@ to follow the previous rule.");
         struct rule *rp;
         rp = (struct rule *)malloc( sizeof(struct rule) +
              sizeof(struct symbol*)*psp->nrhs + sizeof(char*)*psp->nrhs );
+        memset(rp, 0, sizeof(struct rule));
         if( rp==0 ){
           ErrorMsg(psp->filename,psp->tokenlineno,
             "Can't allocate enough memory for this rule.");
