--- src/dviprlib.h.orig	Tue May 13 16:10:34 1997
+++ src/dviprlib.h	Tue May 24 21:41:14 2005
@@ -337,23 +337,23 @@
 #ifdef dviprlib_implementation
 typedef struct {
   int no;
-  long (*getworksize)(P2(dviprt_print *,long ));
-  long (*encode)(P3(dviprt_print *,long,int));
+  long (*getworksize)(dviprt_print *,long);
+  long (*encode)(dviprt_print *,long,int);
 } dviprt_encoder;
 
 #define liblocal private
 
-liblocal dviprt_encoder *dviprt_getencoder_(P1(int ));
-liblocal int dviprt_setcfgbuffer_(P3(dviprt_cfg_i *,int ,int ));
-liblocal int dviprt_resetcfgbuffer_(P1(dviprt_cfg_i *));
-liblocal int dviprt_initcfg_(P2(dviprt_cfg_t *,dviprt_cfg_i *));
-liblocal int dviprt_printmessage(P2(char *,int ));
-liblocal int dviprt_printerror(P2(char *,int ));
-liblocal int dviprt_printwarning(P2(char *,int ));
-liblocal int dviprt_printcfgerror(P3(dviprt_cfg_i *,char *,int ));
-liblocal int dviprt_printcfgwarning(P3(dviprt_cfg_i *,char *,int ));
+liblocal dviprt_encoder *dviprt_getencoder_(int);
+liblocal int dviprt_setcfgbuffer_(dviprt_cfg_i *,int ,int);
+liblocal int dviprt_resetcfgbuffer_(dviprt_cfg_i *);
+liblocal int dviprt_initcfg_(dviprt_cfg_t *,dviprt_cfg_i *);
+liblocal int dviprt_printmessage(char *,int);
+liblocal int dviprt_printerror(char *,int);
+liblocal int dviprt_printwarning(char *,int);
+liblocal int dviprt_printcfgerror(dviprt_cfg_i *,char *,int);
+liblocal int dviprt_printcfgwarning(dviprt_cfg_i *,char *,int);
 
-extern int dviprt_print_headercomment_(P4(char *,char *,char *,FILE *));
+extern int dviprt_print_headercomment_(char *,char *,char *,FILE *);
 extern char dviprt_message_buffer[];
 #endif dviprlib_implementation
  
