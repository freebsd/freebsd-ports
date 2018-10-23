--- README.md.orig	2018-10-14 19:59:57 UTC
+++ README.md
@@ -77,7 +77,7 @@ Publishing pushes data from stdin or a file to an exch
     OPTIONS:
         -c, --content-type <content_type>    Content type such as application/json. Inferred from filename if
                                              possible.
-        -e, --exchange <exchange>            Exchange to publish to [default ]
+        -e, --exchange <exchange>            Exchange to publish to [default ""]
         -f, --file <file>                    Filename (- is stdin) [default: -]
         -H, --header <header>...             Header on the form "My-Header: Value"
         -r, --routing-key <routing_key>      Routing key [default: ]
@@ -120,7 +120,7 @@ stdout or as files to a directory.
     FLAGS:
         -i, --info       Include delivery info (and headers).
     OPTIONS:
-        -e, --exchange <exchange>          Exchange to subscribe to
+        -e, --exchange <exchange>          Exchange to subscribe to [default ""]
         -o, --output <output>              Output directory (- is stdout) [default: -]
         -r, --routing-key <routing_key>    Routing key [default: #]
 
