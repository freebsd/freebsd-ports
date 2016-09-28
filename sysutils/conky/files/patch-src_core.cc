--- src/core.cc.orig	2016-07-20 16:53:48 UTC
+++ src/core.cc
@@ -898,11 +898,12 @@ struct text_object *construct_text_objec
 			return NULL;
 		}
 	} else
-#ifdef __linux__
 	OBJ(addr, &update_net_stats)
 		parse_net_stat_arg(obj, arg, free_at_crash);
 		obj->callbacks.print = &print_addr;
-	END OBJ(addrs, &update_net_stats)
+	END
+#ifdef __linux__
+	OBJ(addrs, &update_net_stats)
 		parse_net_stat_arg(obj, arg, free_at_crash);
 		obj->callbacks.print = &print_addrs;
 #ifdef BUILD_IPV6
