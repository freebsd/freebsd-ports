--- rnews.c	2002-05-18 20:21:26.000000000 +0100
+++ rnews.c	2002-09-08 12:50:41.000000000 +0100
@@ -2,6 +2,8 @@
  *  S-News version 0.1.9 - A Simple News Server
  *  Copyright (C) 1998 Christopher John Purnell
  *                     cjp@lost.org.uk
+ *  Supersedes/cancel modifications (C) 2002 Tony Houghton
+ *  		       tony@realh.co.uk
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
@@ -50,6 +52,8 @@
 
 #include "snews.h"
 
+#define DEBLOG(a) /* fprintf a */
+
 struct header
 {
 	struct header *next;
@@ -78,14 +82,23 @@
 static FILE *open_lock(char *);
 static int file_name(struct header *,char *,unsigned);
 static GDBM_FILE open_history(char *,int);
+static int read_string(FILE *,char *,unsigned);
+static void delete_msg(const char *);
+static int whole_string(struct header_pointer *,char *,unsigned);
+static int read_line(FILE *,char *,unsigned);
+static int isolate_addr(char *);
 
 static char *progname;
 static char fqdn[BUFLEN];
 static char msgid[BUFLEN];
 static char article[BUFLEN];
+static char vsender[BUFLEN];
+static char cancel[BUFLEN];
 static char queue=0,approved=0;
+static int cancel_only;
 
 struct header junk = { 0, "junk", 0 };
+struct header control_cancel = { 0, "control.cancel", 0 };
 
 int main(int argc,char **argv)
 {
@@ -95,6 +108,16 @@
 
 	set_ug_id();
 
+	/* For logging, remove this in release */
+	/*
+	i = open("/var/log/news/rnews", O_WRONLY|O_CREAT|O_APPEND, 0644);
+	if (i)
+	{
+	    close(2);
+	    dup2(i, 2);
+	}
+	*/
+
 	progname = argv[0];
 
 	if (get_fqdn())
@@ -116,12 +139,18 @@
 		return (1);
 	}
 
+	cancel[0] = 0;
+	vsender[0] = 0;
+	cancel_only = 0;
+
 	if (!(hdr = read_header()))
 		return (1);
 
 	if (!(ngrp = parse_header(hdr)))
 		return (1);
 
+	DEBLOG((stderr, "Message-ID: %s\n", msgid));
+
 	if (!(fp = open_lock(CONFDIR"/active.n")))
 	{
 		perror(progname);
@@ -130,8 +159,16 @@
 	
 	if (!(i = chk_article(msgid)))
 	{
-		if (!(ngrp = update_active(CONFDIR"/active",CONFDIR"/active.n",
-					  fp,ngrp)))
+		DEBLOG((stderr, "chk_article OK\n"));
+		if (cancel_only)
+		{
+			ngrp = update_active(CONFDIR"/active",
+					     CONFDIR"/active.n",
+					     fp,&control_cancel);
+			DEBLOG((stderr, "cancel_only, ngrp = %d\n", ngrp));
+		}
+		else if (!(ngrp = update_active(CONFDIR"/active",
+			    CONFDIR"/active.n",fp,ngrp)))
 		{
 			rewind(fp);
 			if (ftruncate(fileno(fp),0))
@@ -144,8 +181,11 @@
 		i = !ngrp;
 	}
 
+	DEBLOG((stderr, "After chk_article and update_active, result = %d (0 is good)\n", i));
+
 	if (fclose(fp) || i || write_article(hdr,ngrp))
 	{
+		DEBLOG((stderr, "fclose || i || write_article failed\n"));
 		unlink(CONFDIR"/active.n");
 		return (1);
 	}
@@ -158,6 +198,9 @@
 		return (1);
 	}
 
+	if (cancel[0])
+		delete_msg(cancel);
+
 	if (!queue) return (0);
 
 	execl(QNEWSPATH,QNEWSARG0,article,0);
@@ -301,11 +344,79 @@
 			{
 				approved=1;
 			}
+			else if (!strncasecmp(hdr->line,"Sender:",7))
+			{
+				hp.hdr = hdr;
+				hp.ptr = hdr->line+7;
+				if (whole_string(&hp,vsender,BUFLEN)<=0)
+				{
+					fprintf(stderr,"%s: bad Sender\n",
+						progname);
+					return (0);
+				}
+				DEBLOG((stderr, "Found Sender: %s\n", vsender));
+			}
+			else if (!vsender[0] && !strncasecmp(hdr->line,"From:",5))
+			{
+				hp.hdr = hdr;
+				hp.ptr = hdr->line+5;
+				if (whole_string(&hp,vsender,BUFLEN)<=0)
+				{
+					fprintf(stderr,"%s: bad From\n",
+						progname);
+					return (0);
+				}
+				DEBLOG((stderr, "Found From: %s\n", vsender));
+			}
+			else if (!strncasecmp(hdr->line,"Supersedes:",11))
+			{
+				hp.hdr = hdr;
+				hp.ptr = hdr->line+11;
+				if (whole_string(&hp,cancel,BUFLEN)<=0)
+				{
+					fprintf(stderr,"%s: bad Supersedes\n",
+						progname);
+					return (0);
+				}
+				DEBLOG((stderr, "Found Supersedes: %s\n", cancel));
+			}
+			else if (!strncasecmp(hdr->line,"Control: cancel",15))
+			{
+				hp.hdr = hdr;
+				hp.ptr = hdr->line+15;
+				if (whole_string(&hp,cancel,BUFLEN)<=0)
+				{
+					fprintf(stderr,"%s: bad cancel\n",
+						progname);
+					return (0);
+				}
+				DEBLOG((stderr, "Found cancel: %s\n", cancel));
+				cancel_only = 1;
+			}
+			else if (!strncasecmp(hdr->line,"Also-Control: cancel",20))
+			{
+				hp.hdr = hdr;
+				hp.ptr = hdr->line+20;
+				if (whole_string(&hp,cancel,BUFLEN)<=0)
+				{
+					fprintf(stderr,"%s: bad cancel\n",
+						progname);
+					return (0);
+				}
+				DEBLOG((stderr, "Found also-cancel: %s\n", cancel));
+			}
 
 		}
 		hdr = hdr->next;
 	}
 
