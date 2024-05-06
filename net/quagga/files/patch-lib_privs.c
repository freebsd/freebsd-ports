--- lib/privs.c.orig	2018-02-20 04:24:55.000000000 +0700
+++ lib/privs.c	2024-05-06 19:00:18.907694000 +0700
@@ -717,8 +717,8 @@ zprivs_init(struct zebra_privs_t *zprivs)
 
   if (zprivs->user)
     {
-      ngroups = sizeof(groups);
-      if ( (ngroups = getgrouplist (zprivs->user, zprivs_state.zgid, groups, &ngroups )) < 0 )
+      ngroups = nitems(groups);
+      if (getgrouplist (zprivs->user, zprivs_state.zgid, groups, &ngroups) < 0 )
         {
           /* cant use log.h here as it depends on vty */
           fprintf (stderr, "privs_init: could not getgrouplist for user %s\n",
