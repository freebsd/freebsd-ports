--- filter-rspamd.go.orig	2023-06-14 17:13:00 UTC
+++ filter-rspamd.go
@@ -135,7 +135,7 @@ func linkAuth(s *session, params []string) {
 
 	var user, res string
 	if version < "0.7" {
-		res = params[len(params) - 1]
+		res = params[len(params)-1]
 		user = strings.Join(params[0:len(params)-1], "|")
 	} else {
 		res = params[0]
@@ -479,48 +479,71 @@ func rspamdQuery(s *session, token string) {
 	}
 
 	if len(rr.Headers.Add) > 0 {
-		authHeaders := map[string]string{}
+		// Authentication headers from Rspamd are in the form of:
+		// "ARC-Seal":                   { "order": 1, "value": text }
+		// "ARC-Authentication-Results": { "order": 1, "value": text }
+		// "ARC-Message-Signature":      { "order": 1, "value": text }
+		// Unfortunately they all have an order of 1,
+		// thought they should be ordered as per RFC 8617
+		// so we give them a fixed order, and shift everything after
+		orderFix := map[string]int{
+			"ARC-Seal":                   0,
+			"ARC-Message-Signature":      1,
+			"ARC-Authentication-Results": 2,
+		}
 
+		// headers, indexed by order
+		headers := map[int]map[string]string{-1: {}}
+
 		for h, t := range rr.Headers.Add {
+			if h == "" {
+				continue
+			}
+
 			switch v := t.(type) {
-			/**
-			 * Authentication headers from Rspamd are in the form of:
-			 * ARC-Seal : { order : 1, value : text }
-			 * ARC-Message-Signature : { order : 1, value : text }
-			 * Unfortunately they all have an order of 1, so we
-			 * make a map of them and print them in proper order.
-			 */
+			case string:
+				// Regular headers from Rspamd used to be plain strings
+				// continue to accept this old format, just in case
+
+				headers[-1][h] = v
+
 			case map[string]interface{}:
-				if h != "" {
-					v, ok := v["value"].(string)
-					if ok {
-						authHeaders[h] = v
+				// They are now in the form { "value": text, "order": -1 }
+				// so we convert them, and use `order` as the map index
+
+				vv, ok_v := v["value"].(string)
+				vo, ok_o := v["order"].(float64)
+				if ok_v && ok_o {
+					vo := int(vo)
+					if vo > -1 {
+						o_fix, ok := orderFix[h]
+						if ok {
+							vo = o_fix
+						} else {
+							// if not in orderFix, add after
+							vo = vo + len(orderFix)
+						}
 					}
+
+					if _, ok := headers[vo]; !ok {
+						headers[vo] = map[string]string{}
+					}
+					headers[vo][h] = vv
 				}
-			/**
-			 * Regular X-Spam headers from Rspamd are plain strings.
-			 * Insert these at the top.
-			 */
-			case string:
-				writeHeader(s, token, h, v)
+
 			default:
 			}
 		}
 
-		/**
-		 * Prefix auth headers to incoming mail in proper order.
-		 */
-		if len(authHeaders) > 0 {
-			hdrs := []string{
-				"ARC-Seal",
-				"ARC-Message-Signature",
-				"ARC-Authentication-Results",
-				"Authentication-Results"}
-
-			for _, h := range hdrs {
-				if authHeaders[h] != "" {
-					writeHeader(s, token, h, authHeaders[h])
-				}
+		// add the headers in order
+		orders := make([]int, 0, len(headers))
+		for k := range headers {
+			orders = append(orders, k)
+		}
+		sort.Ints(orders)
+		for _, o := range orders {
+			for h, v := range headers[o] {
+				writeHeader(s, token, h, v)
 			}
 		}
 	}
