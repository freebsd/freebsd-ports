Taken from: [FDclone-users:00244] Re: SEGV caused by group lookups

diff -u ../old/FD-2.04c/pathname.c ./pathname.c
--- ../old/FD-2.04c/pathname.c	Wed Oct 15 00:00:00 2003
+++ ./pathname.c	Wed Nov 19 12:40:17 2003
@@ -2917,7 +2917,7 @@
 	gidlist = b_realloc(gidlist, maxgid, gidtable);
 	gidlist[maxgid].gid = grp -> gr_gid;
 	gidlist[maxgid].name = strdup2(grp -> gr_name);
-	gidlist[maxgid].gr_mem = grp -> gr_mem;
+	gidlist[maxgid].gr_mem = duplvar(grp -> gr_mem, -1);
 	gidlist[maxgid].ismem = 0;
 	return(&(gidlist[maxgid++]));
 }
@@ -2932,13 +2932,15 @@
 	if (!(gp = findgid(gid, NULL))) return(0);
 	if (!(gp -> ismem)) {
 		gp -> ismem++;
-		if ((up = finduid(geteuid(), NULL)))
+		if (gp -> gr_mem && (up = finduid(geteuid(), NULL)))
 		for (i = 0; gp -> gr_mem[i]; i++) {
 			if (!strpathcmp(up -> name, gp -> gr_mem[i])) {
 				gp -> ismem++;
 				break;
 			}
 		}
+		freevar(gp -> gr_mem);
+		gp -> gr_mem = NULL;
 	}
 
 	return(gp -> ismem - 1);
