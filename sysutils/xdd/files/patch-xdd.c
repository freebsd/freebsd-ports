--- xdd.c.orig	Mon May 29 04:06:49 2006
+++ xdd.c	Mon May 29 04:24:54 2006
@@ -60,7 +60,7 @@
 	/* Things used by the read-after-write operations */
 #if (IRIX || SOLARIS || HPUX || AIX || ALTIX)
 	struct stat64 statbuf;
-#elif (LINUX || OSX)
+#elif (LINUX || OSX || FreeBSD)
     struct  stat    statbuf;
 #endif
 	int64_t prev_loc; /* The previous location from a read-after-write message from the writer */
@@ -114,11 +114,11 @@
 		sleep_time_dw = (int32_t)(p->start_delay/BILLION);
 #ifdef WIN32
 		Sleep(sleep_time_dw);
-#elif (LINUX || IRIX || AIX || ALTIX || OSX) /* Add OS Support to this line for usleep() */
+#elif (LINUX || IRIX || AIX || ALTIX || OSX || FreeBSD) /* Add OS Support to this line for usleep() */
 		if ((sleep_time_dw*CLK_TCK) > 1000) /* only sleep if it will be 1 or more ticks */
 #if (IRIX || ALTIX)
 			sginap((sleep_time_dw*CLK_TCK)/1000);
-#elif (LINUX || AIX || OSX) /* Add OS Support to this line for usleep() as well*/
+#elif (LINUX || AIX || OSX || FreeBSD) /* Add OS Support to this line for usleep() as well*/
 			usleep(sleep_time_dw*1000);
 #endif
 #endif
@@ -384,14 +384,14 @@
 				p->my_current_byte_location = (uint64_t)((p->mynum * xgp->target_offset) + p->seekhdr.seeks[0].block_location) * p->block_size;
 		else    p->my_current_byte_location = (uint64_t)((p->mynum * xgp->target_offset) + p->seekhdr.seeks[current_op].block_location) * p->block_size;
 
-#if (LINUX || IRIX || SOLARIS || HPUX || AIX || ALTIX || OSX)
+#if (LINUX || IRIX || SOLARIS || HPUX || AIX || ALTIX || OSX || FreeBSD)
 		if ((p->target_options & RX_READAFTERWRITE) && (p->target_options & RX_RAW_READER)) { 
 // fprintf(stderr,"Reader: RAW check - dataready=%lld, trigger=%x\n",data_ready,p->raw_trigger);
 			/* Check to see if we can read more data - if not see where we are at */
 			if (p->raw_trigger & RX_RAW_STAT) { /* This section will continually poll the file status waiting for the size to increase so that it can read more data */
 				while (data_ready < p->iosize) {
 					/* Stat the file so see if there is data to read */
-#if (LINUX || OSX)
+#if (LINUX || OSX || FreeBSD)
 					status = fstat(p->fd,&statbuf);
 #else
 					status = fstat64(p->fd,&statbuf);
@@ -472,11 +472,11 @@
 					sleep_time_dw = sleep_time;
 #ifdef WIN32
 					Sleep(sleep_time_dw);
-#elif (LINUX || IRIX || AIX || ALTIX || OSX) /* Change this line to use usleep */
+#elif (LINUX || IRIX || AIX || ALTIX || OSX || FreeBSD) /* Change this line to use usleep */
 					if ((sleep_time_dw*CLK_TCK) > 1000) /* only sleep if it will be 1 or more ticks */
 #if (IRIX || ALTIX)
 						sginap((sleep_time_dw*CLK_TCK)/1000);
-#elif (LINUX || AIX || OSX) /* Change this line to use usleep */
+#elif (LINUX || AIX || OSX || FreeBSD) /* Change this line to use usleep */
 						usleep(sleep_time_dw*1000);
 #endif
 #endif
@@ -564,7 +564,7 @@
 #else /* UUUUUUUUUUUUUUUU Begin Unix stuff UUUUUUUUUUUUUUUUU*/
 #if (IRIX || SOLARIS || HPUX || AIX || ALTIX)
 		lseek64(p->fd,(off64_t)p->my_current_byte_location,0); 
-#elif (LINUX || OSX)
+#elif (LINUX || OSX || FreeBSD)
 		/* In Linux the -D_FILE_OFFSET_BITS=64 make the off_t type be a 64-bit integer */
                 if (!p->target_options & RX_SGIO) 
 		    lseek(p->fd, (off_t)p->my_current_byte_location, SEEK_SET);
@@ -653,7 +653,7 @@
             }
         }
         
-#if (LINUX || IRIX || SOLARIS || HPUX || AIX || ALTIX || OSX)
+#if (LINUX || IRIX || SOLARIS || HPUX || AIX || ALTIX || OSX || FreeBSD)
 		if ((p->target_options & RX_READAFTERWRITE) && (p->target_options & RX_RAW_WRITER)) {
 			/* Since I am the writer in a read-after-write operation, and if we are using a socket connection to the reader for write-completion messages
 			 * then I need to send the reader a message of what I just wrote - starting location and length of write.
