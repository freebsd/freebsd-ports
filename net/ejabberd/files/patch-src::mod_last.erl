--- mod_last.erl.orig
+++ mod_last.erl
@@ -102,7 +102,16 @@
 		  sub_el = [{xmlelement, "query",
 			     [{"xmlns", ?NS_LAST},
 			      {"seconds", integer_to_list(Sec)}],
-			     [{xmlcdata, Status}]}]}
+			     [{xmlcdata, Status}]}]};
+	[{last_activity, _, TimeStamp}] ->
+	    {MegaSecs, Secs, _MicroSecs} = now(),
+	    TimeStamp2 = MegaSecs * 1000000 + Secs,
+	    Sec = TimeStamp2 - TimeStamp,
+	    IQ#iq{type = result,
+		  sub_el = [{xmlelement, "query",
+			     [{"xmlns", ?NS_LAST},
+			      {"seconds", integer_to_list(Sec)}],
+			     []}]}
     end.
 
 
