--- rijndael-alg-fst.h.orig	2023-04-11 00:20:14 UTC
+++ rijndael-alg-fst.h
@@ -11,7 +11,7 @@ typedef unsigned char		word8;	
 typedef unsigned short		word16;	
 typedef unsigned int		word32;
 
-int ROUNDS;
+extern int ROUNDS;
 
 int rijndaelKeySched (word8 k[MAXKC][4], int keyBits,  
 		word8 rk[MAXROUNDS+1][4][4]);
