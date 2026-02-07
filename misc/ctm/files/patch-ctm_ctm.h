--- ctm/ctm.h.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm.h
@@ -24,6 +24,7 @@
 #include <sys/stat.h>
 #include <sys/file.h>
 #include <sys/time.h>
+#include <stdint.h>
 
 #define VERSION "2.0"
 
@@ -40,6 +41,8 @@
 #define CTM_F_MD5		0x05
 #define CTM_F_Count		0x06
 #define CTM_F_Bytes		0x07
+#define CTM_F_Release		0x08
+#define CTM_F_Forward		0x09
 
 /* The qualifiers... */
 #define CTM_Q_MASK		0xff00
@@ -47,10 +50,13 @@
 #define CTM_Q_Name_Dir		0x0200
 #define CTM_Q_Name_New		0x0400
 #define CTM_Q_Name_Subst	0x0800
+#define CTM_Q_Name_Svnbase	0x1000
 #define CTM_Q_MD5_After		0x0100
 #define CTM_Q_MD5_Before	0x0200
 #define CTM_Q_MD5_Chunk		0x0400
 #define CTM_Q_MD5_Force		0x0800
+#define CTM_Q_Forward_Tar	0x0100
+#define CTM_Q_Forward_SVN	0x0200
 
 struct CTM_Syntax {
     char	*Key;		/* CTM key for operation */
@@ -145,14 +151,16 @@ void Fatal_(int ln, char *fn, char *kind);
 u_char * Ffield(FILE *fd, MD5_CTX *ctx,u_char term);
 u_char * Fname(FILE *fd, MD5_CTX *ctx,u_char term,int qual, int verbose);
 
-int Fbytecnt(FILE *fd, MD5_CTX *ctx, u_char term);
+intmax_t Fbytecnt(FILE *fd, MD5_CTX *ctx, u_char term);
 
 u_char * Fdata(FILE *fd, int u_chars, MD5_CTX *ctx);
+int Fforward(FILE *fd, intmax_t u_chars, MD5_CTX *ctx, FILE *fd_to);
 
 #define GETFIELD(p,q) if(!((p)=Ffield(fd,&ctx,(q)))) return BADREAD
 #define GETFIELDCOPY(p,q) if(!((p)=Ffield(fd,&ctx,(q)))) return BADREAD; else p=String(p)
 #define GETBYTECNT(p,q) if(0 >((p)= Fbytecnt(fd,&ctx,(q)))) return BADREAD
 #define GETDATA(p,q) if(!((p) = Fdata(fd,(q),&ctx))) return BADREAD
+#define GETFORWARD(p,q) if(!Fforward(fd,(p),&ctx,q)) return BADREAD
 #define GETNAMECOPY(p,q,r,v) if(!((p)=Fname(fd,&ctx,(q),(r),(v)))) return BADREAD; else p=String(p)
 
 int Pass1(FILE *fd, unsigned applied);
