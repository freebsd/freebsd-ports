--- show.c.orig	2026-08-12 22:24:49 UTC
+++ show.c
@@ -195,7 +195,7 @@ static void show_usage(void)
 static const char *COMMAND_NAME;
 static void show_usage(void)
 {
-	fprintf(stderr, "Usage: %s %s { <interface> | all | interfaces } [public-key | private-key | listen-port | fwmark | peers | preshared-keys | endpoints | allowed-ips | latest-handshakes | transfer | persistent-keepalive | dump | jc | jmin | jmax | s1 | s2 | s3 | s4 | h1 | h2 | h3 | h4 | i1 | i2 | i3 | i4 | i5 | header-protection-key | content-padding-addition | rekey-after-time | rekey-timeout | reject-after-time | keepalive-timeout | max_handshake_attempts | random-trailers | disable-cookies]\n", PROG_NAME, COMMAND_NAME);
+	fprintf(stderr, "Usage: %s %s { <interface> | all | interfaces } [public-key | private-key | listen-port | fwmark | peers | preshared-keys | endpoints | allowed-ips | latest-handshakes | transfer | persistent-keepalive | dump | jc | jmin | jmax | s1 | s2 | s3 | s4 | h1 | h2 | h3 | h4 | i1 | i2 | i3 | i4 | i5 | header-protection-key | content-padding-addition | rekey-after-time | rekey-timeout | reject-after-time | keepalive-timeout | max-handshake-attempts | random-trailers | disable-cookies]\n", PROG_NAME, COMMAND_NAME);
 }
 
 static void pretty_print(struct wgdevice *device)
@@ -428,23 +428,23 @@ static bool ugly_print(struct wgdevice *device, const 
 	} else if (!strcmp(param, "i1")) {
 		if (with_interface)
 			printf("%s\t", device->name);
-		printf("%s\n", device->i1);
+		printf("%s\n", device->i1 ? device->i1 : "");
 	} else if (!strcmp(param, "i2")) {
 		if (with_interface)
 			printf("%s\t", device->name);
-		printf("%s\n", device->i2);
+		printf("%s\n", device->i2 ? device->i2 : "");
 	} else if (!strcmp(param, "i3")) {
 		if (with_interface)
 			printf("%s\t", device->name);
-		printf("%s\n", device->i3);
+		printf("%s\n", device->i3 ? device->i3 : "");
 	} else if (!strcmp(param, "i4")) {
 		if (with_interface)
 			printf("%s\t", device->name);
-		printf("%s\n", device->i4);
+		printf("%s\n", device->i4 ? device->i4 : "");
 	} else if (!strcmp(param, "i5")) {
 		if (with_interface)
 			printf("%s\t", device->name);
-		printf("%s\n", device->i5);
+		printf("%s\n", device->i5 ? device->i5 : "");
 	} else if (!strcmp(param, "header-protection-key")) {
 		if (with_interface)
 			printf("%s\t", device->name);
@@ -469,7 +469,7 @@ static bool ugly_print(struct wgdevice *device, const 
 		if (with_interface)
 			printf("%s\t", device->name);
 		printf("%s\n", u16_range_to_string(device->keepalive_timeout));
-	} else if (!strcmp(param, "max-handshake-attemps")) {
+	} else if (!strcmp(param, "max-handshake-attempts")) {
 		if (with_interface)
 			printf("%s\t", device->name);
 		printf("%s\n", u16_range_to_string(device->max_handshake_attempts));
