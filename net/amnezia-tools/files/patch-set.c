--- set.c.orig	2024-10-01 13:02:42 UTC
+++ set.c
@@ -18,7 +18,7 @@ int set_main(int argc, const char *argv[])
 	int ret = 1;
 
 	if (argc < 3) {
-		fprintf(stderr, "Usage: %s %s <interface> [listen-port <port>] [fwmark <mark>] [private-key <file path>] [peer <base64 public key> [remove] [preshared-key <file path>] [endpoint <ip>:<port>] [persistent-keepalive <interval seconds>] [allowed-ips <ip1>/<cidr1>[,<ip2>/<cidr2>] [advanced-security <on|off>]...] ]...\n", PROG_NAME, argv[0]);
+		fprintf(stderr, "Usage: %s %s <interface> [listen-port <port>] [fwmark <mark>] [private-key <file path>] [peer <base64 public key> [remove] [preshared-key <file path>] [endpoint <ip>:<port>] [persistent-keepalive <interval seconds>] [allowed-ips [+|-]<ip1>/<cidr1>[,[+|-]<ip2>/<cidr2>] [advanced-security <on|off>]...] ]...\n", PROG_NAME, argv[0]);
 		return 1;
 	}
 
