--- src/dvdauthor.c.orig	Fri Jan 16 20:55:42 2004
+++ src/dvdauthor.c	Tue Jan 20 17:59:45 2004
@@ -340,7 +340,7 @@
     if( ch>=va->numaudiotracks )
         va->numaudiotracks=ch+1;
 
-    audiodesc_set_audio_attr(&va->ad[ch],&va->adwarn[ch],attr,s);
+    return audiodesc_set_audio_attr(&va->ad[ch],&va->adwarn[ch],attr,s);
 }
 
 static int vobgroup_set_subpic_attr(struct vobgroup *va,int attr,char *s,int ch)
