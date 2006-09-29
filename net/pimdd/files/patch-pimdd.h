--- pimdd.h.orig	Fri Sep 29 11:53:56 2006
+++ pimdd.h	Fri Sep 29 11:54:07 2006
@@ -202,7 +202,7 @@
 
 #define PIM_ASSERT_RPT_BIT 0x80000000
 
-
+#if 0
 /* PIM messages type */
 #define PIM_HELLO               0
 #ifndef PIM_REGISTER
@@ -215,6 +215,7 @@
 #define PIM_GRAFT               6
 #define PIM_GRAFT_ACK           7
 #define PIM_CAND_RP_ADV         8
+#endif
 
 #define PIM_V2_HELLO            PIM_HELLO
 #define PIM_V2_REGISTER         PIM_REGISTER
