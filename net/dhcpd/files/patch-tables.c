--- tables.c.orig	2023-11-20 14:12:38 UTC
+++ tables.c
@@ -184,7 +184,7 @@ struct option dhcp_options[256] = {
 	{ "option-105", "X",				&dhcp_universe, 105 },
 	{ "option-106", "X",				&dhcp_universe, 106 },
 	{ "option-107", "X",				&dhcp_universe, 107 },
-	{ "option-108", "X",				&dhcp_universe, 108 },
+	{ "ipv6-only-preferred", "L",			&dhcp_universe, 108 },
 	{ "option-109", "X",				&dhcp_universe, 109 },
 	{ "option-110", "X",				&dhcp_universe, 110 },
 	{ "option-111", "X",				&dhcp_universe, 111 },
