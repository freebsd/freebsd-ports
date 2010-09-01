--- src/libopensc/reader-pcsc.c.orig	2010-09-01 12:44:28.000000000 +0200
+++ src/libopensc/reader-pcsc.c	2010-09-01 12:44:52.000000000 +0200
@@ -80,7 +80,7 @@
 
 struct pcsc_slot_data {
 	SCARDHANDLE pcsc_card;
-	SCARD_READERSTATE_A reader_state;
+	SCARD_READERSTATE reader_state;
 	DWORD verify_ioctl;
 	DWORD verify_ioctl_start;
 	DWORD verify_ioctl_finish;
@@ -353,7 +353,7 @@
 	sc_context_t *ctx;
 	SCARDCONTEXT pcsc_ctx;
 	LONG ret;
-	SCARD_READERSTATE_A rgReaderStates[SC_MAX_READERS];
+	SCARD_READERSTATE rgReaderStates[SC_MAX_READERS];
 	unsigned long on_bits, off_bits;
 	time_t end_time, now, delta;
 	size_t i;
@@ -401,7 +401,7 @@
 	/* Wait for a status change and return if it's a card insert/removal
 	 */
 	for( ; ; ) {
-		SCARD_READERSTATE_A *rsp;
+		SCARD_READERSTATE *rsp;
 
 		/* Scan the current state of all readers to see if they
 		 * match any of the events we're polling for */
