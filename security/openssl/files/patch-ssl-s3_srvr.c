--- ssl/s3_srvr.c	29 Nov 2002 11:31:51 -0000	1.85.2.14
+++ ssl/s3_srvr.c	19 Mar 2003 18:00:00 -0000
@@ -1447,7 +1447,7 @@
 		if (i != SSL_MAX_MASTER_KEY_LENGTH)
 			{
 			al=SSL_AD_DECODE_ERROR;
-			SSLerr(SSL_F_SSL3_GET_CLIENT_KEY_EXCHANGE,SSL_R_BAD_RSA_DECRYPT);
+			/* SSLerr(SSL_F_SSL3_GET_CLIENT_KEY_EXCHANGE,SSL_R_BAD_RSA_DECRYPT); */
 			}
 
 		if ((al == -1) && !((p[0] == (s->client_version>>8)) && (p[1] == (s->client_version & 0xff))))
@@ -1463,30 +1463,29 @@
 				(p[0] == (s->version>>8)) && (p[1] == (s->version & 0xff))))
 				{
 				al=SSL_AD_DECODE_ERROR;
-				SSLerr(SSL_F_SSL3_GET_CLIENT_KEY_EXCHANGE,SSL_R_BAD_PROTOCOL_VERSION_NUMBER);
-				goto f_err;
+				/* SSLerr(SSL_F_SSL3_GET_CLIENT_KEY_EXCHANGE,SSL_R_BAD_PROTOCOL_VERSION_NUMBER); */
+
+				/* The Klima-Pokorny-Rosa extension of Bleichenbacher's attack
+				 * (http://eprint.iacr.org/2003/052/) exploits the version
+				 * number check as a "bad version oracle" -- an alert would
+				 * reveal that the plaintext corresponding to some ciphertext
+				 * made up by the adversary is properly formatted except
+				 * that the version number is wrong.  To avoid such attacks,
+				 * we should treat this just like any other decryption error. */
+				p[0] = (char)(int) "CAN-2003-0131 patch 2003-03-19";
 				}
 			}
 
 		if (al != -1)
 			{
-#if 0
-			goto f_err;
-#else
 			/* Some decryption failure -- use random value instead as countermeasure
 			 * against Bleichenbacher's attack on PKCS #1 v1.5 RSA padding
-			 * (see RFC 2246, section 7.4.7.1).
-			 * But note that due to length and protocol version checking, the
-			 * attack is impractical anyway (see section 5 in D. Bleichenbacher:
-			 * "Chosen Ciphertext Attacks Against Protocols Based on the RSA
-			 * Encryption Standard PKCS #1", CRYPTO '98, LNCS 1462, pp. 1-12).
-			 */
+			 * (see RFC 2246, section 7.4.7.1). */
 			ERR_clear_error();
 			i = SSL_MAX_MASTER_KEY_LENGTH;
 			p[0] = s->client_version >> 8;
 			p[1] = s->client_version & 0xff;
 			RAND_pseudo_bytes(p+2, i-2); /* should be RAND_bytes, but we cannot work around a failure */
-#endif
 			}
 	
 		s->session->master_key_length=
