--- Build.PL.orig	Mon Jan 23 13:59:39 2006
+++ Build.PL	Mon Jan 23 13:59:52 2006
@@ -271,7 +271,7 @@
 	  'po4a-translate', 'po4a-normalize', 'po4a', 'msguntypot'],
       add_to_cleanup => ['t/tmp','messages.mo', 'blib', 'html',
 	  'po/pod/po4a-pod.pot~', 'po4a.log'],
-      install_path => {po => $base.'/locale', man => $base.'/man'},
+      install_path => {po => $base.'/share/locale', man => $base.'/man'},
       dist_abstract => 'Tools for helping translation of documentation',
       dist_author => ['Martin Quinson (mquinson#debian.org)',
 	  'Denis Barbier <barbier@linuxfr.org>']
