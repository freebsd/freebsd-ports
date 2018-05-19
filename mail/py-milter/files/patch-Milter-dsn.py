--- Milter/dsn.py.orig	2016-12-13 19:17:34 UTC
+++ Milter/dsn.py
@@ -142,13 +142,13 @@ def send_dsn(mailfrom,receiver,msg=None,
         if badrcpts:
           return badrcpts
       return None			# success
-    except smtplib.SMTPRecipientsRefused,x:
+    except smtplib.SMTPRecipientsRefused as x:
       if len(x.recipients) == 1:
         return x.recipients.values()[0]	# permanent error
       return x.recipients
-    except smtplib.SMTPSenderRefused,x:
+    except smtplib.SMTPSenderRefused as x:
       return x.args[:2]			# does not accept DSN
-    except smtplib.SMTPDataError,x:
+    except smtplib.SMTPDataError as x:
       return x.args			# permanent error
     except smtplib.SMTPException:
       pass		# any other error, try next MX
