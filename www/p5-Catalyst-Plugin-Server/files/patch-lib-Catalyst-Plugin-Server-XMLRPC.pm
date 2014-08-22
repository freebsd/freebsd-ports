--- lib/Catalyst/Plugin/Server/XMLRPC.pm.orig	2010-07-08 20:39:58.000000000 +0200
+++ lib/Catalyst/Plugin/Server/XMLRPC.pm	2014-08-22 15:37:10.637508261 +0200
@@ -349,7 +349,7 @@
                                             }
                 ) {
                     $c->req->xmlrpc->_error( 
-                        $c, qq[Invalid XMLRPC request: No such method]
+                        $c, 400, qq[Invalid XMLRPC request: No such method]
                     );
                     last PREPARE;
                 }
@@ -512,7 +512,7 @@
 
     __PACKAGE__->mk_accessors(
         qw/ path prefix separator attribute convert_params
-            show_errors xml_encoding
+            show_errors xml_encoding allow_nil
         /
     );
 
@@ -532,6 +532,8 @@
                                 || $DefaultShowErrors );
         $self->xml_encoding( $c->config->{xmlrpc}->{xml_encoding} )
                 if $c->config->{xmlrpc}->{xml_encoding};
+        $self->allow_nil( $c->config->{xmlrpc}->{allow_nil} )
+                if $c->config->{xmlrpc}->{allow_nil};
         $self->attribute($DefaultAttr);
         $self->convert_params( 1 );
 
@@ -668,7 +670,7 @@
 
         ### an error in parsing the request
         } elsif ( $@ ) {
-            $self->_error( $c, qq[Invalid XMLRPC request "$@"] );
+            $self->_error( $c, 400, qq[Invalid XMLRPC request "$@"] );
             return;
 
         ### something is wrong, but who knows what...
@@ -690,6 +692,9 @@
         local $RPC::XML::ENCODING = $c->server->xmlrpc->config->xml_encoding
                 if $c->server->xmlrpc->config->xml_encoding;
         
+        local $RPC::XML::ALLOW_NIL = $c->server->xmlrpc->config->allow_nil
+                if $c->server->xmlrpc->config->allow_nil;
+
         local $Clone::Fast::BREAK_REFS = 1;
 
         my $res = RPC::XML::response->new(clone($status));
@@ -700,10 +705,11 @@
 
     ### record errors in the error and debug log -- just for convenience 
     sub _error {
-        my($self, $c, $msg) = @_;
+        my($self, $c, $code, $msg) = @_;
 
+	($code, $msg) = (500, $code) unless defined $msg;
         $c->log->debug( $msg ) if $c->debug;
-        $c->error( $msg );
+        $self->error( [ $code, $msg ] );
     }
 }
 
@@ -808,6 +814,13 @@
 
 Defaults to C<us-ascii> which is the default of C<RPC::XML>.
 
+=item allow_nil
+
+Allow undefined values to be encoded as a C<< nil >> element of an empty
+string.
+
+Defaults to false which is the default of C<RPC::XML>.
+
 =back
 
 =head1 DIAGNOSTICS
