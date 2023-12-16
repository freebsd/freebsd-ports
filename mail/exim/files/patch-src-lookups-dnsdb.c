From 79670d3c32ccb37fe06f25d8192943b58606a32a Mon Sep 17 00:00:00 2001
From: Jeremy Harris <jgh146exb@wizmail.org>
Date: Fri, 17 Nov 2023 16:55:17 +0000
Subject: [PATCH] Lookups: Fix dnsdb lookup of multi-chunk TXT.  Bug 3054

Broken=by: f6b1f8e7d642
Source: https://git.exim.org/exim.git/patch/79670d3c32cc

--- src/lookups/dnsdb.c.orig	2023-11-04 13:55:49.000000000 +0100
+++ src/lookups/dnsdb.c	2023-11-17 21:34:25.986385000 +0100
@@ -387,38 +387,31 @@
         }
 
       /* Other kinds of record just have one piece of data each, but there may be
-      several of them, of course. */
+      several of them, of course.  TXT & SPF can have data in multiple chunks. */
 
       if (yield->ptr) yield = string_catn(yield, outsep, 1);
 
       if (type == T_TXT || type == T_SPF)
-        {
-        if (!outsep2)			/* output only the first item of data */
+	for (unsigned data_offset = 0; data_offset + 1 < rr->size; )
 	  {
-	  uschar n = (rr->data)[0];
-	  /* size byte + data bytes must not excced the RRs length */
-	  if (n + 1 <= rr->size)
-	    yield = string_catn(yield, US (rr->data+1), n);
-	  }
-        else
-          for (unsigned data_offset = 0; data_offset < rr->size; )
-            {
-            uschar chunk_len = (rr->data)[data_offset];
-	    int remain = rr->size - data_offset;
+	  uschar chunk_len = (rr->data)[data_offset];
+	  int remain;
 
-	    /* Apparently there are resolvers that do not check RRs before passing
-	    them on, and glibc fails to do so.  So every application must...
-	    Check for chunk len exceeding RR */
+	  if (outsep2 && *outsep2 && data_offset != 0)
+	    yield = string_catn(yield, outsep2, 1);
 
-	    if (chunk_len > remain)
-	      chunk_len = remain;
+	  /* Apparently there are resolvers that do not check RRs before passing
+	  them on, and glibc fails to do so.  So every application must...
+	  Check for chunk len exceeding RR */
 
-            if (*outsep2  && data_offset != 0)
-              yield = string_catn(yield, outsep2, 1);
-            yield = string_catn(yield, US ((rr->data) + ++data_offset), --chunk_len);
-            data_offset += chunk_len;
-            }
-        }
+	  remain = rr->size - ++data_offset;
+	  if (chunk_len > remain)
+	    chunk_len = remain;
+	  yield = string_catn(yield, US ((rr->data) + data_offset), chunk_len);
+	  data_offset += chunk_len;
+
+	  if (!outsep2) break;		/* output only the first chunk of the RR */
+	  }
       else if (type == T_TLSA)
 	if (rr->size < 3)
 	  continue;
