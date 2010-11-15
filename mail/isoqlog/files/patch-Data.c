--- isoqlog/Data.c.orig	2010-08-09 16:54:25.000000000 +0200
+++ isoqlog/Data.c	2010-08-09 17:00:37.000000000 +0200
@@ -173,34 +173,35 @@
 
 int addUserToSortTab(user *usr)
 {
-	int *u;
+	user* *u;
 
 	if (SortDomain.allusers == NULL) { /* first time */
-		SortDomain.allusers = (int *)malloc(NVINIT * sizeof(int *));
+		SortDomain.allusers = malloc(NVINIT * sizeof(user**));
 		if (SortDomain.allusers == NULL)
 			return -1;
 		SortDomain.max = NVINIT;
 		SortDomain.nval = 0;
 	} else
 	if (SortDomain.nval >= SortDomain.max) { /* growing....*/
-		u = (int *)realloc(SortDomain.allusers,
-				(NVGROW * SortDomain.max) * sizeof(int *));
+		u = realloc(SortDomain.allusers,
+				(NVGROW * SortDomain.max) * sizeof(user**));
 		if (u == NULL)
 			return -1;
 		SortDomain.max *= NVGROW;
 		SortDomain.allusers = u;
 	}
-	SortDomain.allusers[SortDomain.nval] = (int)usr;
+	SortDomain.allusers[SortDomain.nval] = usr;
 	return SortDomain.nval++;
 }
 
 
 void sortDomainUsersFrom(char *domain) 
 {
-	int tmpnval, i, j, max, tmp;
+	int tmpnval, i, j, max;
 	struct domain *domainptr;
 	struct user *sym;
 	struct user *tmp1, *tmp2;
+	user* tmp;
 
 	tmpnval = -1;
 	for (i = 0; i < DomainsTab.nval; i++) 
@@ -233,10 +234,11 @@
 
 void sortDomainUsersTo(char *domain) 
 {
-	int tmpnval, i, j, max, tmp;
+	int tmpnval, i, j, max;
 	struct domain *domainptr;
 	struct user *sym;
 	struct user *tmp1, *tmp2;
+	user* tmp;
 
 	tmpnval = -1;
 	for (i = 0; i < DomainsTab.nval; i++) 
@@ -268,10 +270,11 @@
 
 void sortDomainUsersTotal(char *domain) 
 {
-	int tmpnval, i, j, max, tmp;
+	int tmpnval, i, j, max;
 	struct domain *domainptr;
 	struct user *sym;
 	struct user *tmp1, *tmp2;
+	user * tmp;
 
 	tmpnval = -1;
 	for (i = 0; i < DomainsTab.nval; i++) 
@@ -307,10 +310,11 @@
 
 void sortDomainUsersByte(char *domain) 
 {
-	int tmpnval, i, j, max, tmp;
+	int tmpnval, i, j, max;
 	struct domain *domainptr;
 	struct user *sym;
 	struct user *tmp1, *tmp2;
+	user *tmp;
 
 	tmpnval = -1;
 	for (i = 0; i < DomainsTab.nval; i++) 
@@ -345,7 +349,7 @@
 {
 	int i, j, max;
 	globuser *sym;
-	int tmp;
+	user *tmp;
 	user *tmp1;
 	user *tmp2;
 
@@ -373,7 +377,7 @@
 {
 	int i, j, max;
 	globuser *sym;
-	int tmp;
+	user *tmp;
 	user *tmp1;
 	user *tmp2;
 
@@ -402,7 +406,7 @@
 {
 	int i, j, max;
 	globuser *sym;
-	int tmp;
+	user *tmp;
 	user *tmp1;
 	user *tmp2;
 
@@ -430,7 +434,7 @@
 {
 	int i, j, max;
 	globuser *sym;
-	int tmp;
+	user *tmp;
 	user *tmp1;
 	user *tmp2;
 
