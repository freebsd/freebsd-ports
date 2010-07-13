--- ./modules/access/fs.c.orig	2010-07-12 15:48:03.000000000 -0400
+++ ./modules/access/fs.c	2010-07-12 15:48:51.000000000 -0400
@@ -83,9 +83,6 @@
       change_string_list( psz_recursive_list, psz_recursive_list_text, 0 )
     add_string( "ignore-filetypes", "m3u,db,nfo,ini,jpg,jpeg,ljpg,gif,png,pgm,pgmyuv,pbm,pam,tga,bmp,pnm,xpm,xcf,pcx,tif,tiff,lbm,sfv,txt,sub,idx,srt,cue,ssa",
                 NULL, IGNORE_TEXT, IGNORE_LONGTEXT, false )
-#ifndef HAVE_FDOPENDIR
-    add_shortcut( "file" )
-#endif
     add_shortcut( "directory" )
     add_shortcut( "dir" )
     set_callbacks( DirOpen, DirClose )
