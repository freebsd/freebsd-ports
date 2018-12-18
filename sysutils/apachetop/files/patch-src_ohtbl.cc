--- src/ohtbl.cc.orig	2018-08-28 11:24:15 UTC
+++ src/ohtbl.cc
@@ -13,7 +13,7 @@ static int primes[] = {101, 241, 499, 1009, 2003, 3001
 
 int OAHash::getNextPrime(int size)
 {
-	register int *prime;
+	 int *prime;
 	for (prime = &primes[0] ; *prime ; prime++)
 		if (*prime > size)
 			return *prime;
@@ -51,7 +51,7 @@ void OAHash::destroy(void)
 
 void *OAHash::insert(char *key, void *data)
 {
-	register unsigned int p, i;
+	 unsigned int p, i;
 	void *d;
  
 	// Do not exceed the number of positions in the table.
@@ -81,7 +81,7 @@ void *OAHash::insert(char *key, void *data)
 
 int OAHash::remove(char *key)
 {
-	register unsigned int p, i;
+	 unsigned int p, i;
 
 	for (i = 0; i < positions; ++i)
 	{
@@ -108,7 +108,7 @@ int OAHash::remove(char *key)
 
 void *OAHash::lookup(char *key)
 {
-	register unsigned int p, i;
+	 unsigned int p, i;
 
 	for (i = 0; i < positions; ++i)
 	{
