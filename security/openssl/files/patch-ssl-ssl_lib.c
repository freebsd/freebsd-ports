--- ssl/ssl_lib.c	2006/09/28 11:53:51	1.110.2.19
+++ ssl/ssl_lib.c	2007/10/04 08:01:21	1.110.2.20
@@ -1169,7 +1169,6 @@
 char *SSL_get_shared_ciphers(const SSL *s,char *buf,int len)
 	{
 	char *p;
-	const char *cp;
 	STACK_OF(SSL_CIPHER) *sk;
 	SSL_CIPHER *c;
 	int i;
@@ -1182,20 +1181,21 @@
 	sk=s->session->ciphers;
 	for (i=0; i<sk_SSL_CIPHER_num(sk); i++)
 		{
-		/* Decrement for either the ':' or a '\0' */
-		len--;
+		int n;
+
 		c=sk_SSL_CIPHER_value(sk,i);
-		for (cp=c->name; *cp; )
+		n=strlen(c->name);
+		if (n+1 > len)
 			{
-			if (len-- <= 0)
-				{
-				*p='\0';
-				return(buf);
-				}
-			else
-				*(p++)= *(cp++);
+			if (p != buf)
+				--p;
+			*p='\0';
+			return buf;
 			}
+		strcpy(p,c->name);
+		p+=n;
 		*(p++)=':';
+		len-=n+1;
 		}
 	p[-1]='\0';
 	return(buf);
