diff --git a/gencode.c b/gencode.c
index bdc35e64..040a5531 100644
--- gencode.c
+++ gencode.c
@@ -6947,11 +6947,15 @@ gen_mcode(compiler_state_t *cstate, const char *s1, const char *s2,
 		return (NULL);
 
 	nlen = __pcap_atoin(s1, &n);
+	if (nlen < 0)
+		bpf_error(cstate, "invalid IPv4 address '%s'", s1);
 	/* Promote short ipaddr */
 	n <<= 32 - nlen;
 
 	if (s2 != NULL) {
 		mlen = __pcap_atoin(s2, &m);
+		if (mlen < 0)
+			bpf_error(cstate, "invalid IPv4 address '%s'", s2);
 		/* Promote short ipaddr */
 		m <<= 32 - mlen;
 		if ((n & ~m) != 0)
@@ -7009,8 +7013,11 @@ gen_ncode(compiler_state_t *cstate, const char *s, bpf_u_int32 v, struct qual q)
 		vlen = __pcap_atodn(s, &v);
 		if (vlen == 0)
 			bpf_error(cstate, "malformed decnet address '%s'", s);
-	} else
+	} else {
 		vlen = __pcap_atoin(s, &v);
+		if (vlen < 0)
+			bpf_error(cstate, "invalid IPv4 address '%s'", s);
+	}
 
 	switch (q.addr) {
 
