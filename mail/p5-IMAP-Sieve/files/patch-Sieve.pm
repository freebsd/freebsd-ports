--- Sieve.pm.orig	Sat Jun 23 22:42:48 2001
+++ Sieve.pm	Thu Apr 24 18:10:29 2003
@@ -93,7 +93,7 @@
 							 Proto => 'tcp',
 							 Reuse => 1); })
     	{
-		$self->_error("initialize", "could'nt establish a Sieve connection to",$self->{'Server'});				
+		$self->_error("initialize", "couldn't establish a Sieve connection to",$self->{'Server'});				
 		return;
     	}
     } # if SSL
@@ -110,6 +110,7 @@
     if (/\r$/) {
 	chop;
     }
+    my $starttls = 0;
     if (/IMPLEMENTATION/) {
 	$self->{'Implementation'}=$1 if /^"IMPLEMENTATION" +"(.*)"/;
     	#version 2 of cyrus imap/timsieved
@@ -119,6 +120,7 @@
         while (!/^OK/) {
 	   $self->{'Capability'}=$1 if /^"SASL" +"(.*)"/;
 	   $self->{'Sieve'}=$1 if /^"SIEVE" +"(.*)"/;
+	   $starttls=1 if /"STARTTLS"/;
 	   $_ = $self->_read;
 ##	   $_=$self->_read;
 	}
@@ -126,6 +128,55 @@
     else {
 	$self->{'Capability'}=$_;
     }
+    if (!defined($self->{'SSL'}) && $starttls) {
+	my $cwd= cwd;
+	my %ssl_defaults = (
+			  'SSL_use_cert' => 0,
+			  'SSL_verify_mode' => 0x00,
+			  'SSL_key_file' => $cwd."/certs/client-key.pem",
+			  'SSL_cert_file' => $cwd."/certs/client-cert.pem",
+			  'SSL_ca_path' => $cwd."/certs",
+			  'SSL_ca_file' => $cwd."/certs/ca-cert.pem",
+			  'SSL_version' => 'tlsv1'
+			  );
+	my @ssl_options;
+	my $ssl_key;
+	my $key;
+	foreach $ssl_key (keys(%ssl_defaults)) {
+		if (!defined($self->{$ssl_key})) {
+			$self->{$ssl_key} = $ssl_defaults{$ssl_key};
+		}
+	}
+	foreach $ssl_key (keys(%{$self})) {
+		if ($ssl_key =~ /^SSL_/) {
+			push @ssl_options, $ssl_key,$self->{$ssl_key};
+		}
+	}
+        my $SSL_try="use IO::Socket::SSL";
+	eval $SSL_try;
+#	$IO::Socket::SSL::DEBUG = 4;
+	if ($self->{'Socket'}->isa('IO::Socket::SSL')) {
+	    $self->_error("starttls", "TLS already started");
+	    $self->close;
+	    return;
+	}
+	print $fh "STARTTLS\r\n";
+	$_ = $self->_read;
+	if (/OK/) {
+
+	    #IO::Socket::SSL::context_init({@ssl_options});
+	    if (!IO::Socket::SSL::socket_to_SSL($self->{'Socket'}, {@ssl_options}))
+    		{
+			$self->_error("starttls", "couldn't secure connection to",$self->{'Server'});
+	    		$self->close;
+			return;
+    		}
+	} else {
+	    $self->close;
+	    $self->_error("starttls", "Unknown error",$_);
+	    return;
+	}
+    }
     $userpass = "$self->{'Proxy'}\x00".$self->{'Login'}."\x00".$self->{'Password'};
     $encode=encode_base64($userpass);
     $len=length($encode);
@@ -196,7 +247,7 @@
 			}
 		}
 		else {
-			if (($char eq "\n") or ($char eq "\r")) {
+			if ($char eq "\n") {
 				if (length($buffer) ==0) {
 					# remove any cr or nl leftover
 				}
@@ -204,7 +255,7 @@
 					return $buffer;
 				}
 			}
-			else {
+			elsif ($char ne "\r") {
 				$buffer.=$char;
 			}
 		}
