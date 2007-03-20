--- class/deliver/Deliver_SMTP.class.php.orig   Sat Jan 28 21:24:07 2006
+++ class/deliver/Deliver_SMTP.class.php        Mon Nov 13 16:26:14 2006
@@ -69,7 +69,7 @@
             $this->authPop($host, '', $user, $pass);
         }

-        $rfc822_header = $message->rfc822_header;
+        $rfc822_header = unserialize(serialize($message->rfc822_header));

         $from = $rfc822_header->from[0];
         $to =   $rfc822_header->to;

