--- sources/gcl/gcmdline.cc.orig	Sun Feb  9 02:23:11 2003
+++ sources/gcl/gcmdline.cc	Sun Feb  9 02:26:28 2003
@@ -81,7 +81,6 @@
   rawTerm.c_iflag &= ~ICRNL;
   rawTerm.c_iflag &= ~IXON;
   rawTerm.c_iflag &= ~IXOFF;
-  rawTerm.c_iflag &= ~IUCLC;
   rawTerm.c_iflag &= ~IXANY;
   rawTerm.c_iflag &= ~IMAXBEL;
 
@@ -90,7 +89,6 @@
   // rawTerm.c_lflag &= ~ISIG;
   rawTerm.c_lflag |= ISIG;
   rawTerm.c_lflag &= ~ICANON;
-  rawTerm.c_lflag &= ~XCASE;
   rawTerm.c_lflag &= ~ECHO;
 
   rawTerm.c_cc[VTIME] = 0;
