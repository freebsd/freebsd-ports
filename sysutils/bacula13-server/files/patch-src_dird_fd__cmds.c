--- src/dird/fd_cmds.c.orig	2023-05-02 09:50:49 UTC
+++ src/dird/fd_cmds.c
@@ -72,6 +72,34 @@ static void delete_bsock_end_cb(JCR *jcr, void *ctx)
    free_bsock(socket);
 }
 
+/* 16.0.10 (12Jan24) x86_64-pc-linux-gnu,ubuntu,20.04 -> 160010 */
+static uint64_t scan_version(char *str)
+{
+   Enter(0);
+   uint64_t version = 0;
+
+   regex_t r1;
+   regmatch_t pmatch[16];
+   regcomp(&r1, "^([0-9]+)\\.([0-9]+)\\.([0-9]+)", REG_EXTENDED);
+   if (regexec(&r1, str, 4, pmatch, 0) == 0 &&
+       pmatch[1].rm_so == 0 && pmatch[1].rm_eo > 0 && pmatch[1].rm_eo < 50 &&
+       pmatch[2].rm_so > 0 && pmatch[2].rm_eo > 0 && (pmatch[2].rm_eo - pmatch[2].rm_so) < 50 &&
+       pmatch[3].rm_so > 0 && pmatch[3].rm_eo > 0 && (pmatch[3].rm_eo - pmatch[3].rm_so) < 50)
+   {
+      char buf[50];
+      bstrncpy(buf, str + pmatch[1].rm_so, pmatch[1].rm_eo - pmatch[1].rm_so + 1);
+      version = str_to_uint64(buf) * 10000;
+
+      bstrncpy(buf, str + pmatch[2].rm_so, pmatch[2].rm_eo - pmatch[2].rm_so + 1);
+      version += str_to_uint64(buf) * 100;
+
+      bstrncpy(buf, str + pmatch[3].rm_so, pmatch[3].rm_eo - pmatch[3].rm_so + 1);
+      version += str_to_uint64(buf);
+   }
+   regfree(&r1);
+   return version;
+}
+
 /*
  * Open connection with File daemon.
  * Try connecting every retry_interval (default 10 sec), and
@@ -195,6 +223,8 @@ int connect_to_file_daemon(JCR *jcr, int retry_interva
           cr.FileRetention = jcr->client->FileRetention;
           cr.JobRetention = jcr->client->JobRetention;
           bstrncpy(cr.Uname, fd->msg+strlen(OKjob)+1, sizeof(cr.Uname));
+          jcr->client_version = scan_version(cr.Uname);
+
           if (!db_update_client_record(jcr, jcr->db, &cr)) {
              Jmsg(jcr, M_WARNING, 0, _("Error updating Client record. ERR=%s\n"),
                 db_strerror(jcr->db));
