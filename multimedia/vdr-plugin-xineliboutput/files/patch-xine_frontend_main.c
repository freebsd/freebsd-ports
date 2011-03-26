--- a/xine_frontend_main.c
+++ b/xine_frontend_main.c
@@ -629,7 +629,7 @@ int main(int argc, char *argv[])
     case 'C': config_file = optarg;
               PRINTF("Config file: %s\n", config_file);
               break;
-    case 'L': lirc_dev = strdup(optarg ? : "/dev/lircd");
+    case 'L': lirc_dev = strdup(optarg ? : "/var/run/lirc/lircd");
               if (strstr(lirc_dev, ",repeatemu")) {
                 *strstr(lirc_dev, ",repeatemu") = 0;
                 repeat_emu = 1;
