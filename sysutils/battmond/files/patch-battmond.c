--- battmond.c.orig	2021-04-11 13:03:15 UTC
+++ battmond.c
@@ -189,13 +189,12 @@ int main(int argc, char ** argv)
 #ifdef DEBUG
 		fprintf(stderr, "Total battery capacity: %d%%\n", total_cap);
 #endif
-		if (num_discharging && !num_charging && total_cap > 0) {
+		if (num_discharging && !num_charging && total_cap >= 0) {
 			if (total_cap <= halt) {
 				if (dosuspend) { // Suspend
 					syslog(LOG_EMERG, BATT_SUSP);
 					close(acpifd);
-					execl("/usr/sbin/acpiconf", "acpiconf", "-s3", NULL);
-					oops("execl");
+					system("/usr/sbin/acpiconf -s3");
 				} else { // Halt
 					syslog(LOG_EMERG, BATT_HALT);
 					close(acpifd);
