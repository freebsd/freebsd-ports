--- maildir/maildirfilter.c.orig	Tue Jan  2 13:47:39 2007
+++ maildir/maildirfilter.c	Tue Jan  2 13:48:14 2007
@@ -81,6 +81,7 @@
 		  int *errcode)
 {
 const char *c;
+struct maildirfilterrule *pom;
 
 /*
 ** Before creating a new rule, validate all input.
@@ -101,7 +102,6 @@
 	/* rule name: may not already exist */
 	*errcode=MF_ERR_EXISTS;
 	
-	struct maildirfilterrule *pom;
 	for (pom=r->first; pom->next; pom=pom->next) {
 	    if (p!=pom && !strcmp(name, pom->rulename))
 		return (-1);
