--- src/ufdbchkport.c.orig	2017-05-03 00:23:20 UTC
+++ src/ufdbchkport.c
@@ -2331,7 +2331,7 @@ int UFDBopenssl_connect( 
    errno = 0;
    ret = SSL_connect( *ssl );
    saved_errno = errno;
-   state = (*ssl)->state;
+   state = SSL_state(*ssl);
    if (ret > 0  &&  state == SSL_ST_OK)
    {
       if ((*ssl)->version == SSL2_VERSION  &&  UFDBglobalHttpsNoSSLv2)
