--- maildir/maildirfilter.c.orig	Sat Jul  1 02:44:48 2006
+++ maildir/maildirfilter.c	Sat Dec  9 21:38:05 2006
@@ -100,13 +100,13 @@
 
 	/* rule name: may not already exist */
 	*errcode=MF_ERR_EXISTS;
-	
+{
 	struct maildirfilterrule *pom;
 	for (pom=r->first; pom->next; pom=pom->next) {
 	    if (p!=pom && !strcmp(name, pom->rulename))
 		return (-1);
 	}
-
+}
 	/* rule type: we must know what it is */
 
 	switch (type)	{
