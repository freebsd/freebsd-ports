--- lib/HTTP/Proxy/BodyFilter/htmltext.pm~	Tue Mar 23 17:51:08 2004
+++ lib/HTTP/Proxy/BodyFilter/htmltext.pm	Tue Mar 23 17:53:30 2004
@@ -66,7 +66,7 @@
             redo SCAN if $self->{js};    # ignore protected
             {
                 local $_ = $1;
-                $self->{_filter}();
+                $self->{_filter}->();
                 substr( $$dataref, $pos, length($1), $_ );
                 pos($$dataref) = $pos + length($_);
             }
