--- lenses/syslog.aug.orig	2018-08-10 20:17:35 UTC
+++ lenses/syslog.aug
@@ -221,7 +221,7 @@ module Syslog =
 	(* View: entries
 	 entries are either comments/empty lines or entries
 	 *)
-	let entries = (empty | comment | entry)*
+	let entries = (empty | comment | entry )*
 
 	(* Group: Program matching *)
 
@@ -253,10 +253,13 @@ module Syslog =
 
 	(* Group: Top of the tree *)
 
+    let include =
+      [ key "include" . sep_tab . store file_r . eol ]
+
 	(* View: lns
 	 generic entries then programs or hostnames matching blocs
 	 *)
-        let lns = entries . ( program | hostname )*
+        let lns = entries . ( program | hostname | include )*
 
 	(* Variable: filter
 	 all you need is /etc/syslog.conf
