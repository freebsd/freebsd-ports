--- DotDotPwn/HTTP.pm.orig	2016-05-05 08:37:25 UTC
+++ DotDotPwn/HTTP.pm
@@ -21,7 +21,7 @@ sub FuzzHTTP{
 	my $foo = 0; # Used as an auxiliary variable in quiet mode (see below)
 	my $UserAgent;
 
-	open(AGENTS, "DotDotPwn/User-Agents.txt") or die "[-] Cannot open User-Agents.txt file: $!";
+	open(AGENTS, "/usr/local/share/dotdotpwn/User-Agents.txt") or die "[-] Cannot open User-Agents.txt file: $!";
 	my @UserAgents = <AGENTS>;
 	close(AGENTS);
 
