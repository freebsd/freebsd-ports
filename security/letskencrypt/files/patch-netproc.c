--- netproc.c.orig	2016-07-24 05:54:33 UTC
+++ netproc.c
@@ -31,8 +31,6 @@
 
 #define URL_REAL_CA "https://acme-v01.api.letsencrypt.org/directory"
 #define URL_STAGE_CA "https://acme-staging.api.letsencrypt.org/directory"
-#define URL_LICENSE "https://letsencrypt.org" \
-		    "/documents/LE-SA-v1.0.1-July-27-2015.pdf"
 
 #define	RETRY_DELAY 5
 #define RETRY_MAX 10
@@ -333,7 +331,8 @@ sreq(struct conn *c, const char *addr, c
  * Returns non-zero on success.
  */
 static int
-donewreg(struct conn *c, const struct capaths *p)
+donewreg(struct conn *c, const char *agreement, 
+	const struct capaths *p)
 {
 	int		 rc;
 	char		*req;
@@ -342,7 +341,7 @@ donewreg(struct conn *c, const struct ca
 	rc = 0;
 	dodbg("%s: new-reg", p->newreg);
 
-	if (NULL == (req = json_fmt_newreg(URL_LICENSE)))
+	if (NULL == (req = json_fmt_newreg(agreement)))
 		warnx("json_fmt_newreg");
 	else if ((lc = sreq(c, p->newreg, req)) < 0)
 		warnx("%s: bad comm", p->newreg);
@@ -585,7 +584,7 @@ dofullchain(struct conn *c, const char *
 int
 netproc(int kfd, int afd, int Cfd, int cfd, int dfd, int rfd,
 	int newacct, int revoke, int staging, 
-	const char *const *alts, size_t altsz)
+	const char *const *alts, size_t altsz, const char *agreement)
 {
 	int		 rc;
 	size_t		 i;
@@ -690,7 +689,7 @@ netproc(int kfd, int afd, int Cfd, int c
 
 	/* If new, register with the CA server. */
 
-	if (newacct && ! donewreg(&c, &paths))
+	if (newacct && ! donewreg(&c, agreement, &paths))
 		goto out;
 
 	/* Pre-authorise all domains with CA server. */
