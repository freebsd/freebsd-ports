--- jabberd/mio_xml.c.orig	Tue Jul  6 19:06:24 2004
+++ jabberd/mio_xml.c	Tue Jul  6 19:07:34 2004
@@ -142,14 +142,13 @@
         nul += 4;
         bufsz = bufsz - (nul - buf);
         buf = nul;
-        mio_write(m,NULL,"HTTP/1.0 200 Ok
-Server: jabber/xmlstream-hack-0.1
-Expires: Fri, 10 Oct 1997 10:10:10 GMT
-Pragma: no-cache
-Cache-control: private
-Connection: close
-
-",-1);
+        mio_write(m,NULL,"HTTP/1.0 200 Ok\n" \
+"Server: jabber/xmlstream-hack-0.1\n" \
+"Expires: Fri, 10 Oct 1997 10:10:10 GMT\n" \
+"Pragma: no-cache\n" \
+"Cache-control: private\n" \
+"Connection: close\n" \
+"\n", -1);
         m->type = type_NORMAL;
     }
 
