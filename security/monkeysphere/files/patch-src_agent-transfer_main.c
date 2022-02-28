--- src/agent-transfer/main.c.orig	2022-02-28 17:21:23 UTC
+++ src/agent-transfer/main.c
@@ -385,7 +385,7 @@ size_t get_ssh_sz (gcry_mpi_t mpi) {
 int send_to_ssh_agent(struct exporter *e, int fd, unsigned int seconds, int confirm, const char *comment) {
   const char *key_type;
   int ret;
-  size_t len, mpilen;
+  size_t len=0, mpilen=0;
   off_t offset;
   unsigned char *msgbuf = NULL;
   uint32_t tmp;
@@ -450,7 +450,7 @@ int send_to_ssh_agent(struct exporter *e, int fd, unsi
     qdata = gcry_mpi_get_opaque (e->q, &qsz);
     ddata = gcry_mpi_get_opaque (e->d, &dsz);
     if (qsz != 33*8 || dsz != 32*8 || !qdata || !ddata) {
-      fprintf (stderr, "Ed25519 key did not have the expected components (q: %d %p, d: %d %p)\n",
+      fprintf (stderr, "Ed25519 key did not have the expected components (q: %d %s, d: %d %s)\n",
                qsz, qdata, dsz, ddata);
       return -1;
     }
