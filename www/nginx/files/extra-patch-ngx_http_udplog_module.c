--- ../nginx_udplog_module-1.0.0/ngx_http_udplog_module.c.orig	2010-01-05 20:20:35.000000000 +0100
+++ ../nginx_udplog_module-1.0.0/ngx_http_udplog_module.c	2011-12-02 18:31:18.000000000 +0100
@@ -1,4 +1,3 @@
-
 /*
  * Copyright (C) 2010 Valery Kholodkov
  *
@@ -45,6 +44,12 @@
 } ngx_http_log_fmt_t;
 
 typedef struct {
+    ngx_str_t                value;
+    ngx_array_t             *lengths;
+    ngx_array_t             *values;
+} ngx_http_log_tag_template_t;
+
+typedef struct {
     ngx_array_t                 formats;    /* array of ngx_http_log_fmt_t */
     ngx_uint_t                  combined_used; /* unsigned  combined_used:1 */
 } ngx_http_log_main_conf_t;
@@ -64,8 +69,7 @@
 typedef struct {
     ngx_udp_endpoint_t       *endpoint;
     ngx_http_log_fmt_t       *format;
-    ngx_uint_t                facility;
-    ngx_uint_t                severity;
+    ngx_uint_t                bare:1;
 } ngx_http_udplog_t;
 
 typedef struct {
@@ -73,8 +77,11 @@
 } ngx_http_udplog_main_conf_t;
 
 typedef struct {
-    ngx_array_t                *logs;       /* array of ngx_http_udplog_t */
-    unsigned                    off;
+    ngx_array_t                 *logs;       /* array of ngx_http_udplog_t */
+    unsigned                     off;
+    ngx_http_log_tag_template_t *tag;
+    ngx_uint_t                   facility;
+    ngx_uint_t                   severity;
 } ngx_http_udplog_conf_t;
 
 ngx_int_t ngx_udp_connect(ngx_udp_connection_t *uc);
