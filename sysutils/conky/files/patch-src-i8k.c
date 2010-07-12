--- src/i8k.c.orig
+++ src/i8k.c
@@ -53,7 +53,7 @@ struct {
 #define PROC_I8K "/proc/i8k"
 #define I8K_DELIM " "
 static char *i8k_procbuf = NULL;
-void update_i8k(void)
+int update_i8k(void)
 {
 	FILE *fp;
 
@@ -61,8 +61,13 @@ void update_i8k(void)
 		i8k_procbuf = (char *) malloc(128 * sizeof(char));
 	}
 	if ((fp = fopen(PROC_I8K, "r")) == NULL) {
-		CRIT_ERR(NULL, NULL, "/proc/i8k doesn't exist! use insmod to make sure the kernel "
+		free(i8k_procbuf);
+		i8k_procbuf = NULL;
+		NORM_ERR("/proc/i8k doesn't exist! use insmod to make sure the kernel "
 			"driver is loaded...");
+		clean_up_without_threads(NULL, NULL);
+		free(current_mail_spool);
+		return 1;
 	}
 
 	memset(&i8k_procbuf[0], 0, 128);
@@ -82,6 +87,7 @@ void update_i8k(void)
 	i8k.right_fan_rpm = strtok(NULL, I8K_DELIM);
 	i8k.ac_status = strtok(NULL, I8K_DELIM);
 	i8k.buttons_status = strtok(NULL, I8K_DELIM);
+	return 0;
 }
 
 static const char *fan_status_to_string(int status)
