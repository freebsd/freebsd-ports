--- install.c.orig	Wed Jun  1 14:36:46 2005
+++ install.c	Wed Jun  1 14:38:17 2005
@@ -14,6 +14,7 @@
 #define FATAL "install: fatal: "
 
 int fdsourcedir = -1;
+noc;  /* hack for bin package install -- see port pkg/INSTALL */
 
 void h(home,uid,gid,mode)
 const char *home;
@@ -79,6 +80,7 @@
 int gid;
 int mode;
 {
+ if (!noc) {
   int fdin;
   int fdout;
 
@@ -119,6 +121,7 @@
     strerr_die6sys(111,FATAL,"unable to chown .../",subdir,"/",file,": ");
   if (chmod(file,mode) == -1)
     strerr_die6sys(111,FATAL,"unable to chmod .../",subdir,"/",file,": ");
+ }
 }
 
 void C(home,subdir,file,source,uid,gid,mode)
@@ -270,8 +273,9 @@
     strerr_die6sys(111,FATAL,"unable to chmod ",home,"/",file,": ");
 }
 
-int main()
+void main(argc, argv)
 {
+  noc=--argc;
   fdsourcedir = open_read(".");
   if (fdsourcedir == -1)
     strerr_die2sys(111,FATAL,"unable to open current directory: ");
