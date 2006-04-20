--- lib/Net/Akismet.pm.old	Thu Apr 20 15:50:08 2006
+++ lib/Net/Akismet.pm	Thu Apr 20 15:50:49 2006
@@ -24,7 +24,7 @@
 			KEY => 'secret-baba-API-key',
 			URL => 'http://example.blog.net/',
 		) or die('Key verification failure!');
-	
+
 	my $verdict = $akismet->check(
 			USER_IP 		=> '10.10.10.11',
 			COMMENT_CONTENT		=> 'Run, Lola, Run, the spam will catch you!',
@@ -37,7 +37,7 @@
 
 		print "I found spam. I am a spam-founder!\n";
 	}
-		
+
 =head1 METHODS
 
 =over 8
@@ -47,7 +47,7 @@
 	Net::Akismet->new(PARAM => ...);
 
 Acceptable parameters:
-	
+
 =over 4
 
 =item  KEY
@@ -61,7 +61,7 @@
 =item  USER_AGENT
 
 If supplied the value is prepended to this module's identification string to become something like:
-	
+
 	yourkillerapp/0.042 | Akismet Perl/0.01
 
 Otherwise just Akismet Perl's user agent string will be sent.
