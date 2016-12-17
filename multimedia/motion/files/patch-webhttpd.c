Fix warnings about mismatched format specifiers (Fixed upstream in dbd7282)
Fix sockaddr type mismatch warnings (Fixed upstream in dbd7282)

--- webhttpd.c.orig	2016-10-25 01:39:24 UTC
+++ webhttpd.c
@@ -2067,7 +2067,7 @@ static unsigned int handle_get(int clien
             //Send the webcontrol section if applicable
             if (cnt[0]->conf.webcontrol_html_output) {
                 send_template_ini_client(client_socket, ini_template);
-                sprintf(res, "<b>Motion "VERSION" Running [%hu] Cameras</b><br>\n"
+                sprintf(res, "<b>Motion "VERSION" Running [%d] Cameras</b><br>\n"
                              "<a href='/0/'>All</a>\n", i);
                 send_template(client_socket, res);
 
@@ -2079,7 +2079,7 @@ static unsigned int handle_get(int clien
                         send_template(client_socket, res);
                         counter = 0;
                     }
-                    sprintf(res, "<a href='/%hu/'>Camera %d%s%s</a>\n", y, cnt[y]->conf.camera_id,
+                    sprintf(res, "<a href='/%d/'>Camera %d%s%s</a>\n", y, cnt[y]->conf.camera_id,
                                  cnt[y]->conf.camera_name ? " -- " : "",
                                  cnt[y]->conf.camera_name ? cnt[y]->conf.camera_name : "");
                     send_template(client_socket, res);
@@ -2112,10 +2112,10 @@ static unsigned int handle_get(int clien
                 send_template_end_client(client_socket);
             } else {
                 send_template_ini_client_raw(client_socket);
-                sprintf(res, "Motion "VERSION" Running [%hu] Cameras\n0\n", i);
+                sprintf(res, "Motion "VERSION" Running [%d] Cameras\n0\n", i);
                 send_template_raw(client_socket, res);
                 for (y = 1; y < i; y++) {
-                    sprintf(res, "%hu\n", y);
+                    sprintf(res, "%d\n", y);
                     send_template_raw(client_socket, res);
                 }
             }
@@ -2571,7 +2571,7 @@ static int acceptnonblocking(int serverf
 
     if (select(serverfd + 1, &fds, NULL, NULL, &tm) > 0) {
         if (FD_ISSET(serverfd, &fds)) {
-            if ((curfd = accept(serverfd, &client, &client_len)) > 0)
+            if ((curfd = accept(serverfd, (struct sockaddr *)&client, &client_len)) > 0)
                 return curfd;
         }
     }
