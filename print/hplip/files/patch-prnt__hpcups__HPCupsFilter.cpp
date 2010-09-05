--- ./prnt/hpcups/HPCupsFilter.cpp.orig	2010-08-25 11:15:08.000000000 +0400
+++ ./prnt/hpcups/HPCupsFilter.cpp	2010-08-25 11:35:36.000000000 +0400
@@ -433,13 +433,14 @@
 
     memset(&m_JA, 0, sizeof(JobAttributes));
     struct    tm       *t;
-    struct    timeb    tb;
+    struct    timeval    tv;
+    struct    timezone   tz;
     time_t             long_time;
     time(&long_time);
     t = localtime(&long_time);
-    ftime(&tb);
+    gettimeofday(&tv, &tz);
     strncpy(m_JA.job_start_time, asctime(t), sizeof(m_JA.job_start_time)-1);    // returns Fri Jun  5 08:12:16 2009
-    snprintf(m_JA.job_start_time+19, sizeof(m_JA.job_start_time) - 20, ":%d %d", tb.millitm, t->tm_year + 1900); // add milliseconds
+    snprintf(m_JA.job_start_time+19, sizeof(m_JA.job_start_time) - 20, ":%d %d", tv.tv_usec/1000, t->tm_year + 1900); // add milliseconds
 
     getLogLevel();
     m_JA.job_id = atoi(argv[1]);
