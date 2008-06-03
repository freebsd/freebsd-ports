--- src/conky.c.orig	2008-05-27 00:30:59.000000000 -0400
+++ src/conky.c	2008-05-27 00:32:49.000000000 -0400
@@ -56,6 +56,7 @@
 #include <netdb.h>
 #include <fcntl.h>
 #include <getopt.h>
+#include <stdarg.h>
 
 #ifdef HAVE_ICONV
 #include <iconv.h>
@@ -3529,9 +3530,11 @@ static struct text_object *construct_tex
 	END OBJ(user_times, INFO_USERS)
 	END OBJ(user_terms, INFO_USERS)
 	END OBJ(user_number, INFO_USERS)
+#ifdef __linux__
 	END OBJ(gw_iface, INFO_GW)
 	END OBJ(gw_ip, INFO_GW)
 	END OBJ(if_gw, INFO_GW)
+#endif /* __linux__ */
 #ifndef __OpenBSD__
 	END OBJ(adt746xcpu, 0)
 	END OBJ(adt746xfan, 0)
@@ -5375,9 +5378,11 @@ static void generate_text_internal(char 
 					if_jumped = 0;
 				}
 			}
+#ifdef __linux__
 			OBJ(ioscheduler) {
 				snprintf(p, p_max_size, "%s", get_ioscheduler(obj->data.s));
 			}
+#endif
 			OBJ(kernel) {
 				snprintf(p, p_max_size, "%s", cur->uname_s.release);
 			}
