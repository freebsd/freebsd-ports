Backport ab from apache 2.4.x (r1663405)
=============================================================
--- support/ab.c.orig	2014-03-12 11:53:12 UTC
+++ support/ab.c
@@ -156,25 +156,8 @@
 #include "ap_config_auto.h"
 #endif
 
-#if defined(HAVE_SSLC)
-
-/* Libraries for RSA SSL-C */
-#include <rsa.h>
-#include <x509.h>
-#include <pem.h>
-#include <err.h>
-#include <ssl.h>
-#include <r_rand.h>
-#include <sslc.h>
-#define USE_SSL
-#define RSAREF
-#define SK_NUM(x) sk_num(x)
-#define SK_VALUE(x,y) sk_value(x,y)
-typedef STACK X509_STACK_TYPE;
-
-#elif defined(HAVE_OPENSSL)
+#if defined(HAVE_OPENSSL)
 
-/* Libraries on most systems.. */
 #include <openssl/rsa.h>
 #include <openssl/crypto.h>
 #include <openssl/x509.h>
@@ -224,19 +207,25 @@ typedef STACK_OF(X509) X509_STACK_TYPE;
 /* maximum number of requests on a time limited test */
 #define MAX_REQUESTS (INT_MAX > 50000 ? 50000 : INT_MAX)
 
-/* good old state hostname */
-#define STATE_UNCONNECTED 0
-#define STATE_CONNECTING  1     /* TCP connect initiated, but we don't
+/* connection state
+ * don't add enums or rearrange or otherwise change values without
+ * visiting set_conn_state()
+ */
+typedef enum {
+    STATE_UNCONNECTED = 0,
+    STATE_CONNECTING,           /* TCP connect initiated, but we don't
                                  * know if it worked yet
                                  */
-#define STATE_CONNECTED   2     /* we know TCP connect completed */
-#define STATE_READ        3
+    STATE_CONNECTED,            /* we know TCP connect completed */
+    STATE_READ
+} connect_state_e;
 
