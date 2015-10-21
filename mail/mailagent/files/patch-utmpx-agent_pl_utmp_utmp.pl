--- ./agent/pl/utmp/utmp.pl.orig	2014-08-14 01:59:33.506704776 +0900
+++ ./agent/pl/utmp/utmp.pl	2014-08-14 01:59:33.506704776 +0900
@@ -0,0 +1,22 @@
+#
+# utmp file primitives
+#
+
+package utmp;
+
+# Return the ttys on which a given user is logged
+sub ttys {
+	local($user) = @_;			# User's login name
+	local(@u);
+	open(WHO, '/usr/bin/who |') || warn "Can't invoke /usr/bin/who: $!\n";
+	while (<WHO>) {
+	    next unless /^$user\s/;
+	    my ($name, $line, $dummy) = split;
+	    push(@u, $line);
+	}
+	close WHO;     
+	return @u;		# Returns array of ttys
+}
+
+package main;
+
