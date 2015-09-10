--- server/confpars.c.orig	2015-02-26 19:35:43 UTC
+++ server/confpars.c
@@ -4161,28 +4161,10 @@ parse_prefix6(struct parse *cfile,
 		return;
 	}
 
-	/* Make sure starting prefix is within the subnet */
-	if (!addr_eq(group->subnet->net,
-		     subnet_number(lo, group->subnet->netmask))) {
-			      parse_warn(cfile, "prefix6 start prefix"
-                                                " is outside the subnet");
-			      skip_to_semi(cfile);
-		return;
-	}
-
 	if (!parse_ip6_addr(cfile, &hi)) {
 		return;
 	}
 
-	/* Make sure ending prefix is within the subnet */
-	if (!addr_eq(group->subnet->net,
-		     subnet_number(hi, group->subnet->netmask))) {
-			      parse_warn(cfile, "prefix6 end prefix"
-                                                " is outside the subnet");
-			      skip_to_semi(cfile);
-		return;
-	}
-
 	/*
 	 * Next is '/' number ';'.
 	 */
@@ -4205,11 +4187,6 @@ parse_prefix6(struct parse *cfile,
 		parse_warn(cfile, "networks have 0 to 128 bits (exclusive)");
 		return;
 	}
-	if (bits < group->subnet->prefix_len) {
-		parse_warn(cfile, "network mask smaller than subnet mask");
-		skip_to_semi(cfile);
-		return;
-	}
 	if (!is_cidr_mask_valid(&lo, bits) ||
 	    !is_cidr_mask_valid(&hi, bits)) {
 		parse_warn(cfile, "network mask too short");
