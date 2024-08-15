--- src/oping.c.orig	2017-05-11 07:32:27 UTC
+++ src/oping.c
@@ -1125,7 +1125,7 @@ static int update_graph_prettyping (ping_context_t *ct
 			wattron (ctx->window, COLOR_PAIR(color));
 
 		if (has_utf8())
-			mvwprintw (ctx->window, /* y = */ 3, /* x = */ x + 2, symbol);
+			mvwprintw (ctx->window, /* y = */ 3, /* x = */ x + 2, "%s", symbol);
 		else
 			mvwaddch (ctx->window, /* y = */ 3, /* x = */ x + 2, symbolc);
 
@@ -1223,7 +1223,7 @@ static int update_graph_histogram (ping_context_t *ctx
 			mvwaddch (ctx->window, /* y = */ 3, /* x = */ x + 2, ' ');
 		else if (has_utf8 ())
 			mvwprintw (ctx->window, /* y = */ 3, /* x = */ x + 2,
-					hist_symbols_utf8[index]);
+					"%s", hist_symbols_utf8[index]);
 		else
 			mvwaddch (ctx->window, /* y = */ 3, /* x = */ x + 2,
 					hist_symbols_acs[index] | A_ALTCHARSET);
@@ -1600,8 +1600,7 @@ static void update_host_hook (pingobj_iter_t *iter, /*
 
 			HOST_PRINTF ("%zu bytes from %s (%s): icmp_seq=%u ttl=%i ",
 					data_len, context->host, context->addr,
-					sequence, recv_ttl,
-					format_qos (recv_qos, recv_qos_str, sizeof (recv_qos_str)));
+					sequence, recv_ttl);
 			if ((recv_qos != 0) || (opt_send_qos != 0))
 			{
 				HOST_PRINTF ("qos=%s ",
