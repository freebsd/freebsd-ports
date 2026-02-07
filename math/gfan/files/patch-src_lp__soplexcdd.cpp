--- src/lp_soplexcdd.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/lp_soplexcdd.cpp
@@ -536,7 +536,7 @@ if(0)	     {
 	     debug<<"\n";
 	     D(s);
 */
-	     log2 fprintf(Stderr,"Solution failed (Type2).\n");
+	     gfan_log2 fprintf(Stderr,"Solution failed (Type2).\n");
 
 	     /*	     for(int i=0;i<work.nCols();i++)
 	       {
@@ -578,7 +578,7 @@ if(0)	     {
 		 return false;
 	       }
 	     
-	       log2 fprintf(Stderr,"Certificate failed (Type2).\n");
+	       gfan_log2 fprintf(Stderr,"Certificate failed (Type2).\n");
 	       /* std::cerr<< work;
 	      std::cerr<< farkasx;
 	     AsciiPrinter(Stderr).printVector(c);
