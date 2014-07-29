--- src/toss.c.orig	Mon Jul  6 16:04:30 1998
+++ src/toss.c	Sun Mar  5 18:35:41 2000
@@ -316,11 +316,16 @@
         newtic->areadesc=xstrcpy(acur->desc);
 
       /* make base of outbound file name */
+#ifndef AMIGA4D
       if(utmp->addr.point!=0)
         snprintf(ftmp,sizeof(ftmp)-1,"%04x%04x.pnt/%08x",
          utmp->addr.net,utmp->addr.node,utmp->addr.point);
       else
         snprintf(ftmp,sizeof(ftmp)-1,"%04x%04x",utmp->addr.net,utmp->addr.node);
+#else
+      snprintf(ftmp,sizeof(ftmp)-1,"%d.%d.%d.%d", utmp->addr.zone,
+	       utmp->addr.net, utmp->addr.node, utmp->addr.point);
+#endif /* AMIGA4D */
 
       /* determine queue directory */
       strcpy(qdir,get_outbound(utmp->addr.zone)); strcat(qdir,"/");
@@ -342,21 +347,28 @@
          outbound/xxxxyyyy.pnt[/gtic_q]/zzzzzzzz.xlo
       */
       strcpy(xlo,get_outbound(utmp->addr.zone)); strcat(xlo,"/");
+#ifndef AMIGA4D
       if(utmp->addr.point!=0)
       {
         snprintf(ftmp,sizeof(ftmp)-1,"%04x%04x.pnt/",
 					utmp->addr.net,utmp->addr.node);
 				strcat(xlo,ftmp);
       }
+#endif /* AMIGA4D */
       if(mk_bsy==FALSE)
       {
 				strcat(xlo,"gtic_q/");
 				mkdirs(xlo,dirmode(outbound_mode));
       }
+#ifndef AMIGA4D
       if(newtic->to.point!=0)
         snprintf(ftmp,sizeof(ftmp)-1,"%08x",newtic->to.point);
       else
         snprintf(ftmp,sizeof(ftmp)-1,"%04x%04x",newtic->to.net,newtic->to.node);
+#else
+      snprintf(ftmp,sizeof(ftmp)-1,"%d.%d.%d.%d", newtic->to.zone,
+	       newtic->to.net, newtic->to.node, newtic->to.point);
+#endif /* AMIGA4D */
       if(utmp->flags & USER_HOLD)
         strcat(ftmp,".hlo");
       else
@@ -873,7 +885,7 @@
       
     if(announce_f)
 		{
-      fprintf(announce_f,"AREA: %-15s FILE: %s\n",curarea->name,cur->file);
+      fprintf(announce_f,">AREA: %-15s FILE: %s\n",curarea->name,cur->file);
 			if(pub_path && pub_url &&
 				strlen(curarea->path)>=strlen(pub_path) &&
 				strncmp(curarea->path,pub_path,strlen(pub_path))==0) 
