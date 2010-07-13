--- ./modules/access/file.c.orig	2010-07-12 15:38:44.000000000 -0400
+++ ./modules/access/file.c	2010-07-12 15:40:49.000000000 -0400
@@ -193,15 +193,8 @@
      * how to parse the data. The directory plugin will do it. */
     if (S_ISDIR (st.st_mode))
     {
-#ifdef HAVE_FDOPENDIR
-        DIR *handle = fdopendir (fd);
-        if (handle == NULL)
-            goto error; /* Uh? */
-        return DirInit (p_access, handle);
-#else
         msg_Dbg (p_access, "ignoring directory");
         goto error;
-#endif
     }
 
     access_sys_t *p_sys = malloc (sizeof (*p_sys));
