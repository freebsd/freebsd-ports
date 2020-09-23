--- src/scan.c.orig	2003-04-06 21:01:49 UTC
+++ src/scan.c
@@ -59,7 +59,7 @@
 #include "mh.h"
 #include "maildir.h"
 #include "wrap.h"
-#include "md5.h"
+#include <openssl/md5.h>
 #ifdef HAVE_FTS_OPEN
 # include <sys/stat.h>
 # include <fts.h>
@@ -73,7 +73,10 @@
 #include <dmalloc.h>
 #endif /* HAVE_LIBDMALLOC */
 
-void scan_mailbox (char path[])
+static int md5_check_message (const char *body, size_t bbytes);
+
+void
+scan_mailbox (const char path[])
      /* {{{  */
 {
   static FILE *outf;
@@ -95,7 +98,6 @@ void scan_mailbox (char path[])
   int isdup = 0;
   time_t tt;
   struct tm *ct;
-  extern checksum_t *cs;
 
   extern option_t config;
 
@@ -144,12 +146,12 @@ void scan_mailbox (char path[])
 
       if ((config.format == MBOX) || (config.format == ZMBOX) ||
 	  (config.format == BZ2MBOX))
-	msg = (message_t *) mbox_read_message (mbox);
+	msg = mbox_read_message (mbox);
       else if ((config.format == MH) || (config.format == NNMH) ||
 	       (config.format == NNML))
-	msg = (message_t *) mh_read_message (boxd);
+	msg = mh_read_message (boxd);
       else if (config.format == MAILDIR)
-	msg = (message_t *) maildir_read_message (maildird);
+	msg = maildir_read_message (maildird);
 
       if (msg == NULL) break;
 
@@ -178,7 +180,7 @@ void scan_mailbox (char path[])
 	}
 
       if (config.dedup)
-	isdup = md5_check_message (msg->body, cs);
+	isdup = md5_check_message (msg->body, msg->bbytes);
 
       if (((res1 == 0) | (res2 == 0)) ^ ((config.invert ^ delete)) &&
 	  ((config.dedup && !isdup) || !config.dedup))
@@ -281,7 +283,8 @@ void scan_mailbox (char path[])
 }
 /* }}} */
 
-void recursive_scan (char path[])
+void
+recursive_scan (const char path[])
      /* {{{  */
 
 {
@@ -312,37 +315,41 @@ void recursive_scan (char path[])
     fts_close (ftsfoo);
   }
 #else
-  ftw (path, (void *) scan_mailbox, 1);
+  ftw (path, (int (*)(const char *, const struct *, int))scan_mailbox, 1);
 #endif /* HAVE_FTS_OPEN */
 }
 
 /* }}} */
 
-int md5_check_message (char *body, checksum_t *chksum)
+static int
+md5_check_message (const char *body, size_t bbytes)
      /* {{{  */
 {
-  struct md5_ctx a;
-  unsigned char b[16];
+  MD5_CTX a;
+  md5_t b;
   int i;
+  extern checksum_t *cs;
 
-  md5_init_ctx (&a);
+  MD5_Init(&a);
   if (body == NULL)
-    md5_process_bytes ("", 0, &a);
+    MD5_Update(&a, "", 0);
   else
-    md5_process_bytes (body, strlen(body), &a);
-  md5_finish_ctx(&a, b);
+    MD5_Update(&a, body, bbytes);
+  MD5_Final(b.bytes, &a);
 
-  for (i = 0; i < chksum->n; i++)
+  for (i = 0; i < cs->n; i++)
     {
-      if (0 == strncmp (chksum->md5[i], b, 16)) 
+      if (b.halves[0] == cs->md5s[i].halves[0] &&
+	b.halves[1] == cs->md5s[i].halves[1])
 	return 1; 
     }
 
-  chksum->md5 = 
-	(char **) xrealloc (chksum->md5, (1 + chksum->n) * sizeof (char *));
-  chksum->md5[chksum->n] = xstrdup (b);
+  cs = 
+	xrealloc (cs, sizeof(checksum_t) + (i + 1) * sizeof (md5_t));
+  cs->md5s[i].halves[0] = b.halves[0];
+  cs->md5s[i].halves[1] = b.halves[1];
 
-  (chksum->n)++;
+  cs->n++;
 
   return 0;
 }
