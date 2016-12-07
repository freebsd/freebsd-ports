--- DotDotPwn/HTTP_Url.pm.orig	2016-05-05 08:38:21 UTC
+++ DotDotPwn/HTTP_Url.pm
@@ -29,7 +29,7 @@ sub FuzzHTTP_Url{
 	my $foo = 0; # Used as an auxiliary variable in quiet mode (see below)
 	my $UserAgent;
 
-	open(AGENTS, "DotDotPwn/User-Agents.txt") or die "[-] Cannot open User-Agents.txt file: $!";
+	open(AGENTS, "/usr/local/share/dotdotpwn/User-Agents.txt") or die "[-] Cannot open User-Agents.txt file: $!";
 	my @UserAgents = <AGENTS>;
 	close(AGENTS);
 
