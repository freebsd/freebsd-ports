Sendmail 8.12.x
 
The MTA may erroneously detect a communication failure with libmilter
(EINTR in select(2)). [ http://www.sendmail.org/~ca/email/sm-812.html ]

Index: milter.c
===================================================================
RCS file: /cvs/sendmail/milter.c,v
retrieving revision 8.187
retrieving revision 8.188
diff -u -r8.187 -r8.188
--- sendmail/milter.c	2002/01/19 00:48:57	8.187
+++ sendmail/milter.c	2002/01/21 04:07:02	8.188
@@ -139,14 +139,17 @@
 		return NULL; \
 	} \
  \
-	FD_ZERO(&fds); \
-	SM_FD_SET(m->mf_sock, &fds); \
-	tv.tv_sec = (secs); \
-	tv.tv_usec = 0; \
-	ret = select(m->mf_sock + 1, \
-		     (write) ? NULL : &fds, \
-		     (write) ? &fds : NULL, \
-		     NULL, &tv); \
+	do \
+	{ \
+		FD_ZERO(&fds); \
+		SM_FD_SET(m->mf_sock, &fds); \
+		tv.tv_sec = (secs); \
+		tv.tv_usec = 0; \
+		ret = select(m->mf_sock + 1, \
+			     (write) ? NULL : &fds, \
+			     (write) ? &fds : NULL, \
+			     NULL, &tv); \
+	} while (ret < 0 && errno == EINTR); \
  \
 	switch (ret) \
 	{ \
