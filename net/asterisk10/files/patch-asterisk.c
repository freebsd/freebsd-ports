
$FreeBSD$

--- asterisk.c.orig
+++ asterisk.c
@@ -1803,7 +1804,6 @@
 
 	if (option_exec && data) {  /* hack to print output then exit if asterisk -rx is used */
 		char tempchar;
-#ifdef __Darwin__
 		struct pollfd fds[0];
 		fds[0].fd = ast_consock;
 		fds[0].events = POLLIN;
@@ -1811,9 +1811,6 @@
 		while (poll(fds, 1, 100) > 0) {
 			ast_el_read_char(el, &tempchar);
 		}
-#else
-		while (!ast_el_read_char(el, &tempchar));
-#endif
 		return;
 	}
 	for(;;) {
