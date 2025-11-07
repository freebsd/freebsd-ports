https://lists.sr.ht/~kennylevinsen/seatd-devel/%3Cfrbq-4mf4-wny@FreeBSD.org%3E

--- seatd/seatd.c.orig	2024-10-30 19:43:26 UTC
+++ seatd/seatd.c
@@ -72,7 +72,7 @@ int main(int argc, char *argv[]) {
 	int readiness = -1;
 	bool unlink_existing_socket = true;
 	bool chown_socket = true;
-	enum libseat_log_level level = LIBSEAT_LOG_LEVEL_INFO;
+	enum libseat_log_level level = LIBSEAT_LOG_LEVEL_ERROR;
 	while ((c = getopt(argc, argv, "vhn:g:u:l:z")) != -1) {
 		switch (c) {
 		case 'n':
