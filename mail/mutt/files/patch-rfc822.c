diff -u -r2.9.2.1 rfc822.c
--- rfc822.c	2000/06/22 10:54:58	2.9.2.1
+++ rfc822.c	2002/01/01 10:24:05
@@ -33,6 +33,12 @@
 #include "rfc822.h"
 #endif
 
+#define terminate_string(a, b, c) do { if ((b) < (c)) a[(b)] = 0; else \
+	a[(c)] = 0; } while (0)
+
+#define terminate_buffer(a, b) terminate_string(a, b, sizeof (a) - 1)
+
+
 const char RFC822Specials[] = "@.,:;<>[]\\\"()";
 #define is_special(x) strchr(RFC822Specials,x)
 
@@ -227,12 +233,12 @@
       return NULL;
   }
 
-  token[*tokenlen] = 0;
+  terminate_string (token, *tokenlen, tokenmax);
   addr->mailbox = safe_strdup (token);
 
   if (*commentlen && !addr->personal)
   {
-    comment[*commentlen] = 0;
+    terminate_string (comment, *commentlen, commentmax);
     addr->personal = safe_strdup (comment);
   }
 
@@ -320,9 +326,6 @@
   *last = cur;
 }
 
-#define terminate_string(a, b) do { if (b < sizeof(a) - 1) a[b] = 0; else \
-	a[sizeof(a) - 1] = 0; } while (0)
-
 ADDRESS *rfc822_parse_adrlist (ADDRESS *top, const char *s)
 {
   const char *begin, *ps;
@@ -344,12 +347,12 @@
     {
       if (phraselen)
       {
-	terminate_string (phrase, phraselen);
+	terminate_buffer (phrase, phraselen);
 	add_addrspec (&top, &last, phrase, comment, &commentlen, sizeof (comment) - 1);
       }
       else if (commentlen && last && !last->personal)
       {
-	terminate_string (comment, commentlen);
+	terminate_buffer (comment, commentlen);
 	last->personal = safe_strdup (comment);
       }
 
@@ -377,7 +380,7 @@
     else if (*s == ':')
     {
       cur = rfc822_new_address ();
-      terminate_string (phrase, phraselen);
+      terminate_buffer (phrase, phraselen);
       cur->mailbox = safe_strdup (phrase);
       cur->group = 1;
 
@@ -401,12 +404,12 @@
     {
       if (phraselen)
       {
-	terminate_string (phrase, phraselen);
+	terminate_buffer (phrase, phraselen);
 	add_addrspec (&top, &last, phrase, comment, &commentlen, sizeof (comment) - 1);
       }
       else if (commentlen && last && !last->personal)
       {
-	terminate_string (phrase, phraselen);
+	terminate_buffer (phrase, phraselen);
 	last->personal = safe_strdup (comment);
       }
 #ifdef EXACT_ADDRESS
@@ -430,7 +433,7 @@
     }
     else if (*s == '<')
     {
-      terminate_string (phrase, phraselen);
+      terminate_buffer (phrase, phraselen);
       cur = rfc822_new_address ();
       if (phraselen)
       {
@@ -459,7 +462,7 @@
     }
     else
     {
-      if (phraselen && phraselen < sizeof (phrase) - 1)
+      if (phraselen && phraselen < sizeof (phrase) - 1 && *s != '.')
 	phrase[phraselen++] = ' ';
       if ((ps = next_token (s, phrase, &phraselen, sizeof (phrase) - 1)) == NULL)
       {
@@ -473,13 +476,13 @@
   
   if (phraselen)
   {
-    terminate_string (phrase, phraselen);
-    terminate_string (comment, commentlen);
+    terminate_buffer (phrase, phraselen);
+    terminate_buffer (comment, commentlen);
     add_addrspec (&top, &last, phrase, comment, &commentlen, sizeof (comment) - 1);
   }
   else if (commentlen && last && !last->personal)
   {
-    terminate_string (comment, commentlen);
+    terminate_buffer (comment, commentlen);
     last->personal = safe_strdup (comment);
   }
 #ifdef EXACT_ADDRESS
@@ -498,7 +501,7 @@
     if (!addr->group && addr->mailbox && strchr (addr->mailbox, '@') == NULL)
     {
       p = safe_malloc (mutt_strlen (addr->mailbox) + mutt_strlen (host) + 2);
-      sprintf (p, "%s@%s", addr->mailbox, host);
+      sprintf (p, "%s@%s", addr->mailbox, host);	/* __SPRINTF_CHECKED__ */
       safe_free ((void **) &addr->mailbox);
       addr->mailbox = p;
     }
