--- miscutils/man.c.orig	2018-12-30 15:14:20 UTC
+++ miscutils/man.c
@@ -265,7 +265,7 @@ int man_main(int argc UNUSED_PARAM, char
 	if (!man_path_list) {
 		/* default, may be overridden by /etc/man.conf */
 		man_path_list = xzalloc(2 * sizeof(man_path_list[0]));
-		man_path_list[0] = (char*)"/usr/man";
+		man_path_list[0] = (char*)"/usr/share/man";
 		/* count_mp stays 0.
 		 * Thus, man.conf will overwrite man_path_list[0]
 		 * if a path is defined there.
