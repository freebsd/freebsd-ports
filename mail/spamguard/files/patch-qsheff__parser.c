--- qsheff_parser.c.orig	2007-05-30 14:06:19 UTC
+++ qsheff_parser.c
@@ -1,6 +1,9 @@
 #include <stdio.h>
 #include "qsheff_parser.h"
 
+IP_bucket* IP_bucket_arr[NUM_HASH];
+bucket* bucket_arr[NUM_HASH];
+
 extern int w;
 extern int b;
 extern int p;
@@ -225,8 +228,8 @@ qsheff_finalize(void)
                             		fprintf(fp, "%s\n", bp->recvfrom);
 					bp->is_spammer = 1;
 					printf("Paranoid Spammer: %s - %s  sent %d mails\n", bp->mail, bp->recvfrom, bp->count);
-					snprintf(mailbuf, sizeof(mailbuf - 1), " %s - %s has been spamming your box! (sent %d mails)\n No matter this mail address is matched against your spam high list: %s, or not. I'm still adding it to blacklist since s/he sent more mails then your paranoid threshold.\n\n Source mail address has been added to %s file\n Target successfully nuked!\n\n Regards,\n -EnderUNIX spamGuard %s\n http://www.enderunix.org/spamguard\n", bp->mail, bp->recvfrom, bp->count, highfile, badmailfile, VERSION);
-					mailbuf[sizeof(mailbuf - 2)] = '\0';  /* -1 is for NULL byte, the other -1 is for 'Sir BALABAN Byte' ... */
+					snprintf(mailbuf, sizeof(mailbuf) - 1, " %s - %s has been spamming your box! (sent %d mails)\n No matter this mail address is matched against your spam high list: %s, or not. I'm still adding it to blacklist since s/he sent more mails then your paranoid threshold.\n\n Source mail address has been added to %s file\n Target successfully nuked!\n\n Regards,\n -EnderUNIX spamGuard %s\n http://www.enderunix.org/spamguard\n", bp->mail, bp->recvfrom, bp->count, highfile, badmailfile, VERSION);
+					mailbuf[sizeof(mailbuf) - 2] = '\0';  /* -1 is for NULL byte, the other -1 is for 'Sir BALABAN Byte' ... */
 					send_notify_mail(mailbuf,  bp->recvfrom, "paranoid ");
                          	}
 		
