--- nsock/src/nsock_event.c.orig	Fri Oct  3 15:33:05 2003
+++ nsock/src/nsock_event.c	Fri Oct  3 15:32:31 2003
@@ -242,8 +242,9 @@
   int type_code = (int) type;
   unsigned long serial = ms->next_event_serial++;
   unsigned long max_serial_allowed;
-  int shiftbits = sizeof(nsock_event_id) * 8 - TYPE_CODE_NUM_BITS;
+  int shiftbits;
   assert(type <= 3);
+  shiftbits = sizeof(nsock_event_id) * 8 - TYPE_CODE_NUM_BITS;
   
   max_serial_allowed = ( 1 << shiftbits ) - 1;
   if (serial == max_serial_allowed ) {
