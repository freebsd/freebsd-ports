
$FreeBSD$

--- asfsm.c.orig	Sun Oct 18 12:02:09 1998
+++ asfsm.c	Thu Aug 15 23:19:02 2002
@@ -2,10 +2,10 @@
 /* Author: David Muse <mused@examco.com> 1997 */
 #include <stdio.h>
 #include <string.h>
-#include <Xlib.h>
-#include <Intrinsic.h>
-#include <xpm.h>
-#include <extensions/shape.h>
+#include <X11/Xlib.h>
+#include <X11/Intrinsic.h>
+#include <X11/xpm.h>
+#include <X11/extensions/shape.h>
 #ifdef SIXTEENBIT
 	#include "16bit/surreal.xpm"
 	#include "16bit/purplestoneswirl.xpm"
@@ -98,10 +98,10 @@
 	int	flag=0;
 	
 	/* figure out which "df -" command to use */
-	tempfile=popen("df -Bk","r");
+	tempfile=popen("df -k","r");
 	fscanf(tempfile,"%s",word);
 	if (!strcmp(word,"Filesystem")) {
-		sprintf(dfcommand,"df -Bk");
+		sprintf(dfcommand,"df -k");
 	} else {
 		tempfile=popen("df -a","r");
 		fscanf(tempfile,"%s",word);
@@ -135,27 +135,6 @@
 	}
 	fclose(tempfile);
 
-	/* detect which user mount/unmount command to use */
-	/* by giving umnt a bum parameter (-h) and seeing if it */
-	/* returns anything about an illegal option or if it just says */
-	/* command not found.  Different shells have different messages */
-	/* for not finding a command, and which behaves differently too, */
-	/* so this seems a reasonable way to do it. */
-	tempfile=popen("umnt -h > /usr/tmp/testumnt 2> /usr/tmp/testumnt; cat /usr/tmp/testumnt; rm /usr/tmp/testumnt","r");
-	while(!feof(tempfile)) {
-		fscanf(tempfile,"%s",word);
-		if (!strcmp("option",word)) {
-			/* the response must have been 
-		 	umnt: ERROR: Illegal option -- h
-		 	or something like it, the command exists */
-			sprintf(mountcmd,"mnt ");
-			sprintf(umountcmd,"umnt ");
-			flag=1;
-			break;
-		}
-	}
-	pclose(tempfile);
-
 	if (flag==0) {
 		/* otherwise, the mount/unmount commands must be used */
 		sprintf(mountcmd,"mount ");
@@ -374,7 +353,8 @@
 				fs[counter].percent,
 				fs[counter].mountdir);
 			if (strlen(fs[counter].mountdir)>0 && counter<23) {	
-				if (atoi(fs[counter].blocks)>0 || showzero==1) {
+				if ((atoi(fs[counter].blocks)>0 || showzero==1) &&
+									(strcmp(fs[counter].mountdir, "/proc"))){
 					counter++;
 				}
 			} else {
@@ -721,7 +701,7 @@
 			};
 
 			if (!feof(fstabfile)) {
-				if (buffer[0]!='#') {
+				if (buffer[0]!='#' && strncmp(buffer, "proc", 4)) {
 					strcpy(fstab[fstabcounter].filesystem,
 						"");
 					strcpy(fstab[fstabcounter].mountdir,"");
