--- ctm/ctm_syntax.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm_syntax.c
@@ -22,16 +22,21 @@
 #define MD5	CTM_F_MD5
 #define Count	CTM_F_Count
 #define Bytes	CTM_F_Bytes
+#define Release	CTM_F_Release
+#define Forward	CTM_F_Forward
 
 /* The qualifiers... */
 #define File	CTM_Q_Name_File
 #define Dir	CTM_Q_Name_Dir
+#define Svnbase	CTM_Q_Name_Svnbase
 #define New	CTM_Q_Name_New
 #define Subst	CTM_Q_Name_Subst
 #define After	CTM_Q_MD5_After
 #define Before	CTM_Q_MD5_Before
 #define Chunk	CTM_Q_MD5_Chunk
 #define Force	CTM_Q_MD5_Force
+#define Tar	CTM_Q_Forward_Tar
+#define SVN	CTM_Q_Forward_SVN
 
 static int ctmFM[] = /* File Make */
     { Name|File|New|Subst, Uid, Gid, Mode,
@@ -57,6 +62,12 @@ static int ctmDM[] = /* Directory Make */
 static int ctmDR[] = /* Directory Remove */
     { Name|Dir, 0 };
 
+static int ctmTR[] = /* Forward to tar */
+    { Count, Forward|Tar, 0 };
+
+static int ctmSV[] = /* Forward to svnadmin load */
+    { Name|Dir|Svnbase, Release, Count, Forward|SVN, 0 };
+
 struct CTM_Syntax Syntax[] = {
     { "FM",  	ctmFM },
     { "FS",  	ctmFS },
@@ -66,4 +77,6 @@ struct CTM_Syntax Syntax[] = {
     { "AS", 	ctmAS },
     { "DM",  	ctmDM },
     { "DR",  	ctmDR },
+    { "TR",  	ctmTR },
+    { "SV",  	ctmSV },
     { 0,    	0} };
