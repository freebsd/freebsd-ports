*** lib/krb5/asn.1/asn1buf.c	12 Mar 2003 04:33:30 -0000	5.24
--- lib/krb5/asn.1/asn1buf.c	23 Aug 2004 03:43:47 -0000
***************
*** 122,127 ****
--- 122,129 ----
        return ASN1_OVERRUN;
    }
    while (nestlevel > 0) {
+     if (buf->bound - buf->next + 1 <= 0)
+       return ASN1_OVERRUN;
      retval = asn1_get_tag_2(buf, &t);
      if (retval) return retval;
      if (!t.indef) {
