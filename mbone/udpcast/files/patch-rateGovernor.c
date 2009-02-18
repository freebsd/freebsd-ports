--- rateGovernor.c.orig	2008-09-20 09:07:29.000000000 +0200
+++ rateGovernor.c	2009-02-09 08:20:17.000000000 +0100
@@ -23,6 +23,25 @@
 #define DL_RATE_GOVERNOR
 #endif
 
+
+#ifdef __FreeBSD__
+char *
+strndup(const char *str, size_t n)
+{
+  size_t len;
+  char *copy;
+
+  for (len = 0; len < n && str[len]; len++)
+    continue;
+
+  if ((copy = malloc(len + 1)) == NULL)
+    return (NULL);
+  memcpy(copy, str, len);
+  copy[len] = '\0';
+  return (copy);
+}
+#endif
+
 void *rgInitGovernor(struct net_config *cfg, struct rateGovernor_t *gov)
 {
   if(cfg->nrGovernors == MAX_GOVERNORS) {
