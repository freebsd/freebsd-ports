--- server.h.orig	2008-10-03 15:49:53 UTC
+++ server.h
@@ -152,22 +152,22 @@ class LATServer
 	  return (!(type == INACTIVE || type == DISABLED_PTY));
 	}
 
-	bool operator==(int _fd)
+	bool operator==(int _fd) const
 	{
 	    return (type != INACTIVE && fd == _fd);
 	}
 
-	bool operator==(const fdinfo &fdi)
+	bool operator==(const fdinfo &fdi) const
 	{
 	    return (fd == fdi.fd);
 	}
 
-	bool operator!=(const fdinfo &fdi)
+	bool operator!=(const fdinfo &fdi) const
 	{
 	    return (fd != fdi.fd);
 	}
 
-	bool operator!=(int _fd)
+	bool operator!=(int _fd) const
 	{
 	    return (type == INACTIVE || fd != _fd);
 	}
