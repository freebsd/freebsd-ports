
$FreeBSD$

--- src/yaws_sup.erl.orig
+++ src/yaws_sup.erl
@@ -46,10 +46,8 @@
 
     YawsRSS = {yaws_rss, {yaws_rss, start_link, []},
 	       permanent, 5000, worker, [yaws_rss]},
-    Pam = {yaws_pam, {yaws_pam, start_link, ["system-auth", false, false]},
-	       permanent, 5000, worker, [yaws_pam]},
 
-    {ok,{{one_for_all,0,300}, [YawsLog, YawsRSS, YawsServ, Sess, Pam]}}.
+    {ok,{{one_for_all,0,300}, [YawsLog, YawsRSS, YawsServ, Sess]}}.
 
 %%----------------------------------------------------------------------
 %%----------------------------------------------------------------------
