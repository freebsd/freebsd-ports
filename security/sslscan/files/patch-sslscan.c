--- sslscan.c.orig	2009-09-01 12:35:59 UTC
+++ sslscan.c
@@ -41,6 +41,7 @@
 #include <openssl/pkcs12.h>
 #include <openssl/x509.h>
 #include <openssl/x509v3.h>
+#include <netinet/in.h>
 
 // Defines...
 #define false 0
@@ -563,15 +564,6 @@ int testCipher(struct sslCheckOptions *o
 					}
 					if (options->xmlOutput != 0)
 						fprintf(options->xmlOutput, " sslversion=\"");
-					if (sslCipherPointer->sslMethod == SSLv2_client_method())
-					{
-						if (options->xmlOutput != 0)
-							fprintf(options->xmlOutput, "SSLv2\" bits=\"");
-						if (options->pout == true)
-							printf("SSLv2 || ");
-						else
-							printf("SSLv2  ");
-					}
 					else if (sslCipherPointer->sslMethod == SSLv3_client_method())
 					{
 						if (options->xmlOutput != 0)
@@ -688,16 +680,7 @@ int defaultCipher(struct sslCheckOptions
 						cipherStatus = SSL_connect(ssl);
 						if (cipherStatus == 1)
 						{
-							if (sslMethod == SSLv2_client_method())
-							{
-								if (options->xmlOutput != 0)
-									fprintf(options->xmlOutput, "  <defaultcipher sslversion=\"SSLv2\" bits=\"");
-								if (options->pout == true)
-									printf("|| SSLv2 || ");
-								else
-									printf("    SSLv2  ");
-							}
-							else if (sslMethod == SSLv3_client_method())
+							if (sslMethod == SSLv3_client_method())
 							{
 								if (options->xmlOutput != 0)
 									fprintf(options->xmlOutput, "  <defaultcipher sslversion=\"SSLv3\" bits=\"");
@@ -1192,14 +1175,11 @@ int testHost(struct sslCheckOptions *opt
 		switch (options->sslVersion)
 		{
 			case ssl_all:
-				status = defaultCipher(options, SSLv2_client_method());
-				if (status != false)
-					status = defaultCipher(options, SSLv3_client_method());
+				status = defaultCipher(options, SSLv3_client_method());
 				if (status != false)
 					status = defaultCipher(options, TLSv1_client_method());
 				break;
 			case ssl_v2:
-				status = defaultCipher(options, SSLv2_client_method());
 				break;
 			case ssl_v3:
 				status = defaultCipher(options, SSLv3_client_method());
@@ -1379,7 +1359,6 @@ int main(int argc, char *argv[])
 			printf("                       ports (i.e. host:port).\n");
 			printf("  %s--no-failed%s          List only accepted ciphers  (default\n", COL_GREEN, RESET);
 			printf("                       is to listing all ciphers).\n");
-			printf("  %s--ssl2%s               Only check SSLv2 ciphers.\n", COL_GREEN, RESET);
 			printf("  %s--ssl3%s               Only check SSLv3 ciphers.\n", COL_GREEN, RESET);
 			printf("  %s--tls1%s               Only check TLSv1 ciphers.\n", COL_GREEN, RESET);
 			printf("  %s--pk=<file>%s          A file containing the private key or\n", COL_GREEN, RESET);
@@ -1415,12 +1394,10 @@ int main(int argc, char *argv[])
 			switch (options.sslVersion)
 			{
 				case ssl_all:
-					populateCipherList(&options, SSLv2_client_method());
 					populateCipherList(&options, SSLv3_client_method());
 					populateCipherList(&options, TLSv1_client_method());
 					break;
 				case ssl_v2:
-					populateCipherList(&options, SSLv2_client_method());
 					break;
 				case ssl_v3:
 					populateCipherList(&options, SSLv3_client_method());
