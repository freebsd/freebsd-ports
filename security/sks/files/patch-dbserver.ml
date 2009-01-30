# HG changeset patch
# User Yaron M. Minsky <yminsky@gmail.com>
# Date 1211591563 14400
# Node ID 1957b3075022809b4742d0190e87f76ccee55a56
# Parent a032cd3cb2ee139b318bfcd9336b5e58e8cb67dc
fixed bug in handling of send_mailsyncs flag

--- dbserver.ml	Sat May 10 18:45:52 2008 -0400
+++ dbserver.ml	Fri May 23 21:12:43 2008 -0400
@@ -631,24 +631,24 @@
 	 then (Ehandlers.repeat_forever_simple checkpoint_interval checkpoint)
 	 else (Ehandlers.repeat_forever_simple sync_interval sync)) 
 	@
-	Ehandlers.repeat_forever_simple !Settings.membership_reload_time
-	 Membership.reset_membership_time
+	  Ehandlers.repeat_forever_simple !Settings.membership_reload_time
+	  Membership.reset_membership_time
 	@
-	(Ehandlers.repeat_forever 10. 
-	   (Eventloop.make_tc ~cb:transmit_keys ~timeout:0
-	      ~name:"mail transmit keys" )
-	)
+	  (if !Settings.send_mailsyncs then
+	     (Ehandlers.repeat_forever 10. 
+	        (Eventloop.make_tc ~cb:transmit_keys ~timeout:0
+	           ~name:"mail transmit keys" )
+	     )
+	   else [])
 	@
-	(if !Settings.send_mailsyncs then
-	   (Ehandlers.repeat_forever 10. 
-	      (Eventloop.make_tc ~name:"mailsync" ~timeout:0
-		 ~cb:(Mailsync.load_mailed_keys 
-			~addkey:(Keydb.add_key_merge ~newkey:false)))
-	   )
-	 else [])
+	  (Ehandlers.repeat_forever 10. 
+	     (Eventloop.make_tc ~name:"mailsync" ~timeout:0
+		~cb:(Mailsync.load_mailed_keys 
+		       ~addkey:(Keydb.add_key_merge ~newkey:false)))
+	  )
 	@
-	(Ehandlers.repeat_at_hour !Settings.stat_calc_hour
-	   calculate_stats_page)
+	  (Ehandlers.repeat_at_hour !Settings.stat_calc_hour
+	     calculate_stats_page)
       )
 
       (