@@ -88,6 +95,8 @@
     void *child);
 
 static char *ngx_http_udplog_set_log(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
+static char *ngx_http_udplog_set_priority(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
+static char *ngx_http_udplog_set_tag(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
 
 static ngx_int_t ngx_http_udplog_init(ngx_conf_t *cf);
 
@@ -96,12 +105,26 @@
 
     { ngx_string("access_udplog"),
       NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF
-                        |NGX_HTTP_LMT_CONF|NGX_CONF_TAKE123,
+                        |NGX_HTTP_LMT_CONF|NGX_CONF_TAKE1234,
       ngx_http_udplog_set_log,
       NGX_HTTP_LOC_CONF_OFFSET,
       0,
       NULL },
 
+    { ngx_string("udplog_priority"),
+      NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_CONF_TAKE12,
+      ngx_http_udplog_set_priority,
+      NGX_HTTP_LOC_CONF_OFFSET,
+      0,
+      NULL },
+
+    { ngx_string("udplog_tag"),
+      NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_CONF_TAKE1,
+      ngx_http_udplog_set_tag,
+      NGX_HTTP_LOC_CONF_OFFSET,
+      offsetof(ngx_http_udplog_conf_t, tag),
+      NULL },
+
       ngx_null_command
 };
 
@@ -166,7 +189,7 @@
     { ngx_null_string, 0 }
 };
 
-static ngx_udplog_severity_t ngx_udplog_severity[] = {
+static ngx_udplog_severity_t ngx_udplog_severities[] = {
     { ngx_string("emerg"),      0 },
     { ngx_string("alert"),      1 },
     { ngx_string("crit"),       2 },
@@ -190,6 +213,7 @@
     u_char                   *line, *p;
     size_t                    len;
     ngx_uint_t                i, l, pri;
+    ngx_str_t                 tag;
     ngx_http_udplog_t        *log;
     ngx_http_log_op_t        *op;
     ngx_http_udplog_conf_t   *ulcf;
@@ -205,12 +229,31 @@
         return NGX_OK;
     }
 
+    if(ulcf->tag != NULL)
+    {
+        if(ulcf->tag->lengths == NULL) {
+            tag = ulcf->tag->value;
+        }
+        else{
+            if (ngx_http_script_run(r, &tag, ulcf->tag->lengths->elts, 0, ulcf->tag->values->elts)
+                == NULL)
+            {
+                return NGX_ERROR;
+            }
+        }
+    }
+    else {
+        tag.data = (u_char*)"nginx";
+        tag.len = sizeof("nginx") - 1;
+    }
+
     time = ngx_time();
     ngx_gmtime(time, &tm);
 
     log = ulcf->logs->elts;
+    pri = ulcf->facility * 8 + ulcf->severity;
+
     for (l = 0; l < ulcf->logs->nelts; l++) {
-        pri = log[l].facility * 8 + log[l].severity;
 
         if(pri > 255) {
             pri = NGX_UDPLOG_FACILITY_LOCAL7 * 8 + NGX_UDPLOG_SEVERITY_INFO;
@@ -231,7 +274,8 @@
             }
         }
 
-        len += sizeof("<255>") - 1 + sizeof("Jan 31 00:00:00") - 1 + 1 + ngx_cycle->hostname.len + 1;
+        len += sizeof("<255>") - 1 + sizeof("Jan 31 00:00:00") - 1 + 1 + ngx_cycle->hostname.len + 1
+            + tag.len + 2;
 
 #if defined nginx_version && nginx_version >= 7003
         line = ngx_pnalloc(r->pool, len);
@@ -245,9 +289,12 @@
         /*
          * BSD syslog message header (see RFC 3164)
          */
-        p = ngx_sprintf(line, "<%ui>%s %2d %02d:%02d:%02d %V ", pri, months[tm.ngx_tm_mon - 1], tm.ngx_tm_mday,
-            tm.ngx_tm_hour, tm.ngx_tm_min, tm.ngx_tm_sec, &ngx_cycle->hostname);
-
+	if(!log[l].bare){
+	  p = ngx_sprintf(line, "<%ui>%s %2d %02d:%02d:%02d %V %V: ", pri, months[tm.ngx_tm_mon - 1], tm.ngx_tm_mday,
+			  tm.ngx_tm_hour, tm.ngx_tm_min, tm.ngx_tm_sec, &ngx_cycle->hostname, &tag);
+	}else{
+	  p = line;
+	}
         for (i = 0; i < log[l].format->ops->nelts; i++) {
             p = op[i].run(r, p, &op[i]);
         }
@@ -280,10 +327,15 @@
     uc->sockaddr = endpoint->peer_addr.sockaddr;
     uc->socklen = endpoint->peer_addr.socklen;
     uc->server = endpoint->peer_addr.name;
-#if defined nginx_version && nginx_version >= 7054
+#if defined nginx_version && ( nginx_version >= 7054 && nginx_version < 8032 )
     uc->log = &cf->cycle->new_log;
 #else
     uc->log = cf->cycle->new_log;
+#if defined nginx_version && nginx_version >= 8032
+    uc->log.handler = NULL;
+    uc->log.data = NULL;
+    uc->log.action = "logging";
+#endif
 #endif
 
     return NGX_OK;
@@ -320,6 +372,11 @@
 
     if (uc->connection == NULL) {
         if(ngx_udp_connect(uc) != NGX_OK) {
+            if(uc->connection != NULL) {
+                ngx_free_connection(uc->connection);
+                uc->connection = NULL;
+            }
+
             return NGX_ERROR;
         }
 
@@ -335,7 +392,11 @@
     }
 
     if ((size_t) n != (size_t) len) {
+#if defined nginx_version && nginx_version >= 8032
+        ngx_log_error(NGX_LOG_CRIT, &uc->log, 0, "send() incomplete");
+#else
         ngx_log_error(NGX_LOG_CRIT, uc->log, 0, "send() incomplete");
+#endif
         return NGX_ERROR;
     }
 
@@ -364,6 +425,9 @@
     if (conf == NULL) {
         return NGX_CONF_ERROR;
     }
+    conf->off = 1;
+    conf->facility = NGX_CONF_UNSET_UINT;
+    conf->severity = NGX_CONF_UNSET_UINT;
 
     return conf;
 }
@@ -374,37 +438,21 @@
     ngx_http_udplog_conf_t *prev = parent;
     ngx_http_udplog_conf_t *conf = child;
 
-    ngx_http_udplog_t         *log;
-    ngx_http_log_fmt_t        *fmt;
-    ngx_http_log_main_conf_t  *lmcf;
-
-    if(conf->logs || conf->off) {
-        return NGX_CONF_OK;
+    if(conf->tag == NULL) {
+        conf->tag = prev->tag;
     }
 
-    conf->logs = prev->logs;
-    conf->off = prev->off;
+    ngx_conf_merge_uint_value(conf->facility,
+                              prev->facility, NGX_UDPLOG_FACILITY_LOCAL7);
+    ngx_conf_merge_uint_value(conf->severity,
+                              prev->severity, NGX_UDPLOG_SEVERITY_INFO);
 
     if(conf->logs || conf->off) {
         return NGX_CONF_OK;
     }
 
-    conf->logs = ngx_array_create(cf->pool, 2, sizeof(ngx_http_udplog_t));
-    if(conf->logs == NULL) {
-        return NGX_CONF_ERROR;
-    }
-
-    log = ngx_array_push(conf->logs);
-    if(log == NULL) {
-        return NGX_CONF_ERROR;
-    }
-
-    lmcf = ngx_http_conf_get_module_main_conf(cf, ngx_http_log_module);
-    fmt = lmcf->formats.elts;
-
-    /* the default "combined" format */
-    log->format = &fmt[0];
-    lmcf->combined_used = 1;
+    conf->logs = prev->logs;
+    conf->off = prev->off;
 
     return NGX_CONF_OK;
 }
@@ -434,12 +482,6 @@
     return endpoint;
 }
 
