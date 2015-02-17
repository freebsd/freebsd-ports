diff -r 304d545927d2 -r 09d3c9c6f0ad src/login-common/client-common.c
--- src/login-common/client-common.c.orig       Wed Jun 04 00:35:27 2014 +0300
+++ src/login-common/client-common.c    Thu Jun 05 11:30:19 2014 +0300
@@ -172,6 +172,7 @@
                last_client = client->prev;
        DLLIST_REMOVE(&clients, client);

+       o_stream_uncork(client->output);
        if (!client->login_success && client->ssl_proxy != NULL)
                ssl_proxy_destroy(client->ssl_proxy);
        if (client->input != NULL)
