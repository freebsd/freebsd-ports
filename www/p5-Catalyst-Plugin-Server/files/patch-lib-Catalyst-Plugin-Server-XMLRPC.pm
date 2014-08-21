--- lib/Catalyst/Plugin/Server/XMLRPC.pm.orig
+++ lib/Catalyst/Plugin/Server/XMLRPC.pm
@@ -512,7 +512,7 @@ Alias of $c->req->parameters
 
     __PACKAGE__->mk_accessors(
         qw/ path prefix separator attribute convert_params
-            show_errors xml_encoding
+            show_errors xml_encoding allow_nil
         /
     );
 
@@ -532,6 +532,8 @@ Alias of $c->req->parameters
                                 || $DefaultShowErrors );
         $self->xml_encoding( $c->config->{xmlrpc}->{xml_encoding} )
                 if $c->config->{xmlrpc}->{xml_encoding};
+        $self->allow_nil( $c->config->{xmlrpc}->{allow_nil} )
+                if $c->config->{xmlrpc}->{allow_nil};
         $self->attribute($DefaultAttr);
         $self->convert_params( 1 );
 
@@ -690,6 +692,9 @@ Alias of $c->req->parameters
         local $RPC::XML::ENCODING = $c->server->xmlrpc->config->xml_encoding
                 if $c->server->xmlrpc->config->xml_encoding;
         
+        local $RPC::XML::ALLOW_NIL = $c->server->xmlrpc->config->allow_nil
+                if $c->server->xmlrpc->config->allow_nil;
+
         local $Clone::Fast::BREAK_REFS = 1;
 
         my $res = RPC::XML::response->new(clone($status));
@@ -808,6 +813,13 @@ default encoding to C<UTF-8> for instance.
 
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
