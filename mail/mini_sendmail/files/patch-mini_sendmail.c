--- mini_sendmail.c.orig       2005-06-29 19:37:15.000000000 +0200
+++ mini_sendmail.c    2008-11-02 17:09:53.000000000 +0100
@@ -542,6 +542,7 @@
         }

     /* Strip off any angle brackets. */
+/*
     while ( len > 0 && *recipient == '<' )
         {
         ++recipient;
@@ -551,6 +552,23 @@
         --len;

     (void) snprintf( buf, sizeof(buf), "RCPT TO:<%.*s>", len, recipient );
+*/
+    if (len > 0 && recipient[len-1] == '>' )
+    {
+        /* "<name@domain>" or: "Full Name <name@domain>" */
+        while (len > 0 && *recipient != '<' )
+            {
+            ++recipient;
+            --len;
+            }
+        (void) snprintf( buf, sizeof(buf), "RCPT TO:%.*s", len, recipient );
+    }
+    else
+    {
+        /* name@domain */
+        (void) snprintf( buf, sizeof(buf), "RCPT TO:<%.*s>", len, recipient );
+    }
+
     send_command( buf );
     status = read_response();
     if ( status != 250  && status != 251 )


