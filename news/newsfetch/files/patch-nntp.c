--- nntp.c.orig	Thu Jul 23 12:03:11 1998
+++ nntp.c	Thu Jan 27 17:19:01 2005
@@ -20,6 +20,7 @@
 
 char *header;
 #define MAXBUFSIZE 500
+#define GROUP_FMT "%99s"
 char command_buf[MAXBUFSIZE+1];
 
 readNNTPdata()
@@ -33,7 +34,7 @@
 {
 	/* dummy read to flush input */
 	readNNTPdata();
-	fprintf(socket_fp[0],"MODE READER\n");
+	fprintf(socket_fp[0],"MODE READER\r\n");
 	readNNTPdata();
 return(get_error(command_buf));
 }
@@ -140,7 +141,8 @@
 	else
 		fprintf(rctmpfp,"%s",command_buf);
 	}
-	items_read=sscanf(command_buf,"%s %d %d", group, &first_article, &max_article);
+	items_read=sscanf(command_buf,GROUP_FMT "%d %d", group, &first_article, &max_article);
+	group[sizeof(group)-1] = '\0';
 	if(items_read < 2)
 		return(0);
 return(items_read);
@@ -151,7 +153,7 @@
 int first_art, last_art, total_art, tmp ;
 
 	fprintf(stderr,"%s: ",group);
-	fprintf(socket_fp[0],"GROUP %s\n",group);
+	fprintf(socket_fp[0],"GROUP %s\r\n",group);
 	readNNTPdata();
 	
 	#ifdef DEBUG
@@ -180,7 +182,7 @@
 		first_article = last_art - max_article + 1;
 	}
 	
-	fprintf(socket_fp[0],"STAT %d\n",first_article);
+	fprintf(socket_fp[0],"STAT %d\r\n",first_article);
 	readNNTPdata();
 
 	while(!get_error1(command_buf))
@@ -196,7 +198,7 @@
 			return(0); 
 			}
 
-		fprintf(socket_fp[0],"STAT %d\n",first_article);
+		fprintf(socket_fp[0],"STAT %d\r\n",first_article);
 		readNNTPdata();
 		}
 	fprintf(stderr,"articles %d to %d\n",first_article,last_art);
@@ -256,7 +258,7 @@
 		fprintf(stderr,"                                    %c",0xd);
 	}
 
-	fprintf(socket_fp[0],"ARTICLE\n");
+	fprintf(socket_fp[0],"ARTICLE\r\n");
 	readNNTPdata();
 	if(!get_error(command_buf))
 		return(0);	
@@ -275,7 +277,7 @@
 		}
 
 	/* Make it little fast */
-	fprintf(socket_fp[0],"NEXT\n");
+	fprintf(socket_fp[0],"NEXT\r\n");
 
 	article_fetching=1;
 
@@ -329,17 +331,19 @@
 char groupname[100];
 
 	fprintf(stderr, "\nList of NewsGroups:\n"); 
-	fprintf(socket_fp[0],"LIST\n");
+	fprintf(socket_fp[0],"LIST\r\n");
 	readNNTPdata();
 	if(!get_error2(command_buf))
 		exit(1);	
 	readNNTPdata();
-	sscanf(command_buf,"%s",groupname);
+	sscanf(command_buf,GROUP_FMT,groupname);
+	groupname[sizeof(groupname)-1] = '\0';
 	while(command_buf[0] != '.' || command_buf[1] != 13 )/*|| command_buf[1] != 10)*/
 		{
 		fprintf(stderr,"%s\n",groupname);
 		readNNTPdata();
-		sscanf(command_buf,"%s",groupname);
+		sscanf(command_buf,GROUP_FMT,groupname);
+		groupname[sizeof(groupname)-1] = '\0';
 		}
 exit(1);
 
@@ -348,7 +352,7 @@
 sendQuit()
 {
 
-	fprintf(socket_fp[0],"QUIT\n");
+	fprintf(socket_fp[0],"QUIT\r\n");
 	readNNTPdata();
 }
 
