--- cf/m4/proto.m4	4 Dec 2002 00:12:18 -0000	8.649.2.13
+++ cf/m4/proto.m4	30 Dec 2002 15:44:56 -0000
@@ -205,13 +205,13 @@
 KCERTSubject regex _CERT_REGEX_SUBJECT_', `dnl')
 
 ifdef(`LOCAL_RELAY', `dnl
-# who I send unqualified names to if FEATURE(stickyhost) is used
+# who I send unqualified names to if `FEATURE(stickyhost)' is used
 # (null means deliver locally)
 DR`'LOCAL_RELAY')
 
 ifdef(`MAIL_HUB', `dnl
 # who gets all local email traffic
-# ($R has precedence for unqualified names if FEATURE(stickyhost) is used)
+# ($R has precedence for unqualified names if `FEATURE(stickyhost)' is used)
 DH`'MAIL_HUB')
 
 # dequoting map