+	if (vsender[0])
+	{
+		int ires=isolate_addr(vsender);
+		DEBLOG((stderr,"vsender address = %s (result %d)\n",
+					vsender,ires));
+	}
+	
 	return (*msgid?ret:0);
 }
 
@@ -597,7 +708,10 @@
 	int ret;
 
 	if (!(dbf = open_history(CONFDIR"/history",GDBM_READER)))
+	{
+		DEBLOG((stderr, "chk_article: Couldn't open history\n"));
 		return (1);
+	}
 
 	key.dsize = strlen(key.dptr = id) + 1;
 
@@ -605,6 +719,7 @@
 
 	gdbm_close(dbf);
 
+	DEBLOG((stderr, "chk_article: %s exists: %d\n", id, ret));
 	return (ret);
 }
 
@@ -642,3 +757,232 @@
 	}
 	return (dbf);
 }
+
+/* Added by Tony Houghton <tony@realh.co.uk>, mostly copied from expire.c */
+
+static void delete_msg(const char *msgid)
+{
+	char buf[BUFLEN];
+	char sender[BUFLEN];
+	struct stat st;
+	FILE *fp;
+	GDBM_FILE dbf;
+	datum key,value;
+	char *file;
+
+	DEBLOG((stderr, "Deleting %s\n", msgid));
+	if (!(dbf = open_history(CONFDIR"/history",GDBM_READER)))
+		return;
+	key.dsize = strlen(key.dptr = (char *) msgid) + 1;
+	value = gdbm_fetch(dbf, key);
+	if ((file = value.dptr) == NULL)
+		return;
+	DEBLOG((stderr, "Filename is %s\n", file));
+	
+	if (!(fp = fopen(file,"r")))
+	{
+		if (errno != ENOENT)
+			perror(file);
+		free(file);
+		return;
+	}
+
+	if (fstat(fileno(fp),&st))
+	{
+		perror(file);
+		free(file);
+		return;
+	}
+
+	sender[0] = 0;
+	while (fgets(buf,6,fp))
+	{
+		if (!sender[0] && !strcasecmp(buf,"From:"))
+		{
+			if (read_line(fp,sender,BUFLEN) <= 0)
+			{
+				fclose(fp);
+				fprintf(stderr,"%s: bad From header\n",file);
+				free(file);
+				return;
+			}
+			DEBLOG((stderr, "From: %s\n", sender));
+		}
+		else if (!strcasecmp(buf,"Sende") && fgetc(fp) == 'r' &&
+			fgetc(fp) == ':')
+		{
+			if (read_line(fp,sender,BUFLEN) <= 0)
+			{
+				fclose(fp);
+				fprintf(stderr,"%s: bad Sender\n",file);
+				free(file);
+				return;
+			}
+			DEBLOG((stderr, "Sender: %s\n", sender));
+		}
+		else if (buf[0] == '\n')
+			break;
+	}
+	rewind(fp);
+	if (isolate_addr(sender) == -1)
+	{
+		fprintf(stderr,"Invalid sender, can't cancel\n");
+		free(file);
+		fclose(fp);
+		return;
+	}
+	DEBLOG((stderr,"Sender address = %s\n",sender));
+
+	if (strcasecmp(sender,vsender))
+	{
+		fprintf(stderr,"Wrong sender, can't cancel\n");
+		free(file);
+		fclose(fp);
+		return;
+	}
+
+	while (fgets(buf,6,fp))
+	{
+		char *cp;
+		int c;
+
+		if (strcasecmp(buf,"Xref:"))
+		{
+			if ((cp = strchr(buf,'\n')))
+			{
+				if (cp == buf) break;
+			}
+			else
+			{
+				while ((c = fgetc(fp)) != EOF && c != '\n');
+				if (c == EOF) break;
+			}
+		}
+		else
+		{
+			if ((read_string(fp,buf,BUFLEN) <= 0) ||
+			    strcasecmp(buf,fqdn))
+			{
+				fclose(fp);
+				fprintf(stderr,"%s: bad Xref line\n",file);
+				free(file);
+				return;
+			}
+
+			while ((c = read_string(fp,buf,BUFLEN)))
+			{
+				if (c < 0)
+				{
+					fclose(fp);
+					fprintf(stderr,"%s: bad Xref line\n",
+						file);
+					free(file);
+					return;
+				}
+
+				cp = buf;
+				while ((c = *cp))
+				{
+					if (c == '.' || c ==':')
+						*cp = '/';
+					++cp;
+				}
+
+				if (strcmp(file,buf) &&
+				    unlink(buf) && errno != ENOENT)
+				{
+					perror(buf);
+					fclose(fp);
+					free(file);
+					return;
+				}
+			}
+
+			break;
+		}
+	}
+	if (ferror(fp))
+	{
+		perror(file);
+		free(file);
+		fclose(fp);
+		return;
+	}
+
+	fclose(fp);
+	if (unlink(file))
+		perror(file);
+	free(file);
+}
+
+static int read_string(FILE *fp,char *str,unsigned len)
+{
+	int c;
+	unsigned i=0;
+
+	while ((c = fgetc(fp)) != EOF && c != '\n' && isspace(c));
+
+	while (c != EOF && !isspace(c))
+	{
+		str[i]=c;
+		if (++i>=len) return (-1);
+		c = fgetc(fp);
+	}
+	str[i]='\0';
+
+	return (i);
+}
+
+static int whole_string(struct header_pointer *hp,char *str,unsigned len)
+{
+        unsigned i=0;
+	unsigned char c;
+
+        while ((c = next_char(hp)) && isspace(c));
+
+        while (c && c != '\n')
+        {
+                str[i]=c;
+                if (++i>=len) return (-1);
+                c = next_char(hp);
+        }
+	str[i]='\0';
+
+        return (i);
+}
+ 
+static int read_line(FILE *fp,char *str,unsigned len)
+{
+	int c;
+	unsigned i=0;
+
+	while ((c = fgetc(fp)) != EOF && c != '\n' && isspace(c));
+
+	while (c != EOF && c != '\n')
+	{
+		str[i]=c;
+		if (++i>=len) return (-1);
+		c = fgetc(fp);
+	}
+	str[i]='\0';
+
+	return (i);
+}
+
+static int isolate_addr(char *str)
+{
+    char *at;
+    unsigned len;
+
+    if (!(at=strchr(str,'@')))
+	    return -1;
+    while (at != str && !isspace(*(at-1)) && *(at-1) != '<')
+	    --at;
+    for (len = 0;
+	 len <= strlen(at) && !isspace(at[len]) && at[len] !='>';
+	 ++len);
+    memmove(str,at,len);
+    str[len]=0;
+    return 0;
+}
+
