--- install.c.orig	Mon Jun 15 07:53:16 1998
+++ install.c	Fri May  6 09:30:15 2005
@@ -10,6 +10,7 @@
 #define FATAL "install: fatal: "
 
 int fdsourcedir = -1;
+noc;  /* hack for bin package install -- see port pkg/INSTALL */
 
 void h(home,uid,gid,mode)
 char *home;
@@ -75,6 +76,7 @@
 int gid;
 int mode;
 {
+ if (!noc) {
   int fdin;
   int fdout;
 
@@ -115,6 +117,7 @@
     strerr_die6sys(111,FATAL,"unable to chown .../",subdir,"/",file,": ");
   if (chmod(file,mode) == -1)
     strerr_die6sys(111,FATAL,"unable to chmod .../",subdir,"/",file,": ");
+ }
 }
 
 void z(home,file,len,uid,gid,mode)
@@ -152,8 +155,9 @@
     strerr_die6sys(111,FATAL,"unable to chmod ",home,"/",file,": ");
 }
 
-void main()
+void main(argc, argv)
 {
+  noc=--argc;
   fdsourcedir = open_read(".");
   if (fdsourcedir == -1)
     strerr_die2sys(111,FATAL,"unable to open current directory: ");
