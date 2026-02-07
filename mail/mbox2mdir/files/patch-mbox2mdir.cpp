--- mbox2mdir.cpp	2018-08-18 00:55:36.190935000 -0500
+++ mbox2mdir.cpp	2018-08-18 00:55:54.648780000 -0500
@@ -178,7 +178,7 @@
   //const char *ifile="Mailbox", *odir="/home/sergey/Maildir/cur";
   const char *ifile, *odir;
   if(argc<3){
-    printf("Mailbox to Maildir Converter, Version "VERSION" built: "__DATE__" Copyright(C) Sergey A. Galin.\n"
+    printf("Mailbox to Maildir Converter, Version " VERSION " built: " __DATE__ " Copyright(C) Sergey A. Galin.\n"
 	   "This program is distibuted under GNU General Public License v.2 or later.\n"
 	   "Homepage: http://sageshome.net/oss/\n"
 	   "\n"
