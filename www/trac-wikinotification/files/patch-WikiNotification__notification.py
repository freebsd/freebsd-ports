--- WikiNotification/notification.py.orig	2008-03-14 09:02:03 UTC
+++ WikiNotification/notification.py
@@ -14,14 +14,13 @@
 # =============================================================================
 
 import re
-import md5
 
 from trac import __version__
 from trac.core import *
 from trac.util.text import CRLF
 from trac.wiki.model import WikiPage
 from trac.versioncontrol.diff import unified_diff
-from trac.notification import NotifyEmail
+from trac.notification import NotifyEmail, NotificationSystem
 from trac.config import Option, BoolOption, ListOption, IntOption
 
 from genshi.template.text import TextTemplate
@@ -33,6 +32,7 @@ diff_header = """Index: %(name)s
 +++ %(name)s (version: %(version)s)
 """
 
+
 class WikiNotificationSystem(Component):
     smtp_from = Option(
         'wiki-notification', 'smtp_from', 'trac+wiki@localhost',
@@ -131,7 +131,7 @@ class WikiNotifyEmail(NotifyEmail):
         if page.version > 0 and action == 'modified':
             diff = diff_header % {'name': self.page.name,
                                   'version': self.page.version,
-                                  'oldversion': self.page.version -1
+                                  'oldversion': self.page.version -1,
                                  }
             oldpage = WikiPage(self.env, page.name, page.version - 1)
             self.data["oldversion"]= oldpage.version
@@ -183,8 +183,8 @@ class WikiNotifyEmail(NotifyEmail):
         public_cc = self.config.getbool('wiki-notification', 'use_public_cc')
         headers = {}
         headers['X-Mailer'] = 'Trac %s, by Edgewall Software' % __version__
-        headers['X-Trac-Version'] =  __version__
-        headers['X-Trac-Project'] =  projname
+        headers['X-Trac-Version'] = __version__
+        headers['X-Trac-Project'] = projname
         headers['X-URL'] = self.config.get('project', 'url')
         headers['Precedence'] = 'bulk'
         headers['Auto-Submitted'] = 'auto-generated'
@@ -284,18 +284,16 @@ class WikiNotifyEmail(NotifyEmail):
             del msg['Content-Transfer-Encoding']
             msg.set_charset(self._charset)
 
-        self.add_headers(msg, headers);
-        self.add_headers(msg, mime_headers);
-        self.env.log.info("Sending SMTP notification to %s:%d to %s"
-                           % (self.smtp_server, self.smtp_port, recipients))
+        self.add_headers(msg, headers)
+        self.add_headers(msg, mime_headers)
+        self.env.log.info("Sending SMTP notification to %s"
+                           % str(recipients))
         msgtext = msg.as_string()
         # Ensure the message complies with RFC2822: use CRLF line endings
         recrlf = re.compile("\r?\n")
         msgtext = CRLF.join(recrlf.split(msgtext))
-        try:
-            self.server.sendmail(msg['From'], recipients, msgtext)
-        except Exception, err:
-            self.env.log.debug('Notification could not be sent: %r', err)
+        NotificationSystem(self.env).send_email(self.from_email, recipients,
+                                                msgtext)
 
     def format_subject(self, action):
         template = self.config.get('wiki-notification', 'subject_template')
@@ -308,6 +306,6 @@ class WikiNotifyEmail(NotifyEmail):
         data = {
             'page': self.page,
             'prefix': prefix,
-            'action': action
+            'action': action,
         }
         return template.generate(**data).render('text', encoding=None).strip()
