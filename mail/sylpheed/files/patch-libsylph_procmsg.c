--- libsylph/procmsg.c.orig	2014-06-10 04:06:35 UTC
+++ libsylph/procmsg.c
@@ -164,7 +164,7 @@ static gint procmsg_read_cache_data_str_
 	if (endp - *p < sizeof(len))
 		return -1;
 
-	len = *(const guint32 *)(*p);
+	memcpy(&len, *p, sizeof(len));
 	*p += sizeof(len);
 	if (len > G_MAXINT || len > endp - *p)
 		return -1;
@@ -197,7 +197,7 @@ static gint procmsg_read_cache_data_str_
 		g_mapped_file_free(mapfile);			\
 		return NULL;					\
 	} else {						\
-		n = *(const guint32 *)p;			\
+		memcpy(&n, p, sizeof(n));			\
 		p += sizeof(guint32);				\
 	}							\
 }
