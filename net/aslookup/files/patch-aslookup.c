--- aslookup.c.orig	2009-09-20 11:00:21 UTC
+++ aslookup.c
@@ -48,12 +48,12 @@
 #include <time.h>
 #include <stdlib.h>
 
-#define VERSION	"ASLookup Beta Version 0.13"
+#define VERSION	"ASLookup Beta Version 0.13d"
 #define COPYRIGHT "Copyright (C) 1998 - 2000 K.Kondo, Internet Initiative Japan Inc.\r\nCopyright (c) 2005 K.Kondo, Bugest-Network"
 #define REVISION "aslookup.c,v 1.7 2005/12/07 02:56:35 kuniaki Exp"
 
 #ifdef RALOCAL
-#define RADB	"bvtest.bugest.net"
+#define RADB	"whois.epoch.net"
 #define WHOIS	43
 #endif /* _ifedef RALOCAL */
 #ifndef RALOCAL
@@ -109,7 +109,7 @@ char *connecthost;
 }
 #endif /* _ifdef LOG */
 
-int dbopen()
+void dbopen()
 {
 	struct hostent		*hp;
 	struct sockaddr_in	sin;
@@ -137,14 +137,14 @@ int dbopen()
 #endif
 }
 
-int dbclose()
+void dbclose()
 {
 	write(sc, "q\n", 2);
 	close(sc);
 
 }
 
-int batchmode()
+void batchmode()
 {
 	write(sc, "!!\n", 3);
 }
@@ -198,7 +198,7 @@ char *type;
 	return(ret);
 }
 
-int sread(buf, len)
+void sread(buf, len)
 char *buf;
 int  len;
 {
@@ -285,7 +285,7 @@ u_long asn;
 	char	asstr[128];
 	char	*data;
 
-	sprintf(asstr, "!man,AS%d\n", asn);
+	sprintf(asstr, "!man,AS%lu\n", asn);
 
 #ifdef DEBUG
 	printf("Command : %s", asstr);
@@ -512,7 +512,7 @@ char	*retc;
 	connectlog(JPWHOIS);
 #endif
 
-	sprintf(line, "AS%d\n", asn);
+	sprintf(line, "AS%lu\n", asn);
 	write(jpsoc,line,strlen(line));
 
 	jpfd = fdopen(jpsoc, "r");
@@ -571,7 +571,7 @@ char	*retc;
 	connectlog(APWHOIS);
 #endif
 
-	sprintf(line, "AS%d\n", asn);
+	sprintf(line, "AS%lu\n", asn);
 	write(apsoc,line,strlen(line));
 
 	apfd = fdopen(apsoc, "r");
@@ -686,7 +686,7 @@ char	*retc;
 	connectlog(JIWHOIS);
 #endif
 
-	sprintf(line, "AS%d\n", asn);
+	sprintf(line, "AS%lu\n", asn);
 	write(jisoc,line,strlen(line));
 
 	jifd = fdopen(jisoc, "r");
@@ -710,7 +710,7 @@ char	*retc;
 }
 #endif /* _JPIXDB */
 
-int searchas(aslist)
+void searchas(aslist)
 char *aslist;
 {
 	char	aslistbuf[1024];
@@ -738,7 +738,7 @@ char *aslist;
 #ifdef DEBUG
 					printf("DEBUG: descr field not found\n");
 #endif
-					printf("  AS%d:????????\n", asnum);
+					printf("  AS%lu:????????\n", asnum);
 				}
 #ifdef DEBUG
 				printf("DB Type -> RPSL?\n");
@@ -771,7 +771,7 @@ char *aslist;
 				if (desce != NULL) {
 					*desce = '\0';
 				}
