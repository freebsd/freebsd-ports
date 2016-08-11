--- tracsubtickets/api.py.orig	2012-10-27 18:40:31 UTC
+++ tracsubtickets/api.py
@@ -153,7 +153,7 @@ class SubTicketsSystem(Component):
                            (parent, ticket.id))
             # add a comment to old parent
             xticket = Ticket(self.env, parent)
-            xticket.save_changes(author, _('Remove a subticket #%s.') % ticket.id)
+            xticket.save_changes(author, _('Remove a subticket #%s. (%s)') % (ticket.id, ticket['summary']))
             tn = TicketNotifyEmail(self.env)
             tn.notify(xticket, newticket=False, modtime=xticket['changetime'])
 
@@ -164,7 +164,7 @@ class SubTicketsSystem(Component):
                            (parent, ticket.id))
             # add a comment to new parent
             xticket = Ticket(self.env, parent)
-            xticket.save_changes(author, _('Add a subticket #%s.') % ticket.id)
+            xticket.save_changes(author, _('Add a subticket #%s. (%s)') % (ticket.id, ticket['summary']))
             tn = TicketNotifyEmail(self.env)
             tn.notify(xticket, newticket=False, modtime=xticket['changetime'])
 
