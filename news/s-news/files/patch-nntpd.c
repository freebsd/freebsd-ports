--- nntpd.c.orig	Sat May 18 22:21:56 2002
+++ nntpd.c	Wed Aug  4 03:40:06 2004
@@ -2,6 +2,7 @@
  *  S-News version 0.1.9 - A Simple News Server
  *  Copyright (C) 1998 Christopher John Purnell
  *                     cjp@lost.org.uk
+ *  XPAT support added in 2002 by Tony Houghton <tony@realh.co.uk>
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
@@ -22,6 +23,8 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/utsname.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -106,6 +109,7 @@
 static void do_listgroup(char *);
 static void do_xover(char *);
 static void do_xhdr(char *);
+static void do_xpat(char *);
 static void do_xpath(char *);
 static void do_ihave(char *);
 static void do_post(char *);
@@ -239,6 +243,10 @@
 		{
 			do_xhdr(arg);
 		}
+		else if (!strcasecmp(line,"xpat"))
+		{
+			do_xpat(arg);
+		}
 		else if (!strcasecmp(line,"xover"))
 		{
 			do_xover(arg);
@@ -811,10 +819,11 @@
 	printf(".\r\n");
 }
 
+static char *xhdr_h[7] = { "Subject","From","Date","Message-ID",
+		      "References","Bytes","Lines" };
+
 static void do_xhdr(char *arg)
 {
-	static char *h[7] = { "Subject","From","Date","Message-ID",
-			      "References","Bytes","Lines" };
 	char *fmt,*cp;
 	unsigned char c;
 	int i;
@@ -835,7 +844,7 @@
 	i = -1; fmt = "%u \r\n";
 	for (u=0; u<7; ++u)
 	{
-		if (!strcasecmp(arg,h[u]))
+		if (!strcasecmp(arg,xhdr_h[u]))
 		{
 			fmt = ((i=u) < 5) ? "%u %s\r\n" : "%u %u\r\n";
 		}
@@ -1118,6 +1127,7 @@
 		printf("ARTICLE   HEAD      BODY      STAT\r\n");
 		printf("GROUP     LIST      NEXT      LAST\r\n");
 		printf("LISTGROUP XHDR      XOVER     XPATH\r\n");
+		printf("XPAT      ");
 	}
 	if (canpost)
 	{
@@ -1127,7 +1137,7 @@
 	{
 		printf("IHAVE     ");
 	}
-	printf("HELP      QUIT\r\n.\r\n");
+	printf("\r\nHELP      QUIT\r\n.\r\n");
 }
 
 static int match_pat(char *pat,char *str)
@@ -1533,3 +1543,177 @@
 
 	return str;
 }
+
+static int match_pattern(const char *pat,const char *str)
+{
+	char c;
+
+	while ((c = *(pat++)))
+	{
+		switch (c)
+		{
+		case '*':
+			if (!*pat)
+				return (1);
+			while (*str)
+			{
+				if (match_pattern(pat,str))
+					return (1);
+				++str;
+			}
+			break;
+		case '?':
+			if (!*str)
+				return (0);
+			break;
+		case '[':
+			if (*str)
+			{
+				unsigned char rev,mat=0,l=0,h,u=*str;
+
+				if ((rev = (*pat=='^'?1:0)))
+					pat++;
+				if ((c=*pat)) do
+				{
+					pat++;
+					if (c=='-' && l && (h=*pat) && h!=']')
+					{
+						pat++;
+						if (u>=l && u<=h) mat=1;
+						l = 0;
+					}
+					else
+					{
+						if (u==c) mat=1;
+						l = c;
+					}
+				}
+				while ((c=*pat) && c!=']');
+				if (c)
+					++pat;
+				if (mat==rev)
+					return (0);
+			}
+			else
+				return (0);
+			break;
+		default:
+			if (*str!=c)
+				return (0);
+			break;
+		}
+		++str;
+	}
+
+	return (!*str);
+}
+
+static void do_xpat(char *arg)
+{
+	char *cp;
+	unsigned char c;
+	int i;
+	unsigned u,l;
+	char const **patterns = NULL;
+	size_t pat_size = 0;
+	size_t npats = 0;
+
+	if (check_read()) return;
+
+	if (!grp)
+	{
+		printf("412 no newsgroup has been selected\r\n");
+		return;
+	}
+
+	cp = arg;
+	while ((c=*(cp)) && !isspace(c)) cp++;
+	if (*cp) *(cp++) = '\0';
+
+	i = -1;
+	for (u=0; u<7; ++u)
+	{
+		if (!strcasecmp(arg,xhdr_h[u]))
+		{
+		//	fmt = ((i=u) < 5) ? "%u %s\r\n" : "%u %u\r\n";
+			i = u;
+		}
+	}
+	if (i == -1)
+	{
+		printf("501 header not in index\r\n");
+		return;
+	}
+
+	while ((c=*(cp)) && isspace(c)) cp++;
+	if (*cp)
+	{
+		u = strtoul(cp,&cp,10);
+		if (*cp == '-')
+		{
+			if (*(++cp)) l = strtoul(cp,&cp,10);
+			else l = grp->last;
+		}
+		else l = u;
+	}
+	else u = l = art;
+
+	if (!u)
+	{
+		printf("420 no article has been selected\r\n");
+		return;
+	}
+
+	patterns = malloc(sizeof(char const *));
+	pat_size = 1;
+	do
+	{
+		while (*cp && isspace(*cp)) ++cp;
+		if (*cp)
+		{
+			if (npats + 1 > pat_size)
+			{
+				patterns = realloc(patterns, (pat_size *= 2) *
+						sizeof(const char *));
+			}
+			patterns[npats++] = cp;
+			while (*cp && !isspace(*cp)) ++cp;
+			if (*cp) *(cp++) = 0;
+		}
+	} while (*cp);
+	if (!npats)
+	{
+		free(patterns);
+		printf("501 command syntax error\r\n");
+	}
+
+	printf("221 Header follows\r\n");
+	
+	while (u <= l)
+	{
+		struct overview *o;
+
+		if ((o = find_overview(u)))
+		{
+			size_t pat;
+			char matchnum[12];
+			char *match = i < 5 ? (&o->subject)[i] :
+				(sprintf(matchnum, "%u", ((unsigned *)
+							  (&o->subject))[i]),
+				 matchnum);
+
+			for (pat = 0; pat < npats; ++pat)
+			{
+				if (match_pattern(patterns[pat], match))
+				{
+					printf("%u %s\r\n", u, match);
+				}
+			}
+		}
+		++u;
+	}
+
+	printf(".\r\n");
+	free(patterns);
+}
+
