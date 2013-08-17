--- tracduplicates/web_ui.py.orig	2010-09-26 10:42:18.000000000 +0800
+++ tracduplicates/web_ui.py	2013-08-15 01:23:26.793491000 +0800
@@ -12,7 +12,7 @@
     ticket._proxy_old_save = ticket.save_changes
     ticket.save_changes = self.save_changes
   
-  def save_changes(self, author, comment, when=0, db=None, cnum=''):
+  def save_changes(self, author, comment, when=0, db=None, cnum='', replyto=None):
     dupeticket = Ticket(self._ticket.env, self._dupe_id, db=db)
     dupeticket.save_changes(
       author,
@@ -25,7 +25,7 @@
     else:
       comment += "\n\n"
     comment += "*** Marked duplicate of #%d ***" % self._dupe_id
-    return self._ticket._proxy_old_save(author, comment, when=when, db=db, cnum=cnum)
+    return self._ticket._proxy_old_save(author, comment, when=when, db=db, cnum=cnum, replyto=replyto)
 
 class DuplicatesWorkflow(Component):
   implements(ITicketActionController)
