--- VIRTUAL_VACATION/vacation.pl.orig	Thu May 19 22:06:24 2005
+++ VIRTUAL_VACATION/vacation.pl	Thu May 19 22:06:38 2005
@@ -160,7 +160,7 @@
       my @row = $sth->fetchrow_array;
       if (do_cache ($email, $orig_from)) { return; }
       do_debug ("[SEND RESPONSE] for $orig_messageid:\n", "FROM: $email (orig_to: $orig_to)\n", "TO: $orig_from\n", "SUBJECT: $orig_subject\n", "VACATION SUBJECT: $row[0]\n", "VACATION BODY: $row[1]\n");
-      do_mail ($orig_to, $orig_from, $row[0], $row[1]);
+      do_mail ($email, $orig_from, $row[0], $row[1]);
       do_log ($orig_messageid, $orig_to, $orig_from, $orig_subject); 
    }
 
