--- Pcap.c.orig	2008-05-01 15:26:25.000000000 -0500
+++ Pcap.c	2008-05-01 15:27:21.000000000 -0500
@@ -782,9 +782,9 @@
     /* define class PcapStat */
     cPcapStat = rb_funcall(rb_cStruct, rb_intern("new"), 4,
 			   Qnil,
-			   INT2NUM(rb_intern("recv")),
-			   INT2NUM(rb_intern("drop")),
-			   INT2NUM(rb_intern("ifdrop")));
+			   ID2SYM(rb_intern("recv")),
+			   ID2SYM(rb_intern("drop")),
+			   ID2SYM(rb_intern("ifdrop")));
     rb_define_const(mPcap, "Stat", cPcapStat);
 
     /* define exception classes */
