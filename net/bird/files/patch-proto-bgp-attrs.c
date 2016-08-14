diff --git proto/bgp/attrs.c proto/bgp/attrs.c
index d85afa8..b8371f3 100644
--- proto/bgp/attrs.c
+++ proto/bgp/attrs.c
@@ -118,7 +118,7 @@ validate_path(struct bgp_proto *p, int as_path, int bs, byte *idata, uint *ileng
 {
   int res = 0;
   u8 *a, *dst;
-  int len, plen, copy;
+  int len, plen;
 
   dst = a = idata;
   len = *ilength;
@@ -132,15 +132,20 @@ validate_path(struct bgp_proto *p, int as_path, int bs, byte *idata, uint *ileng
       if (len < plen)
 	return -1;
 
+      if (a[1] == 0)
+        {
+	  log(L_WARN "%s: %s_PATH attribute contains empty segment, skipping it",
+	      p->p.name, as_path ? "AS" : "AS4");
+	  goto skip;
+	}
+
       switch (a[0])
 	{
 	case AS_PATH_SET:
-	  copy = 1;
 	  res++;
 	  break;
 
 	case AS_PATH_SEQUENCE:
-	  copy = 1;
 	  res += a[1];
 	  break;
 
@@ -154,20 +159,17 @@ validate_path(struct bgp_proto *p, int as_path, int bs, byte *idata, uint *ileng
 
 	  log(L_WARN "%s: %s_PATH attribute contains AS_CONFED_* segment, skipping segment",
 	      p->p.name, as_path ? "AS" : "AS4");
-	  copy = 0;
-	  break;
+	  goto skip;
 
 	default:
 	  return -1;
 	}
 
-      if (copy)
-	{
-	  if (dst != a)
-	    memmove(dst, a, plen);
-	  dst += plen;
-	}
+      if (dst != a)
+	memmove(dst, a, plen);
+      dst += plen;
 
+    skip:
       len -= plen;
       a += plen;
     }