-static ngx_int_t
-ngx_http_udplog_set_facility_and_severity(ngx_http_udplog_t *log, ngx_str_t *value)
-{
-    return NGX_OK;
-}
-
 static char *
 ngx_http_udplog_set_log(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
 {
@@ -458,6 +500,7 @@
         ulcf->off = 1;
         return NGX_CONF_OK;
     }
+    ulcf->off = 0;
 
     if (ulcf->logs == NULL) {
         ulcf->logs = ngx_array_create(cf->pool, 2, sizeof(ngx_http_udplog_t));
@@ -483,10 +526,11 @@
 
     ngx_memzero(&u, sizeof(ngx_url_t));
 
-    u.host = value[1];
-    u.port = 514;
+    u.url = value[1];
+    u.default_port = 514;
+    u.no_resolve = 0;
 
-    if(ngx_inet_resolve_host(cf->pool, &u) != NGX_OK) {
+    if(ngx_parse_url(cf->pool, &u) != NGX_OK) {
         ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "%V: %s", &u.host, u.err);
         return NGX_CONF_ERROR;
     }
@@ -496,7 +540,7 @@
     if(log->endpoint == NULL) {
         return NGX_CONF_ERROR;
     }
-
+    log->bare = 0;
     if (cf->args->nelts >= 3) {
         name = value[2];
 
@@ -508,14 +552,18 @@
         name.data = (u_char *) "combined";
         lmcf->combined_used = 1;
     }
-
+    if (cf->args->nelts >= 4) {
+      if (ngx_strcmp(value[3].data, "bare") == 0) {
+	log->bare = 1;
+      }
+    }
     fmt = lmcf->formats.elts;
     for (i = 0; i < lmcf->formats.nelts; i++) {
         if (fmt[i].name.len == name.len
             && ngx_strcasecmp(fmt[i].name.data, name.data) == 0)
         {
             log->format = &fmt[i];
-            goto facility;
+            goto done;
         }
     }
 
@@ -523,12 +571,105 @@
                        "unknown log format \"%V\"", &name);
     return NGX_CONF_ERROR;
 
-facility:
-    log->facility = NGX_UDPLOG_FACILITY_LOCAL7;
-    log->severity = NGX_UDPLOG_SEVERITY_INFO;
+done:
+
+    return NGX_CONF_OK;
+}
+
+
+static char *
+ngx_http_udplog_set_priority(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
+{
+    ngx_http_udplog_conf_t     *ulcf = conf;
+    ngx_str_t                  *value;
+    ngx_udplog_facility_t      *f;
+    ngx_udplog_severity_t      *s;
+
+    value = cf->args->elts;
+
+    f = ngx_udplog_facilities;
+
+    while(f->name.data != NULL) {
+        if(ngx_strncmp(f->name.data, value[1].data, f->name.len) == 0)
+            break;
+
+        f++;
+    }
+
+    if(f->name.data != NULL) {
+        ulcf->facility = f->number;
+    }
+    else {
+        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
+                           "unknown facility \"%V\"", &value[1]);
+        return NGX_CONF_ERROR;
+    }
+
+    if (cf->args->nelts == 3) {
+        s = ngx_udplog_severities;
+
+        while(s->name.data != NULL) {
+            if(ngx_strncmp(s->name.data, value[2].data, s->name.len) == 0)
+                break;
+
+            s++;
+        }
+
+        if(s->name.data != NULL) {
+            ulcf->severity = s->number;
+        }
+        else {
+            ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
+                               "unknown severity \"%V\"", &value[2]);
+            return NGX_CONF_ERROR;
+        }
+    }
+
+    return NGX_CONF_OK;
+}
+
+static char *
+ngx_http_udplog_set_tag(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
+{
+    ngx_int_t                   n;
+    ngx_str_t                  *value;
+    ngx_http_script_compile_t   sc;
+    ngx_http_log_tag_template_t **field, *h;
+
+    field = (ngx_http_log_tag_template_t**) (((u_char*)conf) + cmd->offset);
+
+    value = cf->args->elts;
+
+    if (*field == NULL) {
+        *field = ngx_palloc(cf->pool, sizeof(ngx_http_log_tag_template_t));
+        if (*field == NULL) {
+            return NGX_CONF_ERROR;
+        }
+    }
+
+    h = *field;
+
+    h->value = value[1];
+    h->lengths = NULL;
+    h->values = NULL;
+
+    /*
+     * Compile field name
+     */
+    n = ngx_http_script_variables_count(&value[1]);
+
+    if (n > 0) {
+        ngx_memzero(&sc, sizeof(ngx_http_script_compile_t));
+
+        sc.cf = cf;
+        sc.source = &value[1];
+        sc.lengths = &h->lengths;
+        sc.values = &h->values;
+        sc.variables = n;
+        sc.complete_lengths = 1;
+        sc.complete_values = 1;
 
-    if(cf->args->nelts == 4) {
-        if(ngx_http_udplog_set_facility_and_severity(log, &value[3]) != NGX_OK) {
+        if (ngx_http_script_compile(&sc) != NGX_OK) {
             return NGX_CONF_ERROR;
         }
     }
