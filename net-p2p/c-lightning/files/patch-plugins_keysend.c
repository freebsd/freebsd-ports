--- plugins/keysend.c.orig	2020-06-25 14:05:27 UTC
+++ plugins/keysend.c
@@ -133,7 +133,7 @@ static struct command_result *htlc_accepted_call(struc
 
 	ki = tal(cmd, struct keysend_in);
 	memcpy(&ki->payment_preimage, preimage_field->value, 32);
-	ki->label = tal_fmt(ki, "keysend-%lu.%09lu", now.ts.tv_sec, now.ts.tv_nsec);
+	ki->label = tal_fmt(ki, "keysend-%lu.%09lu", (unsigned long)now.ts.tv_sec, now.ts.tv_nsec);
 	ki->payload = tal_steal(ki, payload);
 	ki->preimage_field = preimage_field;
 
