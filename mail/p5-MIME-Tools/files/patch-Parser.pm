--- lib/MIME/Parser.pm.orig	Sun Nov 12 14:55:11 2000
+++ lib/MIME/Parser.pm	Wed Nov 19 18:39:33 2003
@@ -378,16 +378,17 @@
 =item extract_nested_messages OPTION
 
 I<Instance method.>
-Some MIME messages will contain a part of type C<message/rfc822>:
+Some MIME messages will contain a part of type C<message/rfc822>
+or C<message/partial> or C<message/external-body>:
 literally, the text of an embedded mail/news/whatever message.  
 This option controls whether (and how) we parse that embedded message.
 
 If the OPTION is false, we treat such a message just as if it were a 
 C<text/plain> document, without attempting to decode its contents.  
 
-If the OPTION is true (the default), the body of the C<message/rfc822> 
-part is parsed by this parser, creating an entity object.  
-What happens then is determined by the actual OPTION:
+If the OPTION is true (the default), the body of the C<message/rfc822>
+or C<message/partial> part is parsed by this parser, creating an
+entity object.  What happens then is determined by the actual OPTION:
 
 =over 4
 
@@ -592,6 +593,7 @@
 #
 # I<Instance method.>
 # Process and return the next header.
+# Return undef if, instead of a header, the encapsulation boundary is found.
 # Fatal exception on failure.
 #
 sub process_header {
@@ -612,6 +614,10 @@
     foreach (@headlines) { s/[\r\n]+\Z/\n/ }  ### fold
 
     ### How did we do?
+    if ($hdr_rdr->eos_type eq 'DELIM') {
+       $self->whine("bogus part, without CRLF before body");
+       return;
+    }
     ($hdr_rdr->eos_type eq 'DONE') or
 	$self->error("unexpected end of header\n");
 
@@ -983,7 +989,17 @@
 
     ### Parse and add the header:
     my $head = $self->process_header($in, $rdr);
-    $ent->head($head);   
+    if (not defined $head) {
+       $self->debug("bogus empty part");
+       $head = $self->interface('HEAD_CLASS')->new;
+       $head->mime_type('text/plain; charset=US-ASCII');
+       $ent->head($head);
+       $ent->bodyhandle($self->new_body_for($head));
+       $ent->bodyhandle->open("w")->close;
+       $self->results->level(-1);
+       return $ent;
+    }
+    $ent->head($head);
 
     ### Tweak the content-type based on context from our parent...
     ### For example, multipart/digest messages default to type message/rfc822:
@@ -997,8 +1013,10 @@
     if ($type eq 'multipart') {
 	$self->process_multipart($in, $rdr, $ent);
     }
-    elsif (("$type/$subtype" eq "message/rfc822") && 
-	   $self->extract_nested_messages) {
+    elsif (("$type/$subtype" eq "message/rfc822" ||
+            "$type/$subtype" eq "message/external-body" ||
+	    ("$type/$subtype" eq "message/partial" && $head->mime_attr("content-type.number") == 1)) && 
+	    $self->extract_nested_messages) {
 	$self->debug("attempting to process a nested message");
 	$self->process_message($in, $rdr, $ent);
     }
