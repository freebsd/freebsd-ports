--- lib/HTTP/Proxy.pm~	Wed Mar  3 01:15:02 2004
+++ lib/HTTP/Proxy.pm	Tue Mar 23 17:54:31 2004
@@ -760,7 +760,7 @@
             # proxy the data
             $self->log( CONNECT, "($$) CONNECT:",
                                  "$read bytes received from $from" );
-            $peer->syswrite($data);
+            $peer->syswrite($data, length($data));
         }
     }
     $self->log( CONNECT, "($$) CONNECT:", "End of CONNECT proxyfication");