-#define CBUFFSIZE (2048)
+#define CBUFFSIZE (8192)
 
 struct connection {
     apr_pool_t *ctx;
     apr_socket_t *aprsock;
+    apr_pollfd_t pollfd;
     int state;
     apr_size_t read;            /* amount of bytes read */
     apr_size_t bread;           /* amount of body read */
@@ -267,8 +256,8 @@ struct data {
     apr_interval_time_t time;     /* time for connection */
 };
 
-#define ap_min(a,b) ((a)<(b))?(a):(b)
-#define ap_max(a,b) ((a)>(b))?(a):(b)
+#define ap_min(a,b) (((a)<(b))?(a):(b))
+#define ap_max(a,b) (((a)>(b))?(a):(b))
 #define ap_round_ms(a) ((apr_time_t)((a) + 500)/1000)
 #define ap_double_ms(a) ((double)(a)/1000.0)
 #define MAX_CONCURRENCY 20000
@@ -277,35 +266,38 @@ struct data {
 
 int verbosity = 0;      /* no verbosity by default */
 int recverrok = 0;      /* ok to proceed after socket receive errors */
-int posting = 0;        /* GET by default */
+enum {NO_METH = 0, GET, HEAD, PUT, POST, CUSTOM_METHOD} method = NO_METH;
+const char *method_str[] = {"bug", "GET", "HEAD", "PUT", "POST", ""};
+int send_body = 0;      /* non-zero if sending body with request */
 int requests = 1;       /* Number of requests to make */
 int heartbeatres = 100; /* How often do we say we're alive */
 int concurrency = 1;    /* Number of multiple requests to make */
 int percentile = 1;     /* Show percentile served */
+int nolength = 0;       /* Accept variable document length */
 int confidence = 1;     /* Show confidence estimator and warnings */
 int tlimit = 0;         /* time limit in secs */
 int keepalive = 0;      /* try and do keepalive connections */
 int windowsize = 0;     /* we use the OS default window size */
 char servername[1024];  /* name that server reports */
 char *hostname;         /* host name from URL */
-char *host_field;       /* value of "Host:" header field */
-char *path;             /* path name */
-char postfile[1024];    /* name of file containing post data */
+const char *host_field;       /* value of "Host:" header field */
+const char *path;             /* path name */
 char *postdata;         /* *buffer containing data from postfile */
 apr_size_t postlen = 0; /* length of data to be POSTed */
-char content_type[1024];/* content type to put in POST header */
-char *cookie,           /* optional cookie line */
-     *auth,             /* optional (basic/uuencoded) auhentication */
-     *hdrs;             /* optional arbitrary headers */
+char *content_type = NULL;     /* content type to put in POST header */
+const char *cookie,           /* optional cookie line */
+           *auth,             /* optional (basic/uuencoded) auhentication */
+           *hdrs;             /* optional arbitrary headers */
 apr_port_t port;        /* port number */
-char proxyhost[1024];   /* proxy host name */
+char *proxyhost = NULL; /* proxy host name */
 int proxyport = 0;      /* proxy port */
-char *connecthost;
+const char *connecthost;
+const char *myhost;
 apr_port_t connectport;
-char *gnuplot;          /* GNUplot file */
-char *csvperc;          /* CSV Percentile file */
-char url[1024];
-char * fullurl, * colonhost;
+const char *gnuplot;          /* GNUplot file */
+const char *csvperc;          /* CSV Percentile file */
+const char *fullurl;
+const char *colonhost;
 int isproxy = 0;
 apr_interval_time_t aprtimeout = apr_time_from_sec(30); /* timeout value */
 
@@ -348,7 +340,7 @@ BIO *bio_out,*bio_err;
 apr_time_t start, lasttime, stoptime;
 
 /* global request (and its length) */
-char _request[2048];
+char _request[8192];
 char *request = _request;
 apr_size_t reqlen;
 
@@ -364,6 +356,7 @@ apr_pool_t *cntxt;
 
 apr_pollset_t *readbits;
 
+apr_sockaddr_t *mysa;
 apr_sockaddr_t *destsa;
 
 #ifdef NOT_ASCII
@@ -377,7 +370,7 @@ static void close_connection(struct conn
 
 /* simple little function to write an error string and exit */
 
-static void err(char *s)
+static void err(const char *s)
 {
     fprintf(stderr, "%s\n", s);
     if (done)
@@ -387,7 +380,7 @@ static void err(char *s)
 
 /* simple little function to write an APR error string and exit */
 
-static void apr_err(char *s, apr_status_t rv)
+static void apr_err(const char *s, apr_status_t rv)
 {
     char buf[120];
 
@@ -399,6 +392,87 @@ static void apr_err(char *s, apr_status_
     exit(rv);
 }
 
+static void *xmalloc(size_t size)
+{
+    void *ret = malloc(size);
+    if (ret == NULL) {
+        fprintf(stderr, "Could not allocate memory (%"
+                APR_SIZE_T_FMT" bytes)\n", size);
+        exit(1);
+    }
+    return ret;
+}
+
+static void *xcalloc(size_t num, size_t size)
+{
+    void *ret = calloc(num, size);
+    if (ret == NULL) {
+        fprintf(stderr, "Could not allocate memory (%"
+                APR_SIZE_T_FMT" bytes)\n", size*num);
+        exit(1);
+    }
+    return ret;
+}
+
+static char *xstrdup(const char *s)
+{
+    char *ret = strdup(s);
+    if (ret == NULL) {
+        fprintf(stderr, "Could not allocate memory (%"
+                APR_SIZE_T_FMT " bytes)\n", strlen(s));
+        exit(1);
+    }
+    return ret;
+}
+
+/* pool abort function */
+static int abort_on_oom(int retcode)
+{
+    fprintf(stderr, "Could not allocate memory\n");
+    exit(1);
+    /* not reached */
+    return retcode;
+}
+
+static void set_polled_events(struct connection *c, apr_int16_t new_reqevents)
+{
+    apr_status_t rv;
+
+    if (c->pollfd.reqevents != new_reqevents) {
+        if (c->pollfd.reqevents != 0) {
+            rv = apr_pollset_remove(readbits, &c->pollfd);
+            if (rv != APR_SUCCESS) {
+                apr_err("apr_pollset_remove()", rv);
+            }
+        }
+
+        if (new_reqevents != 0) {
+            c->pollfd.reqevents = new_reqevents;
+            rv = apr_pollset_add(readbits, &c->pollfd);
+            if (rv != APR_SUCCESS) {
+                apr_err("apr_pollset_add()", rv);
+            }
+        }
+    }
+}
+
+static void set_conn_state(struct connection *c, connect_state_e new_state)
+{
+    apr_int16_t events_by_state[] = {
+        0,           /* for STATE_UNCONNECTED */
+        APR_POLLOUT, /* for STATE_CONNECTING */
+        APR_POLLIN,  /* for STATE_CONNECTED; we don't poll in this state,
+                      * so prepare for polling in the following state --
+                      * STATE_READ
+                      */
+        APR_POLLIN   /* for STATE_READ */
+    };
+
+    c->state = new_state;
+
+    set_polled_events(c, events_by_state[new_state]);
+}
+
 /* --------------------------------------------------------- */
 /* write out request to a connection - assumes we can write
  * (small) request out in one go into our new socket buffer
@@ -464,7 +538,6 @@ static int ssl_rand_choosenum(int l, int
 
 static void ssl_rand_seed(void)
 {
-    int nDone = 0;
     int n, l;
     time_t t;
     pid_t pid;
@@ -476,7 +549,6 @@ static void ssl_rand_seed(void)
     t = time(NULL);
     l = sizeof(time_t);
     RAND_seed((unsigned char *)&t, l);
-    nDone += l;
 
     /*
      * seed in the current process id (usually just 4 bytes)
@@ -484,14 +556,12 @@ static void ssl_rand_seed(void)
     pid = getpid();
     l = sizeof(pid_t);
     RAND_seed((unsigned char *)&pid, l);
-    nDone += l;
 
     /*
      * seed in some current state of the run-time stack (128 bytes)
      */
     n = ssl_rand_choosenum(0, sizeof(stackdata)-128-1);
     RAND_seed(stackdata+n, 128);
-    nDone += 128;
 }
 
 static int ssl_print_connection_info(BIO *bio, SSL *ssl)
@@ -514,6 +584,7 @@ static int ssl_print_connection_info(BIO
 static void ssl_print_cert_info(BIO *bio, X509 *cert)
 {
     X509_NAME *dn;
+    EVP_PKEY *pk;
     char buf[1024];
 
     BIO_printf(bio, "Certificate version: %ld\n", X509_get_version(cert)+1);
@@ -525,8 +596,10 @@ static void ssl_print_cert_info(BIO *bio
     ASN1_UTCTIME_print(bio, X509_get_notAfter(cert));
     BIO_printf(bio,"\n");
 
+    pk = X509_get_pubkey(cert);
     BIO_printf(bio,"Public key is %d bits\n",
-               EVP_PKEY_bits(X509_get_pubkey(cert)));
+               EVP_PKEY_bits(pk));
+    EVP_PKEY_free(pk);
 
     dn = X509_get_issuer_name(cert);
     X509_NAME_oneline(dn, buf, sizeof(buf));
@@ -553,7 +626,6 @@ static void ssl_print_info(struct connec
         for (i=1; i<count; i++) {
             cert = (X509 *)SK_VALUE(sk, i);
             ssl_print_cert_info(bio_out, cert);
-            X509_free(cert);
     }
     }
     cert = SSL_get_peer_certificate(c->ssl);
@@ -574,7 +646,6 @@ static void ssl_proceed_handshake(struct
 
     while (do_next) {
         int ret, ecode;
-        apr_pollfd_t new_pollfd;
 
         ret = SSL_do_handshake(c->ssl);
         ecode = SSL_get_error(c->ssl, ret);
@@ -596,7 +667,7 @@ static void ssl_proceed_handshake(struct
                 else
                     pk_bits = 0;  /* Anon DH */
 
-                ssl_info = malloc(128);
+                ssl_info = xmalloc(128);
                 apr_snprintf(ssl_info, 128, "%s,%s,%d,%d",
                              SSL_get_version(c->ssl),
                              SSL_CIPHER_get_name(ci),
@@ -606,11 +677,7 @@ static void ssl_proceed_handshake(struct
             do_next = 0;
             break;
         case SSL_ERROR_WANT_READ:
-            new_pollfd.desc_type = APR_POLL_SOCKET;
-            new_pollfd.reqevents = APR_POLLIN;
-            new_pollfd.desc.s = c->aprsock;
-            new_pollfd.client_data = c;
-            apr_pollset_add(readbits, &new_pollfd);
+            set_polled_events(c, APR_POLLIN);
             do_next = 0;
             break;
         case SSL_ERROR_WANT_WRITE:
@@ -634,6 +701,10 @@ static void ssl_proceed_handshake(struct
 
 static void write_request(struct connection * c)
 {
+    if (started >= requests) {
+        return;
+    }
+
     do {
         apr_time_t tnow;
         apr_size_t l = c->rwrite;
@@ -649,7 +720,7 @@ static void write_request(struct connect
             c->connect = tnow;
             c->rwrote = 0;
             c->rwrite = reqlen;
-            if (posting)
+            if (send_body)
                 c->rwrite += postlen;
         }
         else if (tnow > c->connect + aprtimeout) {
@@ -686,16 +757,9 @@ static void write_request(struct connect
         c->rwrite -= l;
     } while (c->rwrite);
 
-    c->state = STATE_READ;
     c->endwrite = lasttime = apr_time_now();
-    {
-        apr_pollfd_t new_pollfd;
-        new_pollfd.desc_type = APR_POLL_SOCKET;
-        new_pollfd.reqevents = APR_POLLIN;
-        new_pollfd.desc.s = c->aprsock;
-        new_pollfd.client_data = c;
-        apr_pollset_add(readbits, &new_pollfd);
-    }
+    started++;
+    set_conn_state(c, STATE_READ);
 }
 
 /* --------------------------------------------------------- */
@@ -760,7 +824,10 @@ static void output_results(int sig)
 #endif
     printf("\n");
     printf("Document Path:          %s\n", path);
-    printf("Document Length:        %" APR_SIZE_T_FMT " bytes\n", doclen);
+    if (nolength)
+        printf("Document Length:        Variable\n");
+    else
+        printf("Document Length:        %" APR_SIZE_T_FMT " bytes\n", doclen);
     printf("\n");
     printf("Concurrency Level:      %d\n", concurrency);
     printf("Time taken for tests:   %.3f seconds\n", timetaken);
@@ -769,16 +836,16 @@ static void output_results(int sig)
     if (bad)
         printf("   (Connect: %d, Receive: %d, Length: %d, Exceptions: %d)\n",
             err_conn, err_recv, err_length, err_except);
-    printf("Write errors:           %d\n", epipe);
+    if (epipe)
+        printf("Write errors:           %d\n", epipe);
     if (err_response)
         printf("Non-2xx responses:      %d\n", err_response);
     if (keepalive)
         printf("Keep-Alive requests:    %d\n", doneka);
     printf("Total transferred:      %" APR_INT64_T_FMT " bytes\n", totalread);
-    if (posting == 1)
-        printf("Total POSTed:           %" APR_INT64_T_FMT "\n", totalposted);
-    if (posting == 2)
-        printf("Total PUT:              %" APR_INT64_T_FMT "\n", totalposted);
+    if (send_body)
+        printf("Total body sent:        %" APR_INT64_T_FMT "\n",
+               totalposted);
     printf("HTML transferred:       %" APR_INT64_T_FMT " bytes\n", totalbread);
 
     /* avoid divide by zero */
@@ -791,11 +858,11 @@ static void output_results(int sig)
                (double) timetaken * 1000 / done);
         printf("Transfer rate:          %.2f [Kbytes/sec] received\n",
                (double) totalread / 1024 / timetaken);
-        if (posting > 0) {
+        if (send_body) {
             printf("                        %.2f kb/s sent\n",
-               (double) totalposted / timetaken / 1024);
+               (double) totalposted / 1024 / timetaken);
             printf("                        %.2f kb/s total\n",
-               (double) (totalread + totalposted) / timetaken / 1024);
+               (double) (totalread + totalposted) / 1024 / timetaken);
         }
     }
 
@@ -943,9 +1010,8 @@ static void output_results(int sig)
             printf("              min   avg   max\n");
 #define CONF_FMT_STRING "%5" APR_TIME_T_FMT " %5" APR_TIME_T_FMT "%5" APR_TIME_T_FMT "\n"
             printf("Connect:    " CONF_FMT_STRING, mincon, meancon, maxcon);
-            printf("Processing: " CONF_FMT_STRING, mintot - mincon,
-                                                   meantot - meancon,
-                                                   maxtot - maxcon);
+            printf("Processing: " CONF_FMT_STRING, mind, meand, maxd);
+            printf("Waiting:    " CONF_FMT_STRING, minwait, meanwait, maxwait);
             printf("Total:      " CONF_FMT_STRING, mintot, meantot, maxtot);
 #undef CONF_FMT_STRING
         }
@@ -972,7 +1038,7 @@ static void output_results(int sig)
                 exit(1);
             }
             fprintf(out, "" "Percentage served" "," "Time in ms" "\n");
-            for (i = 0; i < 100; i++) {
+            for (i = 0; i <= 100; i++) {
                 double t;
                 if (i == 0)
                     t = ap_double_ms(stats[0].time);
@@ -1033,9 +1099,14 @@ static void output_html_results(void)
     printf("<tr %s><th colspan=2 %s>Document Path:</th>"
        "<td colspan=2 %s>%s</td></tr>\n",
        trstring, tdstring, tdstring, path);
-    printf("<tr %s><th colspan=2 %s>Document Length:</th>"
-       "<td colspan=2 %s>%" APR_SIZE_T_FMT " bytes</td></tr>\n",
-       trstring, tdstring, tdstring, doclen);
+    if (nolength)
+        printf("<tr %s><th colspan=2 %s>Document Length:</th>"
+            "<td colspan=2 %s>Variable</td></tr>\n",
+            trstring, tdstring, tdstring);
+    else
+        printf("<tr %s><th colspan=2 %s>Document Length:</th>"
+            "<td colspan=2 %s>%" APR_SIZE_T_FMT " bytes</td></tr>\n",
+            trstring, tdstring, tdstring, doclen);
     printf("<tr %s><th colspan=2 %s>Concurrency Level:</th>"
        "<td colspan=2 %s>%d</td></tr>\n",
        trstring, tdstring, tdstring, concurrency);
@@ -1062,14 +1133,11 @@ static void output_html_results(void)
     printf("<tr %s><th colspan=2 %s>Total transferred:</th>"
        "<td colspan=2 %s>%" APR_INT64_T_FMT " bytes</td></tr>\n",
        trstring, tdstring, tdstring, totalread);
-    if (posting == 1)
-        printf("<tr %s><th colspan=2 %s>Total POSTed:</th>"
-           "<td colspan=2 %s>%" APR_INT64_T_FMT "</td></tr>\n",
-           trstring, tdstring, tdstring, totalposted);
-    if (posting == 2)
-        printf("<tr %s><th colspan=2 %s>Total PUT:</th>"
+    if (send_body)
+        printf("<tr %s><th colspan=2 %s>Total body sent:</th>"
            "<td colspan=2 %s>%" APR_INT64_T_FMT "</td></tr>\n",
-           trstring, tdstring, tdstring, totalposted);
+           trstring, tdstring,
+           tdstring, totalposted);
     printf("<tr %s><th colspan=2 %s>HTML transferred:</th>"
        "<td colspan=2 %s>%" APR_INT64_T_FMT " bytes</td></tr>\n",
        trstring, tdstring, tdstring, totalbread);
@@ -1078,19 +1146,19 @@ static void output_html_results(void)
     if (timetaken) {
         printf("<tr %s><th colspan=2 %s>Requests per second:</th>"
            "<td colspan=2 %s>%.2f</td></tr>\n",
-           trstring, tdstring, tdstring, (double) done * 1000 / timetaken);
+           trstring, tdstring, tdstring, (double) done / timetaken);
         printf("<tr %s><th colspan=2 %s>Transfer rate:</th>"
            "<td colspan=2 %s>%.2f kb/s received</td></tr>\n",
-           trstring, tdstring, tdstring, (double) totalread / timetaken);
-        if (posting > 0) {
+           trstring, tdstring, tdstring, (double) totalread / 1024 / timetaken);
+        if (send_body) {
             printf("<tr %s><td colspan=2 %s>&nbsp;</td>"
                "<td colspan=2 %s>%.2f kb/s sent</td></tr>\n",
                trstring, tdstring, tdstring,
-               (double) totalposted / timetaken);
+               (double) totalposted / 1024 / timetaken);
             printf("<tr %s><td colspan=2 %s>&nbsp;</td>"
                "<td colspan=2 %s>%.2f kb/s total</td></tr>\n",
                trstring, tdstring, tdstring,
-               (double) (totalread + totalposted) / timetaken);
+               (double) (totalread + totalposted) / 1024 / timetaken);
         }
     }
     {
@@ -1154,7 +1222,7 @@ static void start_connect(struct connect
     apr_status_t rv;
 
     if (!(started < requests))
-    return;
+        return;
 
     c->read = 0;
     c->bread = 0;
@@ -1171,18 +1239,30 @@ static void start_connect(struct connect
                 SOCK_STREAM, 0, c->ctx)) != APR_SUCCESS) {
     apr_err("socket", rv);
     }
+
+    if (myhost) {
+        if ((rv = apr_socket_bind(c->aprsock, mysa)) != APR_SUCCESS) {
+            apr_err("bind", rv);
+        }
+    }
+
+    c->pollfd.desc_type = APR_POLL_SOCKET;
+    c->pollfd.desc.s = c->aprsock;
+    c->pollfd.reqevents = 0;
+    c->pollfd.client_data = c;
+
     if ((rv = apr_socket_opt_set(c->aprsock, APR_SO_NONBLOCK, 1))
          != APR_SUCCESS) {
         apr_err("socket nonblock", rv);
     }
 
     if (windowsize != 0) {
-        rv = apr_socket_opt_set(c->aprsock, APR_SO_SNDBUF, 
+        rv = apr_socket_opt_set(c->aprsock, APR_SO_SNDBUF,
                                 windowsize);
         if (rv != APR_SUCCESS && rv != APR_ENOTIMPL) {
             apr_err("socket send buffer", rv);
         }
-        rv = apr_socket_opt_set(c->aprsock, APR_SO_RCVBUF, 
+        rv = apr_socket_opt_set(c->aprsock, APR_SO_RCVBUF,
                                 windowsize);
         if (rv != APR_SUCCESS && rv != APR_ENOTIMPL) {
             apr_err("socket receive buffer", rv);
@@ -1215,21 +1295,12 @@ static void start_connect(struct connect
 #endif
     if ((rv = apr_socket_connect(c->aprsock, destsa)) != APR_SUCCESS) {
         if (APR_STATUS_IS_EINPROGRESS(rv)) {
-            apr_pollfd_t new_pollfd;
-            c->state = STATE_CONNECTING;
+            set_conn_state(c, STATE_CONNECTING);
             c->rwrite = 0;
-            new_pollfd.desc_type = APR_POLL_SOCKET;
-            new_pollfd.reqevents = APR_POLLOUT;
-            new_pollfd.desc.s = c->aprsock;
-            new_pollfd.client_data = c;
-            apr_pollset_add(readbits, &new_pollfd);
             return;
         }
         else {
-            apr_pollfd_t remove_pollfd;
-            remove_pollfd.desc_type = APR_POLL_SOCKET;
-            remove_pollfd.desc.s = c->aprsock;
-            apr_pollset_remove(readbits, &remove_pollfd);
+            set_conn_state(c, STATE_UNCONNECTED);
             apr_socket_close(c->aprsock);
             err_conn++;
             if (bad++ > 10) {
@@ -1237,15 +1308,14 @@ static void start_connect(struct connect
                    "\nTest aborted after 10 failures\n\n");
                 apr_err("apr_socket_connect()", rv);
             }
-            c->state = STATE_UNCONNECTED;
+
             start_connect(c);
             return;
         }
     }
 
     /* connected first time */
-    c->state = STATE_CONNECTED;
-    started++;
+    set_conn_state(c, STATE_CONNECTED);
 #ifdef USE_SSL
     if (c->ssl) {
         ssl_proceed_handshake(c);
@@ -1274,7 +1344,7 @@ static void close_connection(struct conn
             /* first time here */
             doclen = c->bread;
         }
-        else if (c->bread != doclen) {
+        else if ((c->bread != doclen) && !nolength) {
             bad++;
             err_length++;
         }
@@ -1293,21 +1363,15 @@ static void close_connection(struct conn
         }
     }
 
-    {
-        apr_pollfd_t remove_pollfd;
-        remove_pollfd.desc_type = APR_POLL_SOCKET;
-        remove_pollfd.desc.s = c->aprsock;
-        apr_pollset_remove(readbits, &remove_pollfd);
+    set_conn_state(c, STATE_UNCONNECTED);
 #ifdef USE_SSL
-        if (c->ssl) {
-            SSL_shutdown(c->ssl);
-            SSL_free(c->ssl);
-            c->ssl = NULL;
-        }
-#endif
-        apr_socket_close(c->aprsock);
+    if (c->ssl) {
+        SSL_shutdown(c->ssl);
+        SSL_free(c->ssl);
+        c->ssl = NULL;
     }
-    c->state = STATE_UNCONNECTED;
+#endif
+    apr_socket_close(c->aprsock);
 
     /* connect again */
     start_connect(c);
@@ -1337,11 +1401,21 @@ static void read_connection(struct conne
                 good++;
                 close_connection(c);
             }
+            else if (scode == SSL_ERROR_SYSCALL
+                     && status == 0
+                     && c->read != 0) {
+                /* connection closed, but in violation of the protocol, after
+                 * some data has already been read; this commonly happens, so
+                 * let the length check catch any response errors
+                 */
+                good++;
+                close_connection(c);
+            }
             else if (scode != SSL_ERROR_WANT_WRITE
                      && scode != SSL_ERROR_WANT_READ) {
                 /* some fatal error: */
                 c->read = 0;
-                BIO_printf(bio_err, "SSL read failed - closing connection\n");
+                BIO_printf(bio_err, "SSL read failed (%d) - closing connection\n", scode);
                 ERR_print_errors(bio_err);
                 close_connection(c);
             }
@@ -1425,10 +1499,7 @@ static void read_connection(struct conne
             }
             else {
             /* header is in invalid or too big - close connection */
-                apr_pollfd_t remove_pollfd;
-                remove_pollfd.desc_type = APR_POLL_SOCKET;
-                remove_pollfd.desc.s = c->aprsock;
-                apr_pollset_remove(readbits, &remove_pollfd);
+                set_conn_state(c, STATE_UNCONNECTED);
                 apr_socket_close(c->aprsock);
                 err_response++;
                 if (bad++ > 10) {
@@ -1444,12 +1515,14 @@ static void read_connection(struct conne
                  * this is first time, extract some interesting info
                  */
                 char *p, *q;
+                size_t len = 0;
                 p = strstr(c->cbuff, "Server:");
                 q = servername;
                 if (p) {
                     p += 8;
-                    while (*p > 32)
-                    *q++ = *p++;
+                    /* -1 to not overwrite last '\0' byte */
+                    while (*p > 32 && len++ < sizeof(servername) - 1)
+                        *q++ = *p++;
                 }
                 *q = 0;
             }
@@ -1491,12 +1564,12 @@ static void read_connection(struct conne
                 if (cl) {
                     c->keepalive = 1;
                     /* response to HEAD doesn't have entity body */
-                    c->length = posting >= 0 ? atoi(cl + 16) : 0;
+                    c->length = method != HEAD ? atoi(cl + 16) : 0;
                 }
                 /* The response may not have a Content-Length header */
                 if (!cl) {
                     c->keepalive = 1;
-                    c->length = 0; 
+                    c->length = 0;
                 }
             }
             c->bread += c->cbx - (s + l - c->cbuff) + r - tocopy;
@@ -1517,7 +1590,7 @@ static void read_connection(struct conne
             /* first time here */
             doclen = c->bread;
         }
-        else if (c->bread != doclen) {
+        else if ((c->bread != doclen) && !nolength) {
             bad++;
             err_length++;
         }
@@ -1552,7 +1625,8 @@ static void read_connection(struct conne
 static void test(void)
 {
     apr_time_t stoptime;
-    apr_int16_t rv;
+    apr_int16_t rtnev;
+    apr_status_t rv;
     int i;
     apr_status_t status;
     int snprintf_res = 0;
@@ -1578,11 +1652,16 @@ static void test(void)
     fflush(stdout);
     }
 
-    con = calloc(concurrency, sizeof(struct connection));
+    con = xcalloc(concurrency, sizeof(struct connection));
 
-    stats = calloc(requests, sizeof(struct data));
+    /*
+     * XXX: a way to calculate the stats without requiring O(requests) memory
+     * XXX: would be nice.
+     */
+    stats = xcalloc(requests, sizeof(struct data));
 
-    if ((status = apr_pollset_create(&readbits, concurrency, cntxt, 0)) != APR_SUCCESS) {
+    if ((status = apr_pollset_create(&readbits, concurrency, cntxt,
+                                     APR_POLLSET_NOCOPY)) != APR_SUCCESS) {
         apr_err("apr_pollset_create failed", status);
     }
 
@@ -1612,12 +1691,12 @@ static void test(void)
     }
 
     /* setup request */
-    if (posting <= 0) {
+    if (!send_body) {
         snprintf_res = apr_snprintf(request, sizeof(_request),
             "%s %s HTTP/1.0\r\n"
             "%s" "%s" "%s"
             "%s" "\r\n",
-            (posting == 0) ? "GET" : "HEAD",
+            method_str[method],
             (isproxy) ? fullurl : path,
             keepalive ? "Connection: Keep-Alive\r\n" : "",
             cookie, auth, hdrs);
@@ -1630,32 +1709,28 @@ static void test(void)
             "Content-type: %s\r\n"
             "%s"
             "\r\n",
-            (posting == 1) ? "POST" : "PUT",
+            method_str[method],
             (isproxy) ? fullurl : path,
             keepalive ? "Connection: Keep-Alive\r\n" : "",
             cookie, auth,
             postlen,
-            (content_type[0]) ? content_type : "text/plain", hdrs);
+            (content_type != NULL) ? content_type : "text/plain", hdrs);
     }
     if (snprintf_res >= sizeof(_request)) {
         err("Request too long\n");
     }
 
     if (verbosity >= 2)
-        printf("INFO: %s header == \n---\n%s\n---\n", 
-                (posting == 2) ? "PUT" : "POST", request);
+        printf("INFO: %s header == \n---\n%s\n---\n",
+               method_str[method], request);
 
     reqlen = strlen(request);
 
     /*
-     * Combine headers and (optional) post file into one contineous buffer
+     * Combine headers and (optional) post file into one continuous buffer
      */
-    if (posting >= 1) {
-        char *buff = malloc(postlen + reqlen + 1);
-        if (!buff) {
-            fprintf(stderr, "error creating request buffer: out of memory\n");
-            return;
-        }
+    if (send_body) {
+        char *buff = xmalloc(postlen + reqlen + 1);
         strcpy(buff, request);
         memcpy(buff + reqlen, postdata, postlen);
         request = buff;
@@ -1673,8 +1748,20 @@ static void test(void)
     }
 #endif              /* NOT_ASCII */
 
-    /* This only needs to be done once */
-    if ((rv = apr_sockaddr_info_get(&destsa, connecthost, APR_UNSPEC, connectport, 0, cntxt))
+    if (myhost) {
+        /* This only needs to be done once */
+        if ((rv = apr_sockaddr_info_get(&mysa, myhost, APR_UNSPEC, 0, 0, cntxt)) != APR_SUCCESS) {
+            char buf[120];
+            apr_snprintf(buf, sizeof(buf),
+                         "apr_sockaddr_info_get() for %s", myhost);
+            apr_err(buf, rv);
+        }
+    }
+
+    /* This too */
+    if ((rv = apr_sockaddr_info_get(&destsa, connecthost,
+                                    myhost ? mysa->family : APR_UNSPEC,
+                                    connectport, 0, cntxt))
        != APR_SUCCESS) {
         char buf[120];
         apr_snprintf(buf, sizeof(buf),
@@ -1686,7 +1773,7 @@ static void test(void)
     start = lasttime = apr_time_now();
     stoptime = tlimit ? (start + apr_time_from_sec(tlimit)) : AB_MAX;
 
-#ifdef SIGINT 
+#ifdef SIGINT
     /* Output the results if the user terminates the run early. */
     apr_signal(SIGINT, output_results);
 #endif
@@ -1699,24 +1786,19 @@ static void test(void)
 
     do {
         apr_int32_t n;
-        const apr_pollfd_t *pollresults;
+        const apr_pollfd_t *pollresults, *pollfd;
 
         n = concurrency;
         do {
-        status = apr_pollset_poll(readbits, aprtimeout, &n, &pollresults);
+            status = apr_pollset_poll(readbits, aprtimeout, &n, &pollresults);
         } while (APR_STATUS_IS_EINTR(status));
         if (status != APR_SUCCESS)
-            apr_err("apr_poll", status);
-
-        if (!n) {
-            err("\nServer timed out\n\n");
-        }
+            apr_err("apr_pollset_poll", status);
 
-        for (i = 0; i < n; i++) {
-            const apr_pollfd_t *next_fd = &(pollresults[i]);
+        for (i = 0, pollfd = pollresults; i < n; i++, pollfd++) {
             struct connection *c;
 
-            c = next_fd->client_data;
+            c = pollfd->client_data;
 
             /*
              * If the connection isn't connected how can we check it?
@@ -1724,7 +1806,7 @@ static void test(void)
             if (c->state == STATE_UNCONNECTED)
                 continue;
 
-            rv = next_fd->rtnevents;
+            rtnev = pollfd->rtnevents;
 
 #ifdef USE_SSL
             if (c->state == STATE_CONNECTED && c->ssl && SSL_in_init(c->ssl)) {
@@ -1745,22 +1827,25 @@ static void test(void)
              * connection is done and we loop here endlessly calling
              * apr_poll().
              */
-            if ((rv & APR_POLLIN) || (rv & APR_POLLPRI) || (rv & APR_POLLHUP))
+            if ((rtnev & APR_POLLIN) || (rtnev & APR_POLLPRI) || (rtnev & APR_POLLHUP))
                 read_connection(c);
-            if ((rv & APR_POLLERR) || (rv & APR_POLLNVAL)) {
+            if ((rtnev & APR_POLLERR) || (rtnev & APR_POLLNVAL)) {
                 bad++;
                 err_except++;
-                start_connect(c);
+                /* avoid apr_poll/EINPROGRESS loop on HP-UX, let recv discover ECONNREFUSED */
+                if (c->state == STATE_CONNECTING) {
+                    read_connection(c);
+                }
+                else {
+                    start_connect(c);
+                }
                 continue;
             }
-            if (rv & APR_POLLOUT) {
+            if (rtnev & APR_POLLOUT) {
                 if (c->state == STATE_CONNECTING) {
-                    apr_pollfd_t remove_pollfd;
                     rv = apr_socket_connect(c->aprsock, destsa);
-                    remove_pollfd.desc_type = APR_POLL_SOCKET;
-                    remove_pollfd.desc.s = c->aprsock;
-                    apr_pollset_remove(readbits, &remove_pollfd);
                     if (rv != APR_SUCCESS) {
+                        set_conn_state(c, STATE_UNCONNECTED);
                         apr_socket_close(c->aprsock);
                         err_conn++;
                         if (bad++ > 10) {
@@ -1768,13 +1853,11 @@ static void test(void)
                                     "\nTest aborted after 10 failures\n\n");
                             apr_err("apr_socket_connect()", rv);
                         }
-                        c->state = STATE_UNCONNECTED;
                         start_connect(c);
                         continue;
                     }
                     else {
-                        c->state = STATE_CONNECTED;
-                        started++;
+                        set_conn_state(c, STATE_CONNECTED);
 #ifdef USE_SSL
                         if (c->ssl)
                             ssl_proceed_handshake(c);
@@ -1787,25 +1870,9 @@ static void test(void)
                     write_request(c);
                 }
             }
-
-            /*
-             * When using a select based poll every time we check the bits
-             * are reset. In 1.3's ab we copied the FD_SET's each time
-             * through, but here we're going to check the state and if the
-             * connection is in STATE_READ or STATE_CONNECTING we'll add the
-             * socket back in as APR_POLLIN.
-             */
-                if (c->state == STATE_READ) {
-                    apr_pollfd_t new_pollfd;
-                    new_pollfd.desc_type = APR_POLL_SOCKET;
-                    new_pollfd.reqevents = APR_POLLIN;
-                    new_pollfd.desc.s = c->aprsock;
-                    new_pollfd.client_data = c;
-                    apr_pollset_add(readbits, &new_pollfd);
-                }
         }
     } while (lasttime < stoptime && done < requests);
-    
+
     if (heartbeatres)
         fprintf(stderr, "Finished %d requests\n", done);
     else
@@ -1823,14 +1890,14 @@ static void test(void)
 static void copyright(void)
 {
     if (!use_html) {
-        printf("This is ApacheBench, Version %s\n", AP_AB_BASEREVISION " <$Revision: 655654 $>");
+        printf("This is ApacheBench, Version %s\n", AP_AB_BASEREVISION " <$Revision: 1706008 $>");
         printf("Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/\n");
         printf("Licensed to The Apache Software Foundation, http://www.apache.org/\n");
         printf("\n");
     }
     else {
         printf("<p>\n");
-        printf(" This is ApacheBench, Version %s <i>&lt;%s&gt;</i><br>\n", AP_AB_BASEREVISION, "$Revision: 655654 $");
+        printf(" This is ApacheBench, Version %s <i>&lt;%s&gt;</i><br>\n", AP_AB_BASEREVISION, "$Revision: 1706008 $");
         printf(" Copyright 1996 Adam Twiss, Zeus Technology Ltd, http://www.zeustech.net/<br>\n");
         printf(" Licensed to The Apache Software Foundation, http://www.apache.org/<br>\n");
         printf("</p>\n<p>\n");
@@ -1849,12 +1916,16 @@ static void usage(const char *progname)
  */
     fprintf(stderr, "Options are:\n");
     fprintf(stderr, "    -n requests     Number of requests to perform\n");
-    fprintf(stderr, "    -c concurrency  Number of multiple requests to make\n");
-    fprintf(stderr, "    -t timelimit    Seconds to max. wait for responses\n");
+    fprintf(stderr, "    -c concurrency  Number of multiple requests to make at a time\n");
+    fprintf(stderr, "    -t timelimit    Seconds to max. to spend on benchmarking\n");
+    fprintf(stderr, "                    This implies -n 50000\n");
+    fprintf(stderr, "    -s timeout      Seconds to max. wait for each response\n");
+    fprintf(stderr, "                    Default is 30 seconds\n");
     fprintf(stderr, "    -b windowsize   Size of TCP send/receive buffer, in bytes\n");
+    fprintf(stderr, "    -B address      Address to bind to when making outgoing connections\n");
     fprintf(stderr, "    -p postfile     File containing data to POST. Remember also to set -T\n");
     fprintf(stderr, "    -u putfile      File containing data to PUT. Remember also to set -T\n");
-    fprintf(stderr, "    -T content-type Content-type header for POSTing, eg.\n");
+    fprintf(stderr, "    -T content-type Content-type header to use for POST/PUT data, eg.\n");
     fprintf(stderr, "                    'application/x-www-form-urlencoded'\n");
     fprintf(stderr, "                    Default is 'text/plain'\n");
     fprintf(stderr, "    -v verbosity    How much troubleshooting info to print\n");
@@ -1863,7 +1934,7 @@ static void usage(const char *progname)
     fprintf(stderr, "    -x attributes   String to insert as table attributes\n");
     fprintf(stderr, "    -y attributes   String to insert as tr attributes\n");
     fprintf(stderr, "    -z attributes   String to insert as td or th attributes\n");
-    fprintf(stderr, "    -C attribute    Add cookie, eg. 'Apache=1234. (repeatable)\n");
+    fprintf(stderr, "    -C attribute    Add cookie, eg. 'Apache=1234'. (repeatable)\n");
     fprintf(stderr, "    -H attribute    Add Arbitrary header line, eg. 'Accept-Encoding: gzip'\n");
     fprintf(stderr, "                    Inserted after all normal header lines. (repeatable)\n");
     fprintf(stderr, "    -A attribute    Add Basic WWW Authentication, the attributes\n");
@@ -1875,9 +1946,12 @@ static void usage(const char *progname)
     fprintf(stderr, "    -k              Use HTTP KeepAlive feature\n");
     fprintf(stderr, "    -d              Do not show percentiles served table.\n");
     fprintf(stderr, "    -S              Do not show confidence estimators and warnings.\n");
+    fprintf(stderr, "    -q              Do not show progress when doing more than 150 requests\n");
+    fprintf(stderr, "    -l              Accept variable document length (use this for dynamic pages)\n");
     fprintf(stderr, "    -g filename     Output collected data to gnuplot format file.\n");
     fprintf(stderr, "    -e filename     Output CSV file with percentages served\n");
     fprintf(stderr, "    -r              Don't exit on socket receive errors.\n");
+    fprintf(stderr, "    -m method       Method name\n");
     fprintf(stderr, "    -h              Display usage information (this message)\n");
 #ifdef USE_SSL
 
@@ -1887,6 +1961,12 @@ static void usage(const char *progname)
 #define SSL2_HELP_MSG ""
 #endif
 
+#ifndef OPENSSL_NO_SSL3
+#define SSL3_HELP_MSG "SSL3, "
+#else
+#define SSL3_HELP_MSG ""
+#endif
+
 #ifdef HAVE_TLSV1_X
 #define TLS1_X_HELP_MSG ", TLS1.1, TLS1.2"
 #else
@@ -1894,8 +1974,8 @@ static void usage(const char *progname)
 #endif
 
     fprintf(stderr, "    -Z ciphersuite  Specify SSL/TLS cipher suite (See openssl ciphers)\n");
-    fprintf(stderr, "    -f protocol     Specify SSL/TLS protocol\n"); 
-    fprintf(stderr, "                    (" SSL2_HELP_MSG "SSL3, TLS1" TLS1_X_HELP_MSG " or ALL)\n");
+    fprintf(stderr, "    -f protocol     Specify SSL/TLS protocol\n");
+    fprintf(stderr, "                    (" SSL2_HELP_MSG SSL3_HELP_MSG "TLS1" TLS1_X_HELP_MSG " or ALL)\n");
 #endif
     exit(EINVAL);
 }
@@ -1904,7 +1984,7 @@ static void usage(const char *progname)
 
 /* split URL into parts */
 
-static int parse_url(char *url)
+static int parse_url(const char *url)
 {
     char *cp;
     char *h;
@@ -1935,9 +2015,7 @@ static int parse_url(char *url)
 
     if ((cp = strchr(url, '/')) == NULL)
         return 1;
-    h = apr_palloc(cntxt, cp - url + 1);
-    memcpy(h, url, cp - url);
-    h[cp - url] = '\0';
+    h = apr_pstrmemdup(cntxt, url, cp - url);
     rv = apr_parse_addr_port(&hostname, &scope_id, &port, h, cntxt);
     if (rv != APR_SUCCESS || !hostname || scope_id) {
         return 1;
@@ -1974,9 +2052,9 @@ static int parse_url(char *url)
 
 /* ------------------------------------------------------- */
 
-/* read data to POST from file, save contents and length */
+/* read data to POST/PUT from file, save contents and length */
 
-static int open_postfile(const char *pfile)
+static apr_status_t open_postfile(const char *pfile)
 {
     apr_file_t *postfd;
     apr_finfo_t finfo;
@@ -1997,11 +2075,7 @@ static int open_postfile(const char *pfi
         return rv;
     }
     postlen = (apr_size_t)finfo.size;
-    postdata = malloc(postlen);
-    if (!postdata) {
-        fprintf(stderr, "ab: Could not allocate POST data buffer\n");
-        return APR_ENOMEM;
-    }
+    postdata = xmalloc(postlen);
     rv = apr_file_read_full(postfd, postdata, postlen, NULL);
     if (rv != APR_SUCCESS) {
         fprintf(stderr, "ab: Could not read POST data file: %s\n",
@@ -2009,7 +2083,7 @@ static int open_postfile(const char *pfi
         return rv;
     }
     apr_file_close(postfd);
-    return 0;
+    return APR_SUCCESS;
 }
 
 /* ------------------------------------------------------- */
@@ -2017,11 +2091,11 @@ static int open_postfile(const char *pfi
 /* sort out command-line args and call test */
 int main(int argc, const char * const argv[])
 {
-    int r, l;
+    int l;
     char tmp[1024];
     apr_status_t status;
     apr_getopt_t *opt;
-    const char *optarg;
+    const char *opt_arg;
     char c;
 #ifdef USE_SSL
     AB_SSL_METHOD_CONST SSL_METHOD *meth = SSLv23_client_method();
@@ -2033,12 +2107,13 @@ int main(int argc, const char * const ar
     tdstring = "bgcolor=white";
     cookie = "";
     auth = "";
-    proxyhost[0] = '\0';
+    proxyhost = "";
     hdrs = "";
 
     apr_app_initialize(&argc, &argv, NULL);
     atexit(apr_terminate);
     apr_pool_create(&cntxt, NULL);
+    apr_pool_abort_set(abort_on_oom, cntxt);
 
 #ifdef NOT_ASCII
     status = apr_xlate_open(&to_ascii, "ISO-8859-1", APR_DEFAULT_CHARSET, cntxt);
@@ -2058,15 +2133,17 @@ int main(int argc, const char * const ar
     }
 #endif
 
+    myhost = NULL; /* 0.0.0.0 or :: */
+
     apr_getopt_init(&opt, cntxt, argc, argv);
-    while ((status = apr_getopt(opt, "n:c:t:b:T:p:u:v:rkVhwix:y:z:C:H:P:A:g:X:de:Sq"
+    while ((status = apr_getopt(opt, "n:c:t:s:b:T:p:u:v:lrkVhwix:y:z:C:H:P:A:g:X:de:SqB:m:"
 #ifdef USE_SSL
             "Z:f:"
 #endif
-            ,&c, &optarg)) == APR_SUCCESS) {
+            ,&c, &opt_arg)) == APR_SUCCESS) {
         switch (c) {
             case 'n':
-                requests = atoi(optarg);
+                requests = atoi(opt_arg);
                 if (requests <= 0) {
                     err("Invalid number of requests\n");
                 }
@@ -2078,76 +2155,80 @@ int main(int argc, const char * const ar
                 heartbeatres = 0;
                 break;
             case 'c':
-                concurrency = atoi(optarg);
+                concurrency = atoi(opt_arg);
                 break;
             case 'b':
-                windowsize = atoi(optarg);
+                windowsize = atoi(opt_arg);
                 break;
             case 'i':
-                if (posting > 0)
-                err("Cannot mix POST/PUT and HEAD\n");
-                posting = -1;
+                if (method != NO_METH)
+                    err("Cannot mix HEAD with other methods\n");
+                method = HEAD;
                 break;
             case 'g':
-                gnuplot = strdup(optarg);
+                gnuplot = xstrdup(opt_arg);
                 break;
             case 'd':
                 percentile = 0;
                 break;
             case 'e':
-                csvperc = strdup(optarg);
+                csvperc = xstrdup(opt_arg);
                 break;
             case 'S':
                 confidence = 0;
                 break;
+            case 's':
+                aprtimeout = apr_time_from_sec(atoi(opt_arg)); /* timeout value */
+                break;
             case 'p':
-                if (posting != 0)
-                    err("Cannot mix POST and HEAD\n");
-                if (0 == (r = open_postfile(optarg))) {
-                    posting = 1;
-                }
-                else if (postdata) {
-                    exit(r);
+                if (method != NO_METH)
+                    err("Cannot mix POST with other methods\n");
+                if (open_postfile(opt_arg) != APR_SUCCESS) {
+                    exit(1);
                 }
+                method = POST;
+                send_body = 1;
                 break;
             case 'u':
-                if (posting != 0)
-                    err("Cannot mix PUT and HEAD\n");
-                if (0 == (r = open_postfile(optarg))) {
-                    posting = 2;
-                }
-                else if (postdata) {
-                    exit(r);
+                if (method != NO_METH)
+                    err("Cannot mix PUT with other methods\n");
+                if (open_postfile(opt_arg) != APR_SUCCESS) {
+                    exit(1);
                 }
+                method = PUT;
+                send_body = 1;
+                break;
+            case 'l':
+                nolength = 1;
                 break;
             case 'r':
                 recverrok = 1;
                 break;
             case 'v':
-                verbosity = atoi(optarg);
+                verbosity = atoi(opt_arg);
                 break;
             case 't':
-                tlimit = atoi(optarg);
+                tlimit = atoi(opt_arg);
                 requests = MAX_REQUESTS;    /* need to size data array on
                                              * something */
                 break;
             case 'T':
-                strcpy(content_type, optarg);
+                content_type = apr_pstrdup(cntxt, opt_arg);
                 break;
             case 'C':
-                cookie = apr_pstrcat(cntxt, "Cookie: ", optarg, "\r\n", NULL);
+                cookie = apr_pstrcat(cntxt, "Cookie: ", opt_arg, "\r\n", NULL);
                 break;
             case 'A':
                 /*
                  * assume username passwd already to be in colon separated form.
                  * Ready to be uu-encoded.
                  */
-                while (apr_isspace(*optarg))
-                    optarg++;
-                if (apr_base64_encode_len(strlen(optarg)) > sizeof(tmp)) {
+                while (apr_isspace(*opt_arg))
+                    opt_arg++;
+                if (apr_base64_encode_len(strlen(opt_arg)) > sizeof(tmp)) {
                     err("Authentication credentials too long\n");
                 }
-                l = apr_base64_encode(tmp, optarg, strlen(optarg));
+                l = apr_base64_encode(tmp, opt_arg, strlen(opt_arg));
                 tmp[l] = '\0';
 
                 auth = apr_pstrcat(cntxt, auth, "Authorization: Basic ", tmp,
@@ -2157,27 +2238,27 @@ int main(int argc, const char * const ar
                 /*
                  * assume username passwd already to be in colon separated form.
                  */
-                while (apr_isspace(*optarg))
-                optarg++;
-                if (apr_base64_encode_len(strlen(optarg)) > sizeof(tmp)) {
+                while (apr_isspace(*opt_arg))
+                opt_arg++;
+                if (apr_base64_encode_len(strlen(opt_arg)) > sizeof(tmp)) {
                     err("Proxy credentials too long\n");
                 }
-                l = apr_base64_encode(tmp, optarg, strlen(optarg));
+                l = apr_base64_encode(tmp, opt_arg, strlen(opt_arg));
                 tmp[l] = '\0';
 
                 auth = apr_pstrcat(cntxt, auth, "Proxy-Authorization: Basic ",
                                        tmp, "\r\n", NULL);
                 break;
             case 'H':
-                hdrs = apr_pstrcat(cntxt, hdrs, optarg, "\r\n", NULL);
+                hdrs = apr_pstrcat(cntxt, hdrs, opt_arg, "\r\n", NULL);
                 /*
                  * allow override of some of the common headers that ab adds
                  */
-                if (strncasecmp(optarg, "Host:", 5) == 0) {
+                if (strncasecmp(opt_arg, "Host:", 5) == 0) {
                     opt_host = 1;
-                } else if (strncasecmp(optarg, "Accept:", 7) == 0) {
+                } else if (strncasecmp(opt_arg, "Accept:", 7) == 0) {
                     opt_accept = 1;
-                } else if (strncasecmp(optarg, "User-Agent:", 11) == 0) {
+                } else if (strncasecmp(opt_arg, "User-Agent:", 11) == 0) {
                     opt_useragent = 1;
                 }
                 break;
@@ -2190,7 +2271,7 @@ int main(int argc, const char * const ar
                  */
             case 'x':
                 use_html = 1;
-                tablestring = optarg;
+                tablestring = opt_arg;
                 break;
             case 'X':
                 {
@@ -2198,22 +2279,22 @@ int main(int argc, const char * const ar
                     /*
                      * assume proxy-name[:port]
                      */
-                    if ((p = strchr(optarg, ':'))) {
+                    if ((p = strchr(opt_arg, ':'))) {
                         *p = '\0';
                         p++;
                         proxyport = atoi(p);
                     }
-                    strcpy(proxyhost, optarg);
+                    proxyhost = apr_pstrdup(cntxt, opt_arg);
                     isproxy = 1;
                 }
                 break;
             case 'y':
                 use_html = 1;
-                trstring = optarg;
+                trstring = opt_arg;
                 break;
             case 'z':
                 use_html = 1;
-                tdstring = optarg;
+                tdstring = opt_arg;
                 break;
             case 'h':
                 usage(argv[0]);
@@ -2221,26 +2302,35 @@ int main(int argc, const char * const ar
             case 'V':
                 copyright();
                 return 0;
+            case 'B':
+                myhost = apr_pstrdup(cntxt, opt_arg);
+                break;
 #ifdef USE_SSL
             case 'Z':
-                ssl_cipher = strdup(optarg);
+                ssl_cipher = strdup(opt_arg);
+                break;
+            case 'm':
+                method = CUSTOM_METHOD;
+                method_str[CUSTOM_METHOD] = strdup(opt_arg);
                 break;
             case 'f':
-                if (strncasecmp(optarg, "ALL", 3) == 0) {
+                if (strncasecmp(opt_arg, "ALL", 3) == 0) {
                     meth = SSLv23_client_method();
 #ifndef OPENSSL_NO_SSL2
-                } else if (strncasecmp(optarg, "SSL2", 4) == 0) {
+                } else if (strncasecmp(opt_arg, "SSL2", 4) == 0) {
                     meth = SSLv2_client_method();
 #endif
-                } else if (strncasecmp(optarg, "SSL3", 4) == 0) {
+#ifndef OPENSSL_NO_SSL3
+                } else if (strncasecmp(opt_arg, "SSL3", 4) == 0) {
                     meth = SSLv3_client_method();
+#endif
 #ifdef HAVE_TLSV1_X
-                } else if (strncasecmp(optarg, "TLS1.1", 6) == 0) {
+                } else if (strncasecmp(opt_arg, "TLS1.1", 6) == 0) {
                     meth = TLSv1_1_client_method();
-                } else if (strncasecmp(optarg, "TLS1.2", 6) == 0) {
+                } else if (strncasecmp(opt_arg, "TLS1.2", 6) == 0) {
                     meth = TLSv1_2_client_method();
 #endif
-                } else if (strncasecmp(optarg, "TLS1", 4) == 0) {
+                } else if (strncasecmp(opt_arg, "TLS1", 4) == 0) {
                     meth = TLSv1_client_method();
                 }
                 break;
@@ -2253,6 +2343,10 @@ int main(int argc, const char * const ar
         usage(argv[0]);
     }
 
+    if (method == NO_METH) {
+        method = GET;
+    }
+
     if (parse_url(apr_pstrdup(cntxt, opt->argv[opt->ind++]))) {
         fprintf(stderr, "%s: invalid URL\n", argv[0]);
         usage(argv[0]);
@@ -2296,6 +2390,10 @@ int main(int argc, const char * const ar
         exit(1);
     }
     SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL);
+#ifdef SSL_MODE_RELEASE_BUFFERS
+    /* Keep memory usage as low as possible */
+    SSL_CTX_set_mode (ssl_ctx, SSL_MODE_RELEASE_BUFFERS);
+#endif
     if (ssl_cipher != NULL) {
         if (!SSL_CTX_set_cipher_list(ssl_ctx, ssl_cipher)) {
             fprintf(stderr, "error setting cipher list [%s]\n", ssl_cipher);
