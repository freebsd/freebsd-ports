--- sslscan.c.orig	2009-09-01 14:35:59.000000000 +0200
+++ sslscan.c	2015-03-07 23:26:34.286277205 +0100
@@ -41,6 +41,7 @@
 #include <openssl/pkcs12.h>
 #include <openssl/x509.h>
 #include <openssl/x509v3.h>
+#include <netinet/in.h>
 
 // Defines...
 #define false 0
@@ -563,6 +564,7 @@
 					}
 					if (options->xmlOutput != 0)
 						fprintf(options->xmlOutput, " sslversion=\"");
+#ifndef OPENSSL_NO_SSL2
 					if (sslCipherPointer->sslMethod == SSLv2_client_method())
 					{
 						if (options->xmlOutput != 0)
@@ -571,8 +573,11 @@
 							printf("SSLv2 || ");
 						else
 							printf("SSLv2  ");
-					}
-					else if (sslCipherPointer->sslMethod == SSLv3_client_method())
+					} 
+					else
+#endif
+#ifndef OPENSSL_NO_SSL3
+					if (sslCipherPointer->sslMethod == SSLv3_client_method())
 					{
 						if (options->xmlOutput != 0)
 							fprintf(options->xmlOutput, "SSLv3\" bits=\"");
@@ -582,6 +587,7 @@
 							printf("SSLv3  ");
 					}
 					else
+#endif
 					{
 						if (options->xmlOutput != 0)
 							fprintf(options->xmlOutput, "TLSv1\" bits=\"");
@@ -688,6 +694,7 @@
 						cipherStatus = SSL_connect(ssl);
 						if (cipherStatus == 1)
 						{
+#ifndef OPENSSL_NO_SSL2
 							if (sslMethod == SSLv2_client_method())
 							{
 								if (options->xmlOutput != 0)
@@ -697,7 +704,10 @@
 								else
 									printf("    SSLv2  ");
 							}
-							else if (sslMethod == SSLv3_client_method())
+							else 
+#endif
+#ifndef OPENSSL_NO_SSL3
+							if (sslMethod == SSLv3_client_method())
 							{
 								if (options->xmlOutput != 0)
 									fprintf(options->xmlOutput, "  <defaultcipher sslversion=\"SSLv3\" bits=\"");
@@ -707,6 +717,7 @@
 									printf("    SSLv3  ");
 							}
 							else
+#endif
 							{
 								if (options->xmlOutput != 0)
 									fprintf(options->xmlOutput, "  <defaultcipher sslversion=\"TLSv1\" bits=\"");
@@ -1192,18 +1203,26 @@
 		switch (options->sslVersion)
 		{
 			case ssl_all:
+#ifndef OPENSSL_NO_SSL2
 				status = defaultCipher(options, SSLv2_client_method());
 				if (status != false)
+#endif
+#ifndef OPENSSL_NO_SSL3
 					status = defaultCipher(options, SSLv3_client_method());
 				if (status != false)
+#endif
 					status = defaultCipher(options, TLSv1_client_method());
 				break;
+#ifndef OPENSSL_NO_SSL2
 			case ssl_v2:
 				status = defaultCipher(options, SSLv2_client_method());
 				break;
+#endif
+#ifndef OPENSSL_NO_SSL3
 			case ssl_v3:
 				status = defaultCipher(options, SSLv3_client_method());
 				break;
+#endif
 			case tls_v1:
 				status = defaultCipher(options, TLSv1_client_method());
 				break;
@@ -1415,16 +1434,24 @@
 			switch (options.sslVersion)
 			{
 				case ssl_all:
+#ifndef OPENSSL_NO_SSL2
 					populateCipherList(&options, SSLv2_client_method());
+#endif
+#ifndef OPENSSL_NO_SSL3
 					populateCipherList(&options, SSLv3_client_method());
+#endif
 					populateCipherList(&options, TLSv1_client_method());
 					break;
+#ifndef OPENSSL_NO_SSL2
 				case ssl_v2:
 					populateCipherList(&options, SSLv2_client_method());
 					break;
+#endif
+#ifndef OPENSSL_NO_SSL3
 				case ssl_v3:
 					populateCipherList(&options, SSLv3_client_method());
 					break;
+#endif
 				case tls_v1:
 					populateCipherList(&options, TLSv1_client_method());
 					break;
