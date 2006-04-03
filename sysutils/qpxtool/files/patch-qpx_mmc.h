--- qpx_mmc.h.orig	Sat Mar 18 20:28:50 2006
+++ qpx_mmc.h	Thu Mar 23 05:03:22 2006
@@ -89,26 +89,25 @@
 	"<12>","<13>","<14>",""
 };
 
-const	int	_devcnt=58;
+const	int	_devcnt=64;
 const	str_dev _devtbl[_devcnt]={
-		"/dev/hda\0","/dev/hdb\0","/dev/hdc\0","/dev/hdd\0",
-		"/dev/hde\0","/dev/hdf\0","/dev/hdg\0","/dev/hdh\0",
-		"/dev/hdi\0","/dev/hdj\0","/dev/hdk\0","/dev/hdl\0",
-		"/dev/hdm\0","/dev/hdn\0","/dev/hdo\0","/dev/hdp\0",
-		"/dev/hdq\0","/dev/hdr\0","/dev/hds\0","/dev/hdt\0",
-		"/dev/hdu\0","/dev/hdv\0","/dev/hdw\0","/dev/hdx\0",
-		"/dev/hdy\0","/dev/hdz\0",
-
-		"/dev/sr0\0","/dev/sr1\0","/dev/sr2\0","/dev/sr3\0",
-		"/dev/sr4\0","/dev/sr5\0","/dev/sr6\0","/dev/sr7\0",
-		"/dev/sr8\0","/dev/sr9\0","/dev/sr10\0","/dev/sr11\0",
-		"/dev/sr12\0","/dev/sr13\0","/dev/sr14\0","/dev/sr15\0",
-
-		"/dev/sr16\0","/dev/sr17\0","/dev/sr18\0","/dev/sr19\0",
-		"/dev/sr20\0","/dev/sr21\0","/dev/sr22\0","/dev/sr23\0",
-		"/dev/sr24\0","/dev/sr25\0","/dev/sr26\0","/dev/sr27\0",
-		"/dev/sr28\0","/dev/sr29\0","/dev/sr30\0","/dev/sr31\0",
+		"/dev/acd0\0","/dev/acd1\0","/dev/acd2\0","/dev/acd3\0",
+		"/dev/acd4\0","/dev/acd5\0","/dev/acd6\0","/dev/acd7\0",
+		"/dev/acd8\0","/dev/acd9\0","/dev/acd10\0","/dev/acd11\0",
+		"/dev/acd12\0","/dev/acd13\0","/dev/acd14\0","/dev/acd15\0",
+		"/dev/acd16\0","/dev/acd17\0","/dev/acd18\0","/dev/acd19\0",
+		"/dev/acd20\0","/dev/acd21\0","/dev/acd22\0","/dev/acd23\0",
+		"/dev/acd24\0","/dev/acd25\0","/dev/acd26\0","/dev/acd27\0",
+		"/dev/acd28\0","/dev/acd29\0","/dev/acd30\0","/dev/acd31\0",
 
+		"/dev/cd0\0","/dev/cd1\0","/dev/cd2\0","/dev/cd3\0",
+		"/dev/cd4\0","/dev/cd5\0","/dev/cd6\0","/dev/cd7\0",
+		"/dev/cd8\0","/dev/cd9\0","/dev/cd10\0","/dev/cd11\0",
+		"/dev/cd12\0","/dev/cd13\0","/dev/cd14\0","/dev/cd15\0",
+		"/dev/cd16\0","/dev/cd17\0","/dev/cd18\0","/dev/cd19\0",
+		"/dev/cd20\0","/dev/cd21\0","/dev/cd22\0","/dev/cd23\0",
+		"/dev/cd24\0","/dev/cd25\0","/dev/cd26\0","/dev/cd27\0",
+		"/dev/cd28\0","/dev/cd29\0","/dev/cd30\0","/dev/cd31\0",
 /*
 		"/dev/sr0\0","/dev/sr1\0","/dev/sr2\0","/dev/sr3\0",
 		"/dev/sr4\0","/dev/sr5\0","/dev/sr6\0","/dev/sr7\0",
