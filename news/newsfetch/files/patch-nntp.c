--- nntp.c.orig	Sat Aug  3 19:24:46 2002
+++ nntp.c	Sat Aug  3 19:26:29 2002
@@ -33,7 +33,7 @@
 {
 	/* dummy read to flush input */
 	readNNTPdata();
-	fprintf(socket_fp[0],"MODE READER\n");
+	fprintf(socket_fp[0],"MODE READER\r\n");
 	readNNTPdata();
 return(get_error(command_buf));
 }
@@ -151,7 +151,7 @@
 int first_art, last_art, total_art, tmp ;
 
 	fprintf(stderr,"%s: ",group);
-	fprintf(socket_fp[0],"GROUP %s\n",group);
+	fprintf(socket_fp[0],"GROUP %s\r\n",group);
 	readNNTPdata();
 	
 	#ifdef DEBUG
@@ -180,7 +180,7 @@
 		first_article = last_art - max_article + 1;
 	}
 	
-	fprintf(socket_fp[0],"STAT %d\n",first_article);
+	fprintf(socket_fp[0],"STAT %d\r\n",first_article);
 	readNNTPdata();
 
 	while(!get_error1(command_buf))
@@ -196,7 +196,7 @@
 			return(0); 
 			}
 
-		fprintf(socket_fp[0],"STAT %d\n",first_article);
+		fprintf(socket_fp[0],"STAT %d\r\n",first_article);
 		readNNTPdata();
 		}
 	fprintf(stderr,"articles %d to %d\n",first_article,last_art);
@@ -256,7 +256,7 @@
 		fprintf(stderr,"                                    %c",0xd);
 	}
 
-	fprintf(socket_fp[0],"ARTICLE\n");
+	fprintf(socket_fp[0],"ARTICLE\r\n");
 	readNNTPdata();
 	if(!get_error(command_buf))
 		return(0);	
@@ -275,7 +275,7 @@
 		}
 
 	/* Make it little fast */
-	fprintf(socket_fp[0],"NEXT\n");
+	fprintf(socket_fp[0],"NEXT\r\n");
 
 	article_fetching=1;
 
@@ -329,7 +329,7 @@
 char groupname[100];
 
 	fprintf(stderr, "\nList of NewsGroups:\n"); 
-	fprintf(socket_fp[0],"LIST\n");
+	fprintf(socket_fp[0],"LIST\r\n");
 	readNNTPdata();
 	if(!get_error2(command_buf))
 		exit(1);	
@@ -348,7 +348,7 @@
 sendQuit()
 {
 
-	fprintf(socket_fp[0],"QUIT\n");
+	fprintf(socket_fp[0],"QUIT\r\n");
 	readNNTPdata();
 }
 
