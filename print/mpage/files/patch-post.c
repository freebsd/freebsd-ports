$OpenBSD: patch-post_c,v 1.2 2002/11/13 17:15:49 naddy Exp $
--- post.c.orig	Wed Oct 16 23:45:54 2002
+++ post.c	Wed Nov 13 18:04:56 2002
@@ -353,6 +353,7 @@ ps_copyprolog(fd, outfd)
  FILE *fd;
  FILE *outfd;
 {
+    size_t len;
 
     Debug(DB_PSDOC, "%%ps_copyprolog: adding mpage prolog\n", 0);
     if (!have_showsheet) {
@@ -399,15 +400,17 @@ ps_copyprolog(fd, outfd)
                  */
                 if (tex1)
                     free(tex1);
-                tex1 = malloc(strlen(currline)+1);
-                strcpy(tex1, currline);
+                len = strlen(currline)+1;
+                tex1 = malloc(len);
+                (void)strlcpy(tex1, currline, len);
                 fprintf(outfd, "%s", currline);
 
                 fgets(currline, LINESIZE-1, fd);
                 if (tex2)
                     free(tex2);
-                tex2 = malloc(strlen(currline)+1);
-                strcpy(tex2, currline);
+                len = strlen(currline)+1;
+                tex2 = malloc(len);
+                (void)strlcpy(tex2, currline, len);
             }
         }
         fprintf(outfd, "%s", currline);
@@ -432,7 +435,7 @@ ps_roff_copyprolog(fd, outfd)
  /*       if (strcmp(currline, "xi\n") == 0) */
         if (strstr(currline, "xi\n")) {
             fprintf(outfd, "%%%s", currline); 
-            strcpy(ps_roff_xi, currline);
+            (void)strlcpy(ps_roff_xi, currline, sizeof(ps_roff_xi));
         }
         else if (strncmp(currline, "%%Page:", 7) == 0) {
             fprintf(outfd, "/p { } def\n");
@@ -1013,6 +1016,8 @@ post_one_line(line, fd, outfd, indoc, fl
  int * indoc;
  int flush_page;
 {
+        size_t len;
+
         if (strncmp(line, "%%BeginDocument", 15) == 0) {
             (*indoc)++;
         }
@@ -1063,15 +1068,17 @@ post_one_line(line, fd, outfd, indoc, fl
                      */
                     if (tex1)
                         free(tex1);
-                    tex1 = malloc(strlen(line)+1);
-                    strcpy(tex1, line);
+                    len = strlen(line)+1;
+                    tex1 = malloc(len);
+                    (void)strlcpy(tex1, line, len);
                     fprintf(outfd, "%s", line);
                     flush_page ?  memgets(line, LINESIZE-1) :
                                   fgets(line, LINESIZE-1, fd);
                     if (tex2)
                         free(tex2);
-                    tex2 = malloc(strlen(line)+1);
-                    strcpy(tex2, line);
+                    len = strlen(line)+1;
+                    tex2 = malloc(len);
+                    (void)strlcpy(tex2, line, len);
                 } 
             }
 	}
