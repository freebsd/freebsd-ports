
$FreeBSD$

--- src/smtp_in.c.orig
+++ src/smtp_in.c
@@ -1610,6 +1610,8 @@
       &tzero) > 0)
     {
     int rc = read(fileno(smtp_in), smtp_inbuffer, in_buffer_size);
+    if (rc > 0)
+    {
     if (rc > 150) rc = 150;
     smtp_inbuffer[rc] = 0;
     log_write(0, LOG_MAIN|LOG_REJECT, "SMTP protocol violation: "
@@ -1618,6 +1620,7 @@
       string_printing(smtp_inbuffer));
     smtp_printf("554 SMTP synchronization error\r\n");
     return FALSE;
+      }
     }
   }
 
