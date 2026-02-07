--- pimdd.h.orig	1999-11-30 17:58:53 UTC
+++ pimdd.h
@@ -202,7 +202,7 @@ typedef struct pim_jp_encod_grp_ {
 
 #define PIM_ASSERT_RPT_BIT 0x80000000
 
-
+#if 0
 /* PIM messages type */
 #define PIM_HELLO               0
 #ifndef PIM_REGISTER
@@ -215,6 +215,7 @@ typedef struct pim_jp_encod_grp_ {
 #define PIM_GRAFT               6
 #define PIM_GRAFT_ACK           7
 #define PIM_CAND_RP_ADV         8
+#endif
 
 #define PIM_V2_HELLO            PIM_HELLO
 #define PIM_V2_REGISTER         PIM_REGISTER
