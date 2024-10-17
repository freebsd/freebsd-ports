Obtained from:	https://git.tartarus.org/?p=simon/agedu.git;a=commit;h=3622edabe7f6776dc66dd5d685ab9980226cfa6b

--- html.c.orig	2021-11-29 02:20:04 UTC
+++ html.c
@@ -131,6 +131,8 @@ static unsigned long long round_and_format_age(struct 
 	sprintf(newbuf, "%d year%s", i, i==1 ? "" : "s");
 	if (newret < age)
 	    goto finish;
+	if (newret > ret)              /* integer overflow - give up! */
+	    goto finish;
 	strcpy(buf, newbuf);
 	ret = newret;
     }