-				printf("  AS%d:%s\n", asnum, descs);
+				printf("  AS%lu:%s\n", asnum, descs);
 			}
 			free(obj);
 		} else {
@@ -779,7 +779,7 @@ char *aslist;
 
 #ifdef JPIXDB
 		if (jpix(asnum, &asname) != NULL) {
-			printf("  AS%d:%s\n", asnum, asname);
+			printf("  AS%lu:%s\n", asnum, asname);
 		} else {
 #endif
 #ifdef ARINDB
@@ -790,7 +790,7 @@ char *aslist;
 #ifdef JPNICDB
 				if (strcmp(asname, JPNICTAG) == 0) {
 					if (jpnic(asnum, &asname) != NULL) {
-						printf("  AS%d:%s (JPNIC)\n",
+						printf("  AS%lu:%s (JPNIC)\n",
 								 asnum, asname);
 						fg = 1;
 					} else {
@@ -801,7 +801,7 @@ char *aslist;
 #ifdef APNICDB
 				if (strcmp(asname, APNICTAG) == 0) {
 					if (apnic(asnum, &asname) != NULL) {
-						printf("  AS%d:%s (APNIC)\n",
+						printf("  AS%lu:%s (APNIC)\n",
 								 asnum, asname);
 						fg = 1;
 					} else {
@@ -811,11 +811,11 @@ char *aslist;
 #endif
 				if (strlen(asname) != 0) {
 					if (fg == 0) {
-						printf("  AS%d:%s (ARIN)\n",
+						printf("  AS%lu:%s (ARIN)\n",
 								 asnum, asname);
 					}
 				} else {
-					printf("  AS%d:????????\n", asnum);
+					printf("  AS%lu:????????\n", asnum);
 				}
 			}
 #endif /* ARINDB */
@@ -823,11 +823,11 @@ char *aslist;
 #ifdef JPNICDB
 #ifdef APNICDB
 			if (jpnic(asnum, &asname) != NULL) {
-				printf("  AS%d:%s (JPNIC)\n", asnum, asname);
+				printf("  AS%lu:%s (JPNIC)\n", asnum, asname);
 			} else if (apnic(asnum, &asname) != NULL) {
-				printf("  AS%d:%s (APNIC)\n", asnum, asname);
+				printf("  AS%lu:%s (APNIC)\n", asnum, asname);
 			} else {
-				printf("  AS%d:????????\n", asnum);
+				printf("  AS%lu:????????\n", asnum);
 			}
 #endif
 #endif
@@ -835,9 +835,9 @@ char *aslist;
 #ifdef JPNICDB
 #ifndef APNICDB
 			if (jpnic(asnum, &asname) != NULL) {
-				printf("  AS%d:%s (JPNIC)\n", asnum, asname);
+				printf("  AS%lu:%s (JPNIC)\n", asnum, asname);
 			} else {
-				printf("  AS%d:????????\n", asnum);
+				printf("  AS%lu:????????\n", asnum);
 			}
 #endif
 #endif
@@ -845,16 +845,16 @@ char *aslist;
 #ifndef JPNICDB
 #ifdef APNICDB
 			if (apnic(asnum, &asname) != NULL) {
-				printf("  AS%d:%s (APNIC)\n", asnum, asname);
+				printf("  AS%lu:%s (APNIC)\n", asnum, asname);
 			} else {
-				printf("  AS%d:????????\n", asnum);
+				printf("  AS%lu:????????\n", asnum);
 			}
 #endif
 #endif
 
 #ifndef JPNICDB
 #ifndef APNICDB
-			printf("  AS%d:????????\n", asnum);
+			printf("  AS%lu:????????\n", asnum);
 #endif
 #endif
 
@@ -906,7 +906,7 @@ ASPATHCACHE *data;
 	return(ret);
 }
 
-int freecache()
+void freecache()
 {
 	ASPATHCACHE *ptr;
 
@@ -918,7 +918,7 @@ int freecache()
 	}
 }
 
-int parsestdin()
+void parsestdin()
 {
 
 	char	line[2048];
@@ -1020,6 +1020,7 @@ char *fname;
 	}
 	fclose(fp);
 	freecache();
+	return(0);
 }
 
 int host2as(hn)
@@ -1065,7 +1066,7 @@ char	*hn;
 #endif
 
 	if (getas(adstr, &getasnum) == 0) {
-		printf("% Search Fail\n");
+		printf("%% Search Fail\n");
 	} else {
 #ifdef DEBUG
 		printf("Search AS : %s\n",getasnum);
@@ -1088,10 +1089,11 @@ char	*hn;
 			asptr++;
 		}
 	}
+	return(0);
 }
 
 
-main(argc, argv)
+int main(argc, argv)
 int argc;
 char *argv[];
 {
