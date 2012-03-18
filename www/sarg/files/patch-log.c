X-Git-Url: http://sarg.git.sourceforge.net/git/gitweb.cgi?p=sarg%2Fsarg;a=blobdiff_plain;f=log.c;h=a6d6c61014836957c7b5313a282c6d746405c9b9;hp=ed200b3cb8531e5c1cbb78252714d693a6bc9ea3;hb=24eb624ea44bf4c82c602cea2195d85558787b47;hpb=b8523e5ded9d9d80d6330c6d346dc57f5cf147bf

diff --git a/log.c b/log.c
index ed200b3..a6d6c61 100644
--- log.c
+++ log.c
@@ -147,7 +147,7 @@ int main(int argc,char *argv[])
 	unsigned long recs2=0UL;
 	int OutputNonZero = REPORT_EVERY_X_LINES ;
 	bool download_flag=false;
-	char *download_url=NULL;
+	char download_url[MAXLEN];
 	struct getwordstruct gwarea;
 	longline line;
 	time_t tnum;
@@ -1331,7 +1331,7 @@ int main(int argc,char *argv[])
 				*/
 				download_flag=is_download_suffix(full_url);
 				if (download_flag) {
-					download_url=full_url;
+					safe_strcpy(download_url,full_url,sizeof(download_url));
 					download_count++;
 				}
 			} else
@@ -1503,7 +1503,7 @@ int main(int argc,char *argv[])
 
 			totregsg++;
 
-			if(!dataonly && download_flag && download_url && strstr(code,"DENIED") == 0) {
+			if(!dataonly && download_flag && strstr(code,"DENIED") == 0) {
 				ndownload = 1;
 
 				if ( ! fp_Download_Unsort ) {
