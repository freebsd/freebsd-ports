--- bgpd/bgp_aspath.c.orig	2008-09-05 22:27:26.000000000 +0800
+++ bgpd/bgp_aspath.c	2009-04-30 16:33:56.000000000 +0800
@@ -393,25 +393,6 @@
   return ' ';
 }
 
-/* countup asns from this segment and index onward */
-static int
-assegment_count_asns (struct assegment *seg, int from)
-{
-  int count = 0;
-  while (seg)
-    {
-      if (!from)
-        count += seg->length;
-      else
-        {
-          count += (seg->length - from);
-          from = 0;
-        }
-      seg = seg->next;
-    }
-  return count;
-}
-
 unsigned int
 aspath_count_confeds (struct aspath *aspath)
 {
@@ -521,6 +502,21 @@
   return num;
 }
 
+static void
+aspath_make_str_big_enough (int len,
+			    char **str_buf,
+			    int *str_size,
+			    int count_to_be_added)
+{
+#define TERMINATOR 1
+  while (len + count_to_be_added + TERMINATOR > *str_size)
+    {
+      *str_size *= 2;
+      *str_buf = XREALLOC (MTYPE_AS_STR, *str_buf, *str_size);
+    }
+#undef TERMINATOR
+}
+
 /* Convert aspath structure to string expression. */
 static char *
 aspath_make_str_count (struct aspath *as)
@@ -540,18 +536,7 @@
   
   seg = as->segments;
   
-  /* ASN takes 5 chars at least, plus seperator, see below.
-   * If there is one differing segment type, we need an additional
-   * 2 chars for segment delimiters, and the final '\0'.
-   * Hopefully this is large enough to avoid hitting the realloc
-   * code below for most common sequences.
-   *
-   * With 32bit ASNs, this range will increase, but only worth changing
-   * once there are significant numbers of ASN >= 100000
-   */
-#define ASN_STR_LEN (5 + 1)
-  str_size = MAX (assegment_count_asns (seg, 0) * ASN_STR_LEN + 2 + 1,
-                  ASPATH_STR_DEFAULT_LEN);
+  str_size = ASPATH_STR_DEFAULT_LEN;
   str_buf = XMALLOC (MTYPE_AS_STR, str_size);
 
   while (seg)
@@ -575,32 +560,24 @@
             return NULL;
         }
       
-      /* We might need to increase str_buf, particularly if path has
-       * differing segments types, our initial guesstimate above will
-       * have been wrong.  need 5 chars for ASN, a seperator each and
-       * potentially two segment delimiters, plus a space between each
-       * segment and trailing zero.
-       *
-       * This may need to revised if/when significant numbers of
-       * ASNs >= 100000 are assigned and in-use on the internet...
-       */
-#define SEGMENT_STR_LEN(X) (((X)->length * ASN_STR_LEN) + 2 + 1 + 1)
-      if ( (len + SEGMENT_STR_LEN(seg)) > str_size)
-        {
-          str_size = len + SEGMENT_STR_LEN(seg);
-          str_buf = XREALLOC (MTYPE_AS_STR, str_buf, str_size);
-        }
-#undef ASN_STR_LEN
-#undef SEGMENT_STR_LEN
-      
       if (seg->type != AS_SEQUENCE)
-        len += snprintf (str_buf + len, str_size - len, 
-			 "%c", 
-                         aspath_delimiter_char (seg->type, AS_SEG_START));
+	{
+	  aspath_make_str_big_enough (len, &str_buf, &str_size, 1); /* %c */
+	  len += snprintf (str_buf + len, str_size - len, 
+			   "%c", 
+			   aspath_delimiter_char (seg->type, AS_SEG_START));
+	}
       
       /* write out the ASNs, with their seperators, bar the last one*/
       for (i = 0; i < seg->length; i++)
         {
+#define APPROX_DIG_CNT(x) (x < 100000U ? 5 : 10)
+	  /* %u + %c + %c + " " (last two are below loop) */
+	  aspath_make_str_big_enough (len,
+				      &str_buf,
+				      &str_size,
+				      APPROX_DIG_CNT(seg->as[i]) + 1 + 1 + 1);
+
           len += snprintf (str_buf + len, str_size - len, "%u", seg->as[i]);
           
           if (i < (seg->length - 1))
@@ -1771,8 +1748,8 @@
 static int
 aspath_cmp (const void *arg1, const void *arg2)
 {
-  const struct assegment *seg1 = ((struct aspath *)arg1)->segments;
-  const struct assegment *seg2 = ((struct aspath *)arg2)->segments;
+  const struct assegment *seg1 = ((const struct aspath *)arg1)->segments;
+  const struct assegment *seg2 = ((const struct aspath *)arg2)->segments;
   
   while (seg1 || seg2)
     {
