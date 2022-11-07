--- wmmaiload/checkthread.c.orig	2009-02-23 02:59:20 UTC
+++ wmmaiload/checkthread.c
@@ -85,7 +85,7 @@ static Bool check_imap(MailBox *box, time_t now);
 #endif /* HAVE_IMAP */
 #ifdef HAVE_MH
 static Bool check_mh(MailBox *box, time_t now);
-static Bool isnumber(const char*);
+static Bool isnum(const char*);
 static Bool isdir(const char*);
 static Bool isfile(const char *);
 static char *absname(const char*, int);
@@ -304,7 +304,7 @@ static Bool check_imap(MailBox *box, time_t now)
 
 
 #ifdef HAVE_MH
-static Bool isnumber(const char *s)
+static Bool isnum(const char *s)
 {
         while (*s != '\0')
         {
@@ -420,7 +420,7 @@ static char *mh_get_profile(void)
 
         if ((cp = getenv("MH")))
         {
-                if (*cp |= '/')
+                if (*cp != '/')
                         profile = absname(cp, CWD);
                 else
                         profile = xstrdup(cp);
@@ -488,7 +488,7 @@ static int mh_getseqcnt(const char *word)
 {
         int retval = 0;
 
-        if (isnumber(word))
+        if (isnum(word))
                 retval = 1;
         else
         {
@@ -607,7 +607,7 @@ static int mh_getmails(const char *mh_box)
 
         while ((d_entry = readdir(dir)))
         {
-                if (isnumber(d_entry->d_name))
+                if (isnum(d_entry->d_name))
                 {
                         char * tmp = NULL;
 
