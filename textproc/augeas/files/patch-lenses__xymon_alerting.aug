--- lenses/xymon_alerting.aug.orig	2014-01-27 10:36:08 UTC
+++ lenses/xymon_alerting.aug
@@ -37,16 +37,16 @@
     let comparison  = store /[<>]/
 
     (* View: equal *)
-    let equal       = del /=/ "="
+    let equal       = Sep.equal
 
     (* View: ws *)
-    let ws          = del /[ \t]+?/ " "
+    let ws          = Sep.space
 
     (* View: eol *)
-    let eol         = del /\n/ "\n"
+    let eol         = Util.eol
 
     (* View: ws_or_eol *)
-    let ws_or_eol   = del /[ \t\n]+?/ " "
+    let ws_or_eol   = del /([ \t]+|[ \t]*\n[ \t]*)/ " "
 
     (* View: comment *)
     let comment = Util.comment
@@ -63,70 +63,75 @@
 
     (* View: macrodefinition
          A string that starts with $ and that is assigned something *)
-    let macrodefinition = [ key /\$[^ =\t\n#\/]+/ . equal . store /.*/ . eol ]
+    let macrodefinition = [ key /\$[^ =\t\n#\/]+/ . Sep.space_equal . store Rx.space_in . eol ]
+
 
+    (* View: flag
+         A flag value *)
+    let flag (kw:string) = Build.flag kw
+
+    (* View: kw_word
+         A key=value value *)
+    let kw_word (kw:regexp) = Build.key_value kw equal store_word
 
     (************************************************************************
      * Group:                 FILTERS 
      *************************************************************************)
 
     (* View: page
-         The page filter definition *)
-    let page      = [ ws . key "PAGE" . equal . store_word . ws ]
-    (* View: expage
-         The expage filter definition *)
-    let expage    = [ ws . key "EXPAGE" . equal . store_word . ws ]
+         The (ex)?page filter definition *)
+    let page      = kw_word /(EX)?PAGE/
+
     (* View: group
-         The group filter definition *)
-    let group     = [ ws . key "GROUP" . equal . store_word . ws ]
-    (* View: exgroup
-         The exgroup filter definition *)
-    let exgroup   = [ ws . key "EXGROUP" . equal . store_word . ws ]
+         The (ex)?group filter definition *)
+    let group     = kw_word /(EX)?GROUP/
+
     (* View: host
-         The host filter definition *)
-    let host      = [ ws . key "HOST" . equal . store_word . ws ]
-    (* View: exhost
-         The exhost filter definition *)
-    let exhost    = [ ws . key "EXHOST" . equal . store_word . ws ]
+         The (ex)?host filter definition *)
+    let host      = kw_word /(EX)?HOST/
+
     (* View: service
-         The service filter definition *)
-    let service   = [ ws . key "SERVICE" . equal . store_word . ws ]
-    (* View: exservice
-         The exservice filter definition *)
-    let exservice = [ ws . key "EXSERVICE" . equal . store_word . ws ]
+         The (ex)?service filter definition *)
+    let service   = kw_word /(EX)?SERVICE/
+
     (* View: color
          The color filter definition *)
-    let color     = [ ws . key "COLOR" . equal . store_word . ws ]
+    let color     = kw_word "COLOR"
+
     (* View: time
          The time filter definition *)
-    let time      = [ ws . key "TIME" . equal . store_word . ws ]
+    let time      = kw_word "TIME"
+
     (* View: duration
          The duration filter definition *)
-    let duration  = [ ws . key "DURATION" . [ label "operator" . comparison ] . [ label "value" . store_word ] . ws ]
+    let duration  = [ key "DURATION" . [ label "operator" . comparison ] . [ label "value" . store_word ] ]
     (* View: recover
          The recover filter definition *)
-    let recover   = [ ws . key "RECOVER" . ws ]
+    let recover   = flag "RECOVER"
     (* View: notice
          The notice filter definition *)
