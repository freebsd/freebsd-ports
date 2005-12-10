Index: socket.c
===================================================================
--- socket.c	(Revision 4499)
+++ socket.c	(Arbeitskopie)
@@ -841,6 +841,8 @@
 	}
 	if (certpath)
 		SSL_CTX_load_verify_locations(_ctx, NULL, certpath);
+	else
+		SSL_CTX_set_default_verify_paths(_ctx);
 	
 	_ssl_context[sock] = SSL_new(_ctx);
 	
