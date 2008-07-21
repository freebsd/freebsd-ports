--- dns.c.old	2003-08-20 14:13:03.000000000 +0900
+++ dns.c	2008-07-21 17:42:39.000000000 +0900
@@ -79,6 +79,13 @@
 # define RES_INSECURE1	0x00000400	/* type 1 security disabled */
 #endif
 
+static int query_domain (char *, int);
+static int make_query (struct dns_stat *, int);
+static int process_query (int);
+static void remove_query (struct query_chain *);
+static void got_answer (struct query_chain *, u_char *, int);
+static struct mx* newmx (char *, int, int, struct domain *, long);
+
 int
 pregetmx(dl)
 struct domain *dl;
@@ -87,7 +94,6 @@
 	char **map_arg;
 	long stime, etime;
 	int n;
-	static int query_domain(), process_query();
 #ifdef INET6
 	SockAddr dsin;	/* dummy */
 #endif
@@ -353,7 +359,6 @@
 int type;
 {
 	struct dns_stat *qrp, **hashp;
-	static int make_query();
 
 	qrp = hash_query_lookup(name, &hashp);
 	if (qrp == NULL) {
@@ -396,7 +401,6 @@
 	u_char buf[MAXPACKET];
 	int n;
 	struct query_chain *qchain;
-	static int process_query();
 
 	switch (type) {
 	  case T_MX:
@@ -591,8 +595,6 @@
 	char nbuf[MAXDNAME+1];
 	struct dns_stat *qrp;
 	int pending;
-	static void got_answer();
-	static void remove_query();
 
 	if (sync == 0 && cnf.cquery_max != 0
 	 && query_chain_count >= cnf.cquery_max)
@@ -1764,7 +1766,6 @@
 #endif
 					{
 						struct mx *gwmxp;
-						static struct mx* newmx();
 
 						if (cnf.debug & DEBUG_DNS)
 						log(LOG_DEBUG, "setting protocol gateway as first MX");
