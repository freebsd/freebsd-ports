--- ./modules/core/src/c/stack2.c.orig	2011-07-20 01:15:44.000000000 -0700
+++ ./modules/core/src/c/stack2.c	2012-03-06 01:18:59.000000000 -0800
@@ -667,7 +667,6 @@
     if (*lar != -1)  C2F(cvstr1)(&MN, istk(*lr), cstk(*lar), &cx0,  MN + 1);
     *lar = *lr;
     *lr = cadr(*lr);
-    M=MN; N= 1;
     break;
   case 'd' :
     if (! C2F(cremat)(fname, &lw1, &it, m, n, lr, &lcs, nlgh))  return FALSE;
@@ -1259,6 +1258,12 @@
 		*n = 1;
 		if (! C2F(getsmat)(fname,&topk,&lw,&m1,&n1,&cx1,&cx1,lr,m, nlgh))
 			return FALSE;
+		if ((m1 != 1) || (n1 != 1))
+		{
+			/* bug 8768 check dimensions */
+			Scierror(999, _("%s: Wrong size for input argument #%d: A string expected.\n"), fname, *number);
+			return FALSE;
+		}
 		ix2 = *m * *n;
 		/* in case where ix2 is 0 in2str adds the \0 char after the end of
 		the storage of the variable, so it writes over the next variable
@@ -1348,7 +1353,6 @@
 		nn= (*m)*(*n);
 		ScilabMStr2CM(istk(il1),&nn,istk(ild1),&items,&ierr);
 		if ( ierr == 1) return FALSE;
-		Type = '$';
 		/*
 		* Warning : lr must have the proper size when calling getrhsvar
 		* char **Str1; .... GetRhsVar(...., &lr)
@@ -1621,7 +1625,6 @@
     Sp->icol = istk(icol);
     Sp->R = stk(lr1);
     Sp->I = stk(lc);
-    Type = '$';
     break;
   case 'I' :
     /* int matrices */
@@ -1630,7 +1633,6 @@
       return FALSE;
     Im->m = *m ; Im->n = *n ; Im->it = it; Im->l = lr1;
     Im->D = istk(lr1);
-    Type = '$';
     break;
   case 'p' :
     if (! C2F(getlistpointer)(fname, &topk, &lw, number, lr,  nlgh))
@@ -2086,7 +2088,7 @@
 	int ret = FALSE;
 	int ifin = 0, ifun = 0, tops = 0, moutputs = 0;
 	int id[nsiz];
-	int lf = 0, op = 0, ile = 0, ils = 0, nnn = thestring_len, ninputs = 0;
+	int lf = 0, op = 0, ile = 0, ils = 0, nnn = thestring_len;
 
 	if (nnn <= 2) 
 	{
@@ -2114,11 +2116,6 @@
 			ils = iadr(lf) + 1;
 			moutputs = *istk(ils);
 			ile = ils + moutputs * nsiz + 1;
-			ninputs = *istk(ile);
-			/*
-			*   ninputs=actual number of inputs, moutputs=actual number of outputs
-			*   of thestring: checking mlhs=ninputs and mrhs=moutputs not done.
-			*/
 			ret = C2F(scifunction)(ifirst, &lf, mlhs, mrhs);
 		} 
 		else 
@@ -2170,9 +2167,9 @@
 
 int C2F(scibuiltin)(int *number,int *ifun,int *ifin,int *mlhs,int *mrhs)
 {
-  int srhs, slhs;
-  int ix, k, intop, lw, pt0;
-  int imode,ireftop;
+  int srhs = 0, slhs = 0;
+  int ix = 0, k = 0, intop = 0, lw = 0;
+  int imode = 0, ireftop = 0;
   intop = Top;
 
   if ( intersci_push() == 0 )
@@ -2187,7 +2184,6 @@
   Lhs = *mlhs;
   Rhs = *mrhs;
   C2F(recu).krec = -1;
-  pt0 = C2F(recu).pt;
   ++C2F(recu).niv;
   goto L90;
   /* ***************************** copied from callinter.h  */
@@ -2564,12 +2560,15 @@
 
   for (k = 1; k <= Lhs; k++)
     {
+     if (LhsVar(k))
+     {
       plhsk=*Lstk(LhsVar(k)+Top-Rhs);
       if (*istk( iadr(plhsk) ) < 0) {
 	if (*Lstk(Bot) > *Lstk(*istk(iadr (plhsk) +2)) )
 	LhsVar(k)=*istk(iadr(plhsk)+2);
 	/* lcres = 0 */
       }
+     }
     }
 
   if (Err > 0||C2F(errgst).err1> 0)  return TRUE ;
