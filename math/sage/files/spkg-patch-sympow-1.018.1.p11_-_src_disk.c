--- sympow-1.018.1.p11/src/disk.c-orig	2012-04-19 02:33:51.000000000 +0000
+++ sympow-1.018.1.p11/src/disk.c	2012-04-19 02:34:22.000000000 +0000
@@ -39,7 +39,7 @@
  else if (((sp&3)==0) && CM_CASE) {if (2*ep==sp) S[3]='l'; else S[3]='h';}
  else {if (2*ep==sp) S[3]='L'; else S[3]='H';}
  if (HECKE && dv) {TACKS[which]=malloc(dv*sizeof(QD)); TACKON[which]=dv;}
- else if (dv<=sp/2) TACKON[which]=0;
+ else if (dv<=sp/2) {TACKS[which]=NULL; TACKON[which]=0;}
  else {TACKS[which]=malloc((dv-sp/2)*sizeof(QD)); TACKON[which]=dv-sp/2;}
  S[4]=0; F=fopen("datafiles/param_data","r"); strcpy(U,S);
  if (ANAL_RANK) {if (dv>0) U[0]='A'; else U[0]='m';}
