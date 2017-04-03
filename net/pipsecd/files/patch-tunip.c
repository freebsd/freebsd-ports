--- tunip.c.orig	1999-09-21 22:20:40 UTC
+++ tunip.c
@@ -35,6 +35,8 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
+#include <sys/ioctl.h>
+#include <net/if_tun.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
@@ -58,8 +60,8 @@
 
 #include "defs.h"
 
-#define _PATH_CONF		"/etc/ipsec/pipsecd.conf"
-#define _PATH_STARTUP		"/etc/ipsec/startup"
+#define _PATH_CONF              FILE_PREFIX "/etc/ipsec/pipsecd.conf"
+#define _PATH_STARTUP           FILE_PREFIX "/etc/ipsec/startup"
 #define _PATH_DEV_RANDOM	"/dev/random"
 
 #ifdef USE_ETHERTAP
@@ -100,6 +102,7 @@ struct ethtap_header ethtap;
 #endif
 
 unsigned char buf[MAX_HEADER+MAX_PACKET];
+char *cmd;
 
 typedef union {
     MD5_CTX md5;
@@ -124,11 +127,11 @@ typedef struct hash_method {
 
 typedef union {
     BF_KEY bf;
-    des_key_schedule des;
+    DES_key_schedule des;
     struct {
-	des_key_schedule k1;
-	des_key_schedule k2;
-	des_key_schedule k3;
+	DES_key_schedule k1;
+	DES_key_schedule k2;
+	DES_key_schedule k3;
     } des3;
     CAST_KEY cast;
     IDEA_KEY_SCHEDULE idea;
@@ -704,13 +707,22 @@ void tun_new(struct tun_method *this,
  */
 int tun_send_ip(struct tun_method *this, struct encap_method *encap, int fd)
 {
-    int sent;
+    int sent, i;
 
     if (this->link_header_size) {
         encap->buflen += this->link_header_size;
         encap->buf -= this->link_header_size;
         memcpy(encap->buf, this->link_header, this->link_header_size);
     }
+#if 0
+    printf ("Packet sent to tun dev:");
+    for (i = 0; i < encap->buflen; i++) {
+      if (!(i % 16))
+        printf ("\n    ");
+      printf (" %02x", encap->buf[i]);
+    }
+    printf ("\n\n");   
+#endif
     sent = write(fd, encap->buf, encap->buflen);
     if (sent != encap->buflen)
         syslog(LOG_ERR, "truncated in: %d -> %d\n", encap->buflen, sent);
@@ -1120,6 +1132,7 @@ void config_read(FILE *cf)
 	    }
 	} else if (strcmp(arg, "if") == 0) {
 	    int fd;
+	    int i = 0;
 	    struct sa_desc *local_sa, *remote_sa;
 	    struct peer_desc *peer;
 
@@ -1128,6 +1141,7 @@ void config_read(FILE *cf)
 		perror(arg);
 		continue;
 	    }
+	    ioctl (fd, TUNSIFHEAD, &i);
 
 	    local_sa = NULL;
 	    remote_sa = NULL;
@@ -2006,7 +2020,7 @@ int my_idea_set_decrypt_key(unsigned cha
 void my_des_cbc_encrypt(unsigned char *iv, crypt_key *ek,
 			unsigned char *t, unsigned int len)
 {
-    des_cbc_encrypt(t, t, len, ek->des, iv, DES_ENCRYPT);
+    DES_cbc_encrypt(t, t, len, &ek->des, iv, DES_ENCRYPT);
 }
 
 void my_des_cbc_decrypt(unsigned char *iv, crypt_key *dk,
@@ -2018,7 +2032,7 @@ void my_des_cbc_decrypt(unsigned char *i
     for (i = 0; i < len; i++) printf(" %02x", ct[i]);
     printf("\n");
 #endif
-    des_cbc_encrypt(ct, ct, len, dk->des, iv, DES_DECRYPT);
+    DES_cbc_encrypt(ct, ct, len, &dk->des, iv, DES_DECRYPT);
 #if 0
     printf("%d bytes after decrypt\n", len);
     for (i = 0; i < len; i++) printf(" %02x", ct[i]);
@@ -2029,23 +2043,23 @@ void my_des_cbc_decrypt(unsigned char *i
 int my_des_setkey(unsigned char *b, unsigned int len, crypt_key *k)
 {
     if (len == 8)
-	return des_set_key(b, k->des);
+	return DES_set_key(b, &k->des);
     return -1;
 }
 
 void my_des3_cbc_encrypt(unsigned char *iv, crypt_key *ek,
 			 unsigned char *t, unsigned int len)
 {
-    des_ede3_cbc_encrypt(t, t, len,
-			 ek->des3.k1, ek->des3.k2, ek->des3.k3,
+    DES_ede3_cbc_encrypt(t, t, len,
+			 &ek->des3.k1, &ek->des3.k2, &ek->des3.k3,
 			 iv, DES_ENCRYPT);
 }
 
 void my_des3_cbc_decrypt(unsigned char *iv, crypt_key *dk,
 			 unsigned char *ct, unsigned int len)
 {
-    des_ede3_cbc_encrypt(ct, ct, len,
-			 dk->des3.k1, dk->des3.k2, dk->des3.k3,
+    DES_ede3_cbc_encrypt(ct, ct, len,
+			 &dk->des3.k1, &dk->des3.k2, &dk->des3.k3,
 			 iv, DES_DECRYPT);
 }
 
@@ -2054,11 +2068,11 @@ int my_des3_setkey(unsigned char *b, uns
     if (len != 24)
 	return -1;
 
-    if (des_set_key(b, k->des3.k1) != 0)
+    if (DES_set_key(b, &k->des3.k1) != 0)
 	return -1;
-    if (des_set_key(b+8, k->des3.k2) != 0)
+    if (DES_set_key(b+8, &k->des3.k2) != 0)
 	return -1;
-    if (des_set_key(b+16, k->des3.k3) != 0)
+    if (DES_set_key(b+16, &k->des3.k3) != 0)
 	return -1;
 
     return 0;
@@ -2081,6 +2095,11 @@ int null_setkey(unsigned char *b, unsign
     return 0;
 }
 
+void usage()
+{
+    fprintf(stderr, "%s: usage: [ -c CONFIG ] [ -s SCRIPT ]\n", cmd);
+    exit(1);
+}
 int main(int argc, char **argv)
 {
     time_t t;
@@ -2088,9 +2107,14 @@ int main(int argc, char **argv)
     int pack, i;
     struct sockaddr_in from;
     struct stat sb;
+    int ch;
+    char *path_conf = _PATH_CONF;
+    char *path_startup = _PATH_STARTUP;
 
     FILE *f;
 
+    cmd=argv[0];
+
     openlog ("pipsecd", LOG_PID, LOG_DAEMON);
     syslog (LOG_NOTICE, "pipsecd starting");
 
@@ -2113,7 +2137,21 @@ int main(int argc, char **argv)
     if (encap_icmp_new(&encap_meth[ENCAP_ICMP], IPPROTO_ICMP) == -1)
 	exit(1);
 
-    f = fopen(_PATH_CONF, "r");
+    while ((ch = getopt(argc, argv, "c:s:")) != -1) {
+	switch (ch) {
+	case 'c':
+	    path_conf = optarg;
+	    break;
+	case 's':
+	    path_startup = optarg;
+	    break;
+	case '?':
+	default:
+	    usage();
+	}
+    }
+
+    f = fopen(path_conf, "r");
     if (f == NULL) {
 	perror("configuration file");
 	exit(1);
@@ -2123,8 +2161,8 @@ int main(int argc, char **argv)
     fclose(f);
 
     /* Execute startup script, if any */
-    if (stat(_PATH_STARTUP, &sb) == 0 && (sb.st_mode & 0400))
-	system(_PATH_STARTUP);
+    if (stat(path_startup, &sb) == 0 && (sb.st_mode & 0400))
+	system(path_startup);
 
     /* Send a probe to every peer on startup */
     for (i = 0; i < peer_num; i++)
