--- qnews.c.orig	Sat May 18 22:21:42 2002
+++ qnews.c	Sat Dec 18 19:21:57 2004
@@ -2,6 +2,8 @@
  *  S-News version 0.1.9 - A Simple News Server
  *  Copyright (C) 1998 Christopher John Purnell
  *                     cjp@lost.org.uk
+ *  flock modification (c) 2002 Tony Houghton
+ *  		       tony@realh.co.uk
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
@@ -22,12 +24,20 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
 #include <sys/stat.h>
+#ifdef HAVE_SYS_FILE_H
+#include <sys/file.h>
+#endif
+#include <fcntl.h>
+
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #ifdef STDC_HEADERS
 #include <string.h>
@@ -79,15 +89,37 @@
 			if (match_group(ptr->value,line,end))
 			{
 				FILE *fp;
+			#ifdef HAVE_SYS_FILE_H
+				int fd;
+			#endif
 
 				sprintf(file,CONFDIR"/suck/%s/outgoing",
-					ptr->name);
+				    ptr->name);
 
-				if (!(fp = fopen(file,"a")))
+			#ifdef HAVE_SYS_FILE_H
+				if ((fd = open(file,O_WRONLY|O_APPEND|O_CREAT,
+						0644)) == -1)
 				{
-					perror(file);
-					return (1);
+				    perror(file);
+				    return (1);
+				}
+				if (flock(fd,LOCK_EX) == -1)
+				{
+				    perror(file);
+				    return (1);
+				}
+				if (!(fp = fdopen(fd,"a")))
+				{
+				    perror(file);
+				    return (1);
 				}
+			#else
+                                if (!(fp = fopen(file,"a")))
+                                {
+                                        perror(file);
+                                        return (1);
+                                }
+			#endif
 
 				if (fputs(line,fp) < 0 ||
 				    fputc('\n',fp) < 0)
@@ -103,6 +135,9 @@
 					return (1);
 				}
 
+				/* By commenting this break we can post to
+				 * multiple servers instead of stopping after
+				 * first match*/
 				break;
 			}
 		}
@@ -204,7 +239,7 @@
 				return (0);
 			break;
 		case '[':
-			if (str>=end)
+			if (str<end)
 			{
 				unsigned char rev,mat=0,l=0,h,u=*str;
 
@@ -229,6 +264,8 @@
 				if (mat==rev)
 					return (0);
 			}
+			else
+				return (0);
 			break;
 		default:
 			if (str>=end || *str!=c)
