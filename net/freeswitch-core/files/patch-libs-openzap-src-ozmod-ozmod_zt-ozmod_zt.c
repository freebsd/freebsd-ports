--- libs/openzap/src/ozmod/ozmod_zt/ozmod_zt.c.orig	2010-04-26 14:17:55.000000000 -0700
+++ libs/openzap/src/ozmod/ozmod_zt/ozmod_zt.c	2010-04-26 14:22:56.000000000 -0700
@@ -52,38 +52,38 @@
  * \brief General IOCTL codes
  */
 struct ioctl_codes {
-    int GET_BLOCKSIZE;
-    int SET_BLOCKSIZE;
-    int FLUSH;
-    int SYNC;
-    int GET_PARAMS;
-    int SET_PARAMS;
-    int HOOK;
-    int GETEVENT;
-    int IOMUX;
-    int SPANSTAT;
-    int MAINT;
-    int GETCONF;
-    int SETCONF;
-    int CONFLINK;
-    int CONFDIAG;
-    int GETGAINS;
-    int SETGAINS;
-    int SPANCONFIG;
-    int CHANCONFIG;
-    int SET_BUFINFO;
-    int GET_BUFINFO;
-    int AUDIOMODE;
-    int ECHOCANCEL;
-    int HDLCRAWMODE;
-    int HDLCFCSMODE;
-    int SPECIFY;
-    int SETLAW;
-    int SETLINEAR;
-    int GETCONFMUTE;
-    int ECHOTRAIN;
-    int SETTXBITS;
-    int GETRXBITS;
+    long GET_BLOCKSIZE;
+    long SET_BLOCKSIZE;
+    long FLUSH;
+    long SYNC;
+    long GET_PARAMS;
+    long SET_PARAMS;
+    long HOOK;
+    long GETEVENT;
+    long IOMUX;
+    long SPANSTAT;
+    long MAINT;
+    long GETCONF;
+    long SETCONF;
+    long CONFLINK;
+    long CONFDIAG;
+    long GETGAINS;
+    long SETGAINS;
+    long SPANCONFIG;
+    long CHANCONFIG;
+    long SET_BUFINFO;
+    long GET_BUFINFO;
+    long AUDIOMODE;
+    long ECHOCANCEL;
+    long HDLCRAWMODE;
+    long HDLCFCSMODE;
+    long SPECIFY;
+    long SETLAW;
+    long SETLINEAR;
+    long GETCONFMUTE;
+    long ECHOTRAIN;
+    long SETTXBITS;
+    long GETRXBITS;
 };
 
 /**
