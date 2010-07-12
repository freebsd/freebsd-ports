--- src/common.h.orig
+++ src/common.h
@@ -11,7 +11,7 @@
 #include <sys/socket.h>
 #include "text_object.h"
 
-void add_update_callback(void (*func)(void));
+void add_update_callback(int (*func)(void));
 void free_update_callbacks(void);
 void start_update_threading(void);
 
@@ -19,20 +19,20 @@ void start_update_threading(void);
 void strfold(char *start, int count);
 int check_mount(char *s);
 void prepare_update(void);
-void update_uptime(void);
-void update_meminfo(void);
-void update_net_stats(void);
-void update_cpu_usage(void);
-void update_total_processes(void);
-void update_uname(void);
-void update_threads(void);
-void update_running_processes(void);
+int update_uptime(void);
+int update_meminfo(void);
+int update_net_stats(void);
+int update_cpu_usage(void);
+int update_total_processes(void);
+int update_uname(void);
+int update_threads(void);
+int update_running_processes(void);
 void update_stuff(void);
 char get_freq(char *, size_t, const char *, int, unsigned int);
 void print_voltage_mv(struct text_object *, char *, int);
 void print_voltage_v(struct text_object *, char *, int);
-void update_load_average(void);
-void update_top(void);
+int update_load_average(void);
+int update_top(void);
 void free_all_processes(void);
 struct process *get_first_process(void);
 void get_cpu_count(void);
@@ -50,7 +50,7 @@ void format_seconds(char *buf, unsigned int n, long t);
 void format_seconds_short(char *buf, unsigned int n, long t);
 
 #ifdef X11
-void update_x11info(void);
+int update_x11info(void);
 #endif
 
 int round_to_int_temp(float);
