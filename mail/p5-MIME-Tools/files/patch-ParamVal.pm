--- lib/MIME/Field/ParamVal.pm.orig	Sun Nov  5 04:54:49 2000
+++ lib/MIME/Field/ParamVal.pm	Thu Jun  6 10:15:15 2002
@@ -100,6 +100,9 @@
 #      token      =  1*<any  (ASCII) CHAR except SPACE, CTLs, or tspecials>
 #
 my $TSPECIAL = '()<>@,;:\</[]?="';
+
+#" Fix emacs highlighting...
+
 my $TOKEN    = '[^ \x00-\x1f\x80-\xff' . "\Q$TSPECIAL\E" . ']+';
 
 # Encoded token:
@@ -108,6 +111,9 @@
 # Pattern to match spaces or comments:
 my $SPCZ     = '(?:\s|\([^\)]*\))*';
 
+# Pattern to match non-semicolon as fallback for broken MIME
+# produced by some viruses
+my $BADTOKEN = '[^;]+';
 
 #------------------------------
 #
@@ -181,10 +187,40 @@
 
 =cut
 
+sub rfc2231decode {
+    my($val) = @_;
+    my($enc, $lang, $rest);
+
+    if ($val =~ m/^([^\']*)\'([^\']*)\'(.*)$/) {
+	# SHOULD REALLY DO SOMETHING MORE INTELLIGENT WITH ENCODING!!!
+	$enc = $1;
+	$lang = $2;
+	$rest = $3;
+	$rest = rfc2231percent($rest);
+    } elsif ($val =~ m/^([^\']*)\'([^\']*)$/) {
+	$enc = $1;
+	$rest = $2;
+	$rest = rfc2231percent($rest);
+    } else {
+	$rest = rfc2231percent($val);
+    }
+    return $rest;
+}
+
+sub rfc2231percent {
+    # Do percent-subsitution
+    my($str) = @_;
+    $str =~ s/%([0-9a-fA-F]{2})/pack("c", hex($1))/ge;
+    return $str;
+}
+
 sub parse_params {
     my ($self, $raw) = @_;
     my %params = ();
+    my %rfc2231params = ();
     my $param;
+    my $val;
+    my $part;
 
     # Get raw field, and unfold it:
     defined($raw) or $raw = '';
@@ -200,9 +236,47 @@
 	$raw =~ m/\G$SPCZ\;$SPCZ/og or last;             # skip leading separator
 	$raw =~ m/\G($PARAMNAME)\s*=\s*/og or last;      # give up if not a param
 	$param = lc($1);
-	$raw =~ m/\G(\"([^\"]+)\")|\G($TOKEN)|\G($ENCTOKEN)/g or last;   # give up if no value
-	my ($qstr, $str, $token, $enctoken) = ($1, $2, $3, $4);
-	$params{$param} = defined($qstr) ? $str : (defined($token) ? $token : $enctoken);
+	$raw =~ m/\G(\"([^\"]+)\")|\G($ENCTOKEN)|\G($BADTOKEN)|\G($TOKEN)/g or last;   # give up if no value"
+	my ($qstr, $str, $enctoken, $badtoken, $token) = ($1, $2, $3, $4, $5);
+	if (defined($badtoken)) {
+	    # Strip leading/trailing whitespace from badtoken
+	    $badtoken =~ s/^\s*//;
+	    $badtoken =~ s/\s*$//;
+	}
+	$val = defined($qstr) ? $str :
+	    (defined($enctoken) ? $enctoken :
+	     (defined($badtoken) ? $badtoken : $token));
+
+	# Do RFC 2231 processing
+	if ($param =~ /\*/) {
+	    my($name, $num);
+	    # Pick out the parts of the parameter
+	    if ($param =~ m/^([^*]+)\*([^*]+)\*?$/) {
+		# We have param*number* or param*number
+		$name = $1;
+		$num = $2;
+	    } else {
+		# Fake a part of zero... not sure how to handle this properly
+		$param =~ s/\*//g;
+		$name = $param;
+		$num = 0;
+	    }
+	    # Decode the value unless it was a quoted string
+	    if (!defined($qstr)) {
+		$val = rfc2231decode($val);
+	    }
+	    $rfc2231params{$name}{$num} .= $val;
+	} else {
+	    # Make a fake "part zero" for non-RFC2231 params
+	    $rfc2231params{$param}{"0"} = $val;
+	}
+    }
+
+    # Extract reconstructed parameters
+    foreach $param (keys %rfc2231params) {
+	foreach $part (sort { $a <=> $b } keys %{$rfc2231params{$param}}) {
+	    $params{$param} .= $rfc2231params{$param}{$part};
+	}
 	debug "   field param <$param> = <$params{$param}>";
     }
 
