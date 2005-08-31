--- ParseFormData.pm.orig	Fri Jul 29 00:00:48 2005
+++ ParseFormData.pm	Fri Jul 29 00:01:41 2005
@@ -11,9 +11,9 @@
 package Apache::ParseFormData;
 
 use strict;
-use Apache::Log;
-use Apache::Const -compile => qw(OK M_POST M_GET FORBIDDEN HTTP_REQUEST_ENTITY_TOO_LARGE);
-use Apache::RequestIO ();
+use Apache2::Log;
+use Apache2::Const -compile => qw(OK M_POST M_GET FORBIDDEN HTTP_REQUEST_ENTITY_TOO_LARGE);
+use Apache2::RequestIO ();
 use APR::Table;
 use IO::File;
 use POSIX qw(tmpnam);
@@ -44,12 +44,12 @@
 	if(my $data = $self->headers_in->get('cookie')) {
 		&_parse_query($self, $data, " *; *");
 	}
-	if($self->method_number == Apache::M_POST) {
+	if($self->method_number == Apache2::Const::M_POST) {
 		$self->pnotes('apr_req_result' => &parse_content($self, \%args));
-	} elsif($self->method_number == Apache::M_GET) {
+	} elsif($self->method_number == Apache2::Const::M_GET) {
 		my $data = $self->args();
 		&_parse_query($self, $data) if($data);
-		$self->pnotes('apr_req_result' => Apache::OK);
+		$self->pnotes('apr_req_result' => Apache2::Const::OK);
 	}
 	return($self);
 }
@@ -139,7 +139,7 @@
 		my $error_str = "[Apache::ParseFormData] file upload forbidden";
 		$r->notes->set("error-notes" => $error_str);
 		$r->log_error($error_str);
-		return(Apache::FORBIDDEN);
+		return(Apache2::Const::FORBIDDEN);
 	}
 	my $rm = $r->remaining;
 	if($args->{'post_max'} && ($rm > $args->{'post_max'})) {
@@ -147,7 +147,7 @@
 		my $error_str = "[Apache::ParseFormData] entity too large ($rm, max=$pm)";
 		$r->notes->set("error-notes" => $error_str);
 		$r->log_error($error_str);
-		return(Apache::HTTP_REQUEST_ENTITY_TOO_LARGE);
+		return(Apache2::Const::HTTP_REQUEST_ENTITY_TOO_LARGE);
 	}
 	if($ct =~ /^multipart\/form-data; boundary=(.+)$/) {
 		my $boundary = $1;
@@ -196,7 +196,7 @@
 		$r->get_client_block($buf, $len);
 		&_parse_query($r, $buf) if($buf);
 	}
-	return(Apache::OK);
+	return(Apache2::Const::OK);
 }
 
 sub extract_headers {
