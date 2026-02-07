--- mailgraph.pl.orig	2011-11-19 17:58:21.000000000 +0100
+++ mailgraph.pl	2011-11-19 18:01:09.000000000 +0100
@@ -632,6 +632,13 @@
 				event($time, 'rejected');
 			}
 		}
+		elsif($prog eq 'postscreen')
+		{
+			if($text =~ /NOQUEUE: reject:/)
+			{
+				event($time, 'rejected');
+			}
+		}
 	}
 	elsif($prog eq 'sendmail' or $prog eq 'sm-mta') {
 		if($text =~ /\bmailer=local\b/ ) {
@@ -853,6 +860,11 @@
 			event($time, 'virus');
 		}
 	}
+	elsif($prog eq 'clapf') {
+		if($text =~ /SPAM/) {
+			event($time, 'spam');
+		}
+	}
 }
 
 sub event($$)
