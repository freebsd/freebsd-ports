--- patch-lib-recurrence_internal.h begins here ---
--- lib/recurrence_internal.h.orig	Sat Aug 14 00:15:01 2004
+++ lib/recurrence_internal.h	Sat Aug 14 00:17:12 2004
@@ -52,7 +52,7 @@
   uint32_t  start_minute P;       /* 0x3e */
   uint32_t  end_minute P;         /* 0x42 */
   uint8_t   padding2[4] P;        /* 0x46 */
-} RecurringWeekly P;
+} P RecurringWeekly;
 
 /* size = 0x20 */
 typedef struct
@@ -68,7 +68,7 @@
   uint32_t  start_minute P;       /* 0x3e */
   uint32_t  end_minute P;         /* 0x42 */
   uint8_t   padding2[4] P;        /* 0x46 */
-} RecurringMonthly P;
+} P RecurringMonthly;
 
 /* size = 0x20 */
 typedef struct
@@ -86,7 +86,7 @@
   uint8_t   unknown3[0xc] P;      /* 0x36 */
   uint32_t  start_minute P;       /* 0x42 */
   uint32_t  end_minute P;         /* 0x46 */
-} RecurringMonthNth P;
+} P RecurringMonthNth;
 
 /* size = 0x68 */
 typedef struct
@@ -101,7 +101,7 @@
     RecurringMonthNth month_nth P;
   } details P;
   uint8_t   unknown4[0x1e] P;     /* 0x4a */
-} RecurrenceBlob P;
+} P RecurrenceBlob;
 
 enum
 {
