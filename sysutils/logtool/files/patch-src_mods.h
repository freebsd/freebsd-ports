--- src/mods.h.orig	2003-04-17 11:21:37 UTC
+++ src/mods.h
@@ -45,12 +45,12 @@ short int ltm_iptables();
 char *get_host(char *host);
 
 /* for the snort log lines (this one's a bit complicated)	*/
-short int ltm_snort();
+extern short int ltm_snort();
 
 /* variables to tell us if we're to use the functions in question or not	*/
-short int ltm_use_syslog;
-short int ltm_use_snort;
-short int ltm_use_sudo;
+extern short int ltm_use_syslog;
+extern short int ltm_use_snort;
+extern short int ltm_use_sudo;
 /* "ltm_unknown(); we allways have enabled (otherwise, what's the use?		*/
 
 /* data structs for iptables and snort and so-on for linking in event->special  */
@@ -66,7 +66,7 @@ typedef struct {
         char class[512];        /* Classification: field */
         char prior[512];        /* Priority: field */
 } SNORT;
-SNORT sn;
+extern SNORT sn;
 
 /* repeat for iptables variables */
 typedef struct {
@@ -84,7 +84,7 @@ typedef struct {
         char ttl[64];           /* TTL=ttl      packet time to live     */
         char proto[64];         /* PROTO=UDP    protocol of datagram    */
 } IPTABLES;
-IPTABLES it;
+extern IPTABLES it;
 
 /* a wrapper struct so's we can point to structs like the above from 
  * event.* struct (see logtool.h for this struct) */
