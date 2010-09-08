--- ./mastertickets/model.py.orig	2010-07-11 23:51:58.000000000 -0400
+++ ./mastertickets/model.py	2010-09-08 18:41:35.000000000 -0400
@@ -107,7 +107,7 @@
             for tkt in arr:
                 if isinstance(tkt, Ticket):
                     tkt = tkt.id
-                arr2.append(tkt)
+                arr2.append(str(tkt))
             return '[%s]'%','.join(arr2)
             
         return '<mastertickets.model.TicketLinks #%s blocking=%s blocked_by=%s>'% \
