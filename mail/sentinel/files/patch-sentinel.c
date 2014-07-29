--- sentinel.c.bak	Mon Oct 27 02:03:32 2003
+++ sentinel.c	Sat Dec 20 07:59:32 2003
@@ -3135,8 +3135,10 @@
     /* check if a rule defined for this header in [headers] section */
     for (smfhl = smfHeader_list[message->cfgNdx]; smfhl; smfhl = smfhl->next) {
 	if (!strcasecmp(smfhl->name, headerf)) {
+#ifndef DO_NOT_DECODE_SUBJECT
 	    if (!strcasecmp(headerf, "Subject"))
 		headerv = smfMimeDecodeString(headerv, message->buf);
+#endif
 	    if (headerv) {
 		for (smfel = smfhl->entr; smfel; smfel = smfel->next) {
 		    if (!smfPatternMatch(message, headerv, smfel->event)) {
