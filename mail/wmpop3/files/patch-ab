--- Pop3Client.c.orig  Sat Mar  2 13:18:27 2002
+++ Pop3Client.c       Sat Mar  2 13:23:11 2002
@@ -153,7 +153,12 @@

      if( temp[0] != '+' ){
          perror("Error Reciving Stats");
+         perror("This pop3 server dose not support LAST command.");
+         perror("I use 0 instread of the unkown result.");
+         pc->numOfUnreadMessages = pc->numOfMessages;
+/*
          return -1;
+*/
      }
      return 1;