-    let notice    = [ ws . key "NOTICE" . ws ]
+    let notice    = flag "NOTICE"
 
-    (* View: filters
+    (* View: rule_filter
          Filters are made out of any of the above filter definitions *)
-    let filters = 
-        page |
-        expage |
-        group |
-        exgroup |
-        host |
-        exhost |
-        service |
-        exservice |
-        color |
-        time |
-        duration |
-        recover |
-        notice
+    let rule_filter = page | group | host | service
+                    | color | time | duration | recover | notice
 
+    (* View: filters
+         One or more filters *)
+    let filters = [ label "filters" . Build.opt_list rule_filter ws ]
+
+    (* View: filters_opt
+         Zero, one or more filters *)
+    let filters_opt = [ label "filters" . (ws . Build.opt_list rule_filter ws)? ]
+
+    (* View: kw_word_filters_opt
+         A <kw_word> entry with optional filters *)
+    let kw_word_filters_opt (kw:string) = [ key kw . equal . store_word . filters_opt ]
+
+    (* View: flag_filters_opt
+         A <flag> with optional filters *) 
+    let flag_filters_opt (kw:string) = [ key kw . filters_opt ]
 
     (************************************************************************
      * Group:                 RECIPIENTS
@@ -134,40 +139,43 @@
 
     (* View: mail
          The mail recipient definition *)
-    let mail      = [ key "MAIL" . ws . store_word . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let mail      = [ key "MAIL" . ws . store_word . filters_opt ]
+
     (* View: script
          The script recipient definition *)
-    let script    = [ key "SCRIPT" . ws . [ label "script" . store_word ] . ws . [ label "recipient" . store_word ] . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let script    = [ key "SCRIPT" . ws . [ label "script" . store_word ]
+                  . ws . [ label "recipient" . store_word ] . filters_opt ]
+
     (* View: ignore
          The ignore recipient definition *)
-    let ignore    = [ key "IGNORE" . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let ignore    = flag_filters_opt "IGNORE"
+
     (* View: format
          The format recipient definition *)
-    let format    = [ key "FORMAT" . equal . store_word . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let format    = kw_word_filters_opt "FORMAT"
+
     (* View: repeat
          The repeat recipient definition *)
-    let repeat    = [ key "REPEAT" . equal . store_word . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let repeat    = kw_word_filters_opt "REPEAT"
+
     (* View: unmatched
          The unmatched recipient definition *)
-    let unmatched = [ key "UNMATCHED" . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let unmatched = flag_filters_opt "UNMATCHED"
+
     (* View: stop
          The stop recipient definition *)
-    let stop      = [ key "STOP" . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let stop      = flag_filters_opt "STOP"
+
     (* View: macro
          The macro recipient definition *)
-    let macro     = [ key /\$[^ =\t\n#\/]+/ . ws . [ label "filters" . filters* ] . ws_or_eol ]
+    let macro     = [ key /\$[^ =\t\n#\/]+/ . filters_opt ]
 
-    (* View: recipients
+    (* View: recipient
          Recipients are made out of any of the above recipient definitions *)
-    let recipients =
-        mail |
-        script |
-        ignore |
-        format |
-        repeat |
-        unmatched |
-        stop |
-        macro
+    let recipient = mail | script | ignore | format | repeat | unmatched
+                  | stop | macro
+
+    let recipients = [ label "recipients" . Build.opt_list recipient ws_or_eol ]
 
 
     (************************************************************************
@@ -175,8 +183,8 @@
      *************************************************************************)
 
     (* View: rule
-         Rules are made of filters and then recipients sperarated by a whitespace *)
-    let rule = [ seq "rules" . [ label "filters" . filters+ ] . ws_or_eol . [ label "recipients" . ( recipients )+ ] . eol ] 
+         Rules are made of rule_filter and then recipients sperarated by a whitespace *)
+    let rule = [ seq "rules" . filters . ws_or_eol . recipients . eol ] 
 
     (* View: lns
          The Xymon_Alerting lens *)
