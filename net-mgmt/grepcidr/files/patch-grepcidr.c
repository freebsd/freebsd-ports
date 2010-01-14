--- ./grepcidr.c.orig	2005-04-23 18:00:16.000000000 -0400
+++ ./grepcidr.c	2010-01-14 18:17:58.469773170 -0500
@@ -81,13 +81,38 @@
 	Convert IP address string to 32-bit integer version
 	Returns 0 on failure
 */
-unsigned int ip_to_uint(const char* ip)
+unsigned int ip_to_uint(char** ip)
 {
 	unsigned int IP[4];     /* 4 octets for IP address */
-	if ((sscanf(ip, "%u.%u.%u.%u", &IP[0], &IP[1], &IP[2], &IP[3]) == 4) && VALID_IP(IP))
+	char *p = *ip;
+	char *dot;
+
+	while (*p) {
+	    while (*p && (*p < '0' || *p > '9'))
+		p++;
+	    if (!*p)
+		break;
+
+	    /* speedup: check if the first digits are followed by a dot */
+	    dot = p + 1;
+	    while (*dot >= '0' && *dot <='9')
+		dot++;
+	    if (dot > p+3 || *dot != '.') {
+		p = dot;
+		continue;
+	    }
+
+	    if ((sscanf(p, "%u.%u.%u.%u", &IP[0], &IP[1], &IP[2], &IP[3]) == 4) && VALID_IP(IP)) {
+		/* point to next possible integer */
+		while (*p >= '0' && *p <= '9')
+		    p++;
+		*ip = p;
 		return BUILD_IP(IP);
-	else
-		return 0;
+	    }
+	    p++;
+	}
+	*ip = p;
+	return 0;
 }
 
 
@@ -276,7 +301,10 @@
 	while (fgets(line, sizeof(line), inp_stream))
 	{
 		struct netspec key;
-		if ((key.min=ip_to_uint(line)))
+		char *ptr;
+
+		ptr = line;
+		while ((key.min=ip_to_uint(&ptr)))
 		{
 			int match = 0;
 			if (bsearch(&key, array, patterns, sizeof(struct netspec), netsearch))
@@ -288,6 +316,7 @@
 					counting++;
 				else
 					printf("%s", line);
+				break; /* match only once per line */
 			}
 		}
 	}
