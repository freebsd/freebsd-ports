Index: Curl.xs
===================================================================
RCS file: /home/cvs/ringlet/perl/contrib/net/WWW-Curl/Curl.xs,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -r1.1.1.1 -r1.2
--- Curl.xs	20 Apr 2004 10:55:02 -0000	1.1.1.1
+++ Curl.xs	20 Apr 2004 11:17:25 -0000	1.2
@@ -66,6 +66,12 @@
 
 } perl_curl_easy;
 
+#if LIBCURL_VERSION_NUM >= 0x070b01
+typedef struct {
+    struct curl_httppost * post;
+    struct curl_httppost * last;
+} perl_curl_form;
+#else
 #if LIBCURL_VERSION_NUM >= 0x070900
 typedef struct {
     struct HttpPost * post;
@@ -77,6 +83,7 @@
     void * last;
 } perl_curl_form;
 #endif
+#endif
 
 /* switch from curl option codes to the relevant callback index */
 static perl_curl_easy_callback_code callback_index(int option) {
@@ -101,9 +108,11 @@
 	    return CALLBACK_PROGRESS;
 	    break;
 
+#if (LIBCURL_VERSION_NUM<0x070b01)
 	case CURLOPT_PASSWDFUNCTION:
 	case CURLOPT_PASSWDDATA:
 	    return CALLBACK_PASSWD;
+#endif
 	    break;
     }
     croak("Bad callback index requested\n");
@@ -617,7 +626,9 @@
 	case CURLOPT_INFILE:
 	case CURLOPT_WRITEHEADER:
 	case CURLOPT_PROGRESSDATA:
+#if (LIBCURL_VERSION_NUM<0x070b01)
 	case CURLOPT_PASSWDDATA:
+#endif
 	    perl_curl_easy_register_callback(self,&(self->callback_ctx[callback_index(option)]),value);
 	    break;
 
@@ -626,7 +637,9 @@
 	case CURLOPT_READFUNCTION:
         case CURLOPT_HEADERFUNCTION:
 	case CURLOPT_PROGRESSFUNCTION:
+#if (LIBCURL_VERSION_NUM<0x070b01)
 	case CURLOPT_PASSWDFUNCTION:
+#endif
 	    perl_curl_easy_register_callback(self,&(self->callback[callback_index(option)]),value);
 	    break;
 
