--- tracsubtickets/api.py.orig	2013-03-28 05:19:20.898573000 +0800
+++ tracsubtickets/api.py	2013-03-28 05:19:46.107341000 +0800
@@ -153,7 +153,7 @@
                            (parent, ticket.id))
             # add a comment to old parent
             xticket = Ticket(self.env, parent)
-            xticket.save_changes(author, _('Remove a subticket #%s.') % ticket.id)
+            xticket.save_changes(author, _('Remove a subticket #%s. (%s)') % (ticket.id, ticket['summary']))
             tn = TicketNotifyEmail(self.env)
             tn.notify(xticket, newticket=False, modtime=xticket['changetime'])
 
@@ -164,7 +164,7 @@
                            (parent, ticket.id))
             # add a comment to new parent
             xticket = Ticket(self.env, parent)
-            xticket.save_changes(author, _('Add a subticket #%s.') % ticket.id)
+            xticket.save_changes(author, _('Add a subticket #%s. (%s)') % (ticket.id, ticket['summary']))
             tn = TicketNotifyEmail(self.env)
             tn.notify(xticket, newticket=False, modtime=xticket['changetime'])
 
