--- socket.c.orig	2022-01-28 14:06:02 UTC
+++ socket.c
@@ -141,12 +141,14 @@
   char *firstn = NULL;
   int nfound = 0, ngood = 0, ndead = 0, nwipe = 0, npriv = 0;
   int nperfect = 0;
+  char timestr[64];
   struct sent
     {
       struct sent *next;
       int mode;
       char *name;
-    } *slist, **slisttail, *sent, *nsent;
+      time_t time_created;
+    } *slist, **slisttail, *sent, *nsent, *schosen;
 
   if (match)
     {
@@ -258,8 +260,13 @@
       sent->next = 0;
       sent->name = SaveStr(name);
       sent->mode = mode;
+      sent->time_created = SessionCreationTime(name);
+      for (slisttail = &slist; *slisttail; slisttail = &((*slisttail)->next))
+        {
+          if ((*slisttail)->time_created < sent->time_created) break;
+        }
+      sent->next = *slisttail;
       *slisttail = sent;
-      slisttail = &sent->next;
       nfound++;
       sockfd = MakeClientSocket(0, *is_sock);
 #ifdef USE_SETEUID
@@ -359,34 +366,42 @@
 	}
       for (sent = slist; sent; sent = sent->next)
 	{
+          if (sent->time_created == 0)
+            {
+              sprintf(timestr, "??" "?");
+            }
+          else
+            {
+              strftime(timestr, 64, "%x %X", localtime(&sent->time_created));
+            }
 	  switch (sent->mode)
 	    {
 	    case 0700:
-	      printf("\t%s\t(Attached)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Attached)\n", sent->name, timestr);
 	      break;
 	    case 0600:
-	      printf("\t%s\t(Detached)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Detached)\n", sent->name, timestr);
 	      break;
 #ifdef MULTIUSER
 	    case 0701:
-	      printf("\t%s\t(Multi, attached)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Multi, attached)\n", sent->name, timestr);
 	      break;
 	    case 0601:
-	      printf("\t%s\t(Multi, detached)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Multi, detached)\n", sent->name, timestr);
 	      break;
 #endif
 	    case -1:
 	      /* No trigraphs here! */
-	      printf("\t%s\t(Dead ?%c?)\n", sent->name, '?');
+	      printf("\t%s\t(%s)\t(Dead ?%c?)\n", sent->name, timestr, '?');
 	      break;
 	    case -2:
-	      printf("\t%s\t(Removed)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Removed)\n", sent->name, timestr);
 	      break;
 	    case -3:
-	      printf("\t%s\t(Remote or dead)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Remote or dead)\n", sent->name, timestr);
 	      break;
 	    case -4:
-	      printf("\t%s\t(Private)\n", sent->name);
+	      printf("\t%s\t(%s)\t(Private)\n", sent->name, timestr);
 	      break;
 	    }
 	}
