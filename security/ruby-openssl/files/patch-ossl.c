Index: ossl.c
===================================================================
RCS file: /cvsroot/rubypki/ossl2/ossl.c,v
retrieving revision 1.23
retrieving revision 1.24
diff -u -r1.23 -r1.24
--- ossl.c	21 Feb 2003 14:14:29 -0000	1.23
+++ ossl.c	24 Feb 2003 16:23:10 -0000	1.24
@@ -1,5 +1,5 @@
 /*
- * $Id: ossl.c,v 1.23 2003/02/21 14:14:29 majkl Exp $
+ * $Id: ossl.c,v 1.24 2003/02/24 16:23:10 majkl Exp $
  * 'OpenSSL for Ruby' project
  * Copyright (C) 2001-2002  Michal Rokos <m.rokos@sh.cvut.cz>
  * All rights reserved.
@@ -44,7 +44,8 @@
 asn1time_to_time(ASN1_TIME *time)
 {
     struct tm tm;
-
+    VALUE argv[6];
+    
     if (!time) {
 	ossl_raise(rb_eTypeError, "ASN1_TIME is NULL!");
     }
@@ -64,8 +65,16 @@
     default:
 	ossl_raise(rb_eTypeError, "unknown time format");
     }
-    return rb_time_new(mktime(&tm) - timezone, 0);
+//    return rb_time_new(mktime(&tm) - timezone, 0);
+    argv[0] = INT2NUM(tm.tm_year);
+    argv[1] = INT2NUM(tm.tm_mon+1);
+    argv[2] = INT2NUM(tm.tm_mday);
+    argv[3] = INT2NUM(tm.tm_hour);
+    argv[4] = INT2NUM(tm.tm_min);
+    argv[5] = INT2NUM(tm.tm_sec);
+
+    return rb_funcall2(rb_cTime, rb_intern("utc"), 6, argv);
 }
 
 /*
