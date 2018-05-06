--- src/modules/ctl/ctl.c.orig	2018-03-01 16:24:09 UTC
+++ src/modules/ctl/ctl.c
@@ -240,8 +240,7 @@ static int mod_init(void)
 				return -1;
 			}
 			strcpy(ctl_socket_path, DEFAULT_CTL_SOCKET_PROTO);
-			strcat(ctl_socket_path, runtime_dir);
-			strcat(ctl_socket_path, "/");
+			strcat(ctl_socket_path, "/var/run/");
 			strcat(ctl_socket_path, DEFAULT_CTL_SOCKET_NAME);
 			add_binrpc_socket(PARAM_STRING, ctl_socket_path);
 		}
