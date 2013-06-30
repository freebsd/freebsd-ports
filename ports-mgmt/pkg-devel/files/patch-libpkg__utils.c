commit dbb08c0d2a5da374ddc128f93eb0d57efa08ccf8
Author: Bryan Drewery <bryan@shatow.net>
Date:   Sun Jun 30 09:37:15 2013 -0500

    Return proper value in sha256_fd()

diff --git libpkg/utils.c libpkg/utils.c
index 45a220a..50dcdd1 100644
--- libpkg/utils.c
+++ libpkg/utils.c
@@ -396,7 +396,7 @@ cleanup:
 		close(my_fd);
 	(void)lseek(fd, 0, SEEK_SET);
 
-	return (EPKG_OK);
+	return (ret);
 }
 
 int
