--- set.c.orig	2025-09-03 14:11:13 UTC
+++ set.c
@@ -18,7 +18,7 @@ int set_main(int argc, const char *argv[])
 	int ret = 1;
 
 	if (argc < 3) {
-		fprintf(stderr, "Usage: %s %s <interface> [listen-port <port>] [fwmark <mark>] [private-key <file path>] [jc <junk_count>] [jmin <min_value>] [jmax <max_value>] [s1 <init_junk>] [s2 <resp_junk>] [s3 <cookie_junk>] [s4 <trans_junk>] [h1 <init_header>] [h2 <resp_header>] [h3 <cookie_header>] [h4 <transp_header>] [i1 \"<taged_junk>\"] [i2 \"<taged_junk>\"] [i3 \"<taged_junk>\"] [i4 \"<taged_junk>\"] [i5 \"<taged_junk>\"] [peer <base64 public key> [remove] [preshared-key <file path>] [endpoint <ip>:<port>] [persistent-keepalive <interval seconds>] [allowed-ips <ip1>/<cidr1>[,<ip2>/<cidr2>] [advanced-security <on|off>]...] ]...\n", PROG_NAME, argv[0]);
+		fprintf(stderr, "Usage: %s %s <interface> [listen-port <port>] [fwmark <mark>] [private-key <file path>] [jc <junk_count>] [jmin <min_value>] [jmax <max_value>] [s1 <init_junk>] [s2 <resp_junk>] [s3 <cookie_junk>] [s4 <trans_junk>] [h1 <init_header>] [h2 <resp_header>] [h3 <cookie_header>] [h4 <transp_header>] [i1 \"<taged_junk>\"] [i2 \"<taged_junk>\"] [i3 \"<taged_junk>\"] [i4 \"<taged_junk>\"] [i5 \"<taged_junk>\"] [peer <base64 public key> [remove] [preshared-key <file path>] [endpoint <ip>:<port>] [persistent-keepalive <interval seconds>] [allowed-ips [+|-]<ip1>/<cidr1>[,[+|-]<ip2>/<cidr2>] [advanced-security <on|off>]...] ]...\n", PROG_NAME, argv[0]);
 		return 1;
 	}
 
