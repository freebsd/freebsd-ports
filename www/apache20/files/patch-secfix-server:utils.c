diff -Nur httpd-2.0~/server/util.c httpd-2.0/server/util.c
--- server/util.c
+++ server/util.c
@@ -722,7 +722,7 @@
 
     *resp++ = '\0';
 #if RESOLVE_ENV_PER_TOKEN
-    return ap_resolve_env(p,result);
+    return (char *)ap_resolve_env(p,result);
 #else
     return result;
 #endif
@@ -782,39 +782,87 @@
  */
 AP_DECLARE(const char *) ap_resolve_env(apr_pool_t *p, const char * word)
 {
-       char tmp[ MAX_STRING_LEN ];
-       const char *s, *e;
-       tmp[0] = '\0';
-
-       if (!(s=ap_strchr_c(word,'$')))
-               return word;
-
-       do {
-               /* XXX - relies on strncat() to add '\0'
-                */
-               strncat(tmp,word,s - word);
-               if ((s[1] == '{') && (e=ap_strchr_c(s,'}'))) {
-                       const char *e2 = e;
-                       char *var;
-                       word = e + 1;
-                       var = apr_pstrndup(p, s+2, e2-(s+2));
-                       e = getenv(var);
-                       if (e) {
-                           strcat(tmp,e);
-                       } else {
-                           strncat(tmp, s, e2-s);
-                           strcat(tmp,"}");
-                       }
-               } else {
-                       /* ignore invalid strings */
-                       word = s+1;
-                       strcat(tmp,"$");
-               };
-       } while ((s=ap_strchr_c(word,'$')));
-       strcat(tmp,word);
+# define SMALL_EXPANSION 5
+    struct sll {
+        struct sll *next;
+        const char *string;
+        apr_size_t len;
+    } *result, *current, sresult[SMALL_EXPANSION];
+    char *res_buf, *cp;
+    const char *s, *e, *ep;
+    unsigned spc;
+    apr_size_t outlen;
+
+    s = ap_strchr_c(word, '$');
+    if (!s) {
+        return word;
+    }
+
+    /* well, actually something to do */
+    ep = word + strlen(word);
+    spc = 0;
+    result = current = &(sresult[spc++]);
+    current->next = NULL;
+    current->string = word;
+    current->len = s - word;
+    outlen = current->len;
+
+    do {
+        /* prepare next entry */
+        if (current->len) {
+            current->next = (spc < SMALL_EXPANSION)
+                            ? &(sresult[spc++])
+                            : (struct sll *)apr_palloc(p,
+                                                       sizeof(*current->next));
+            current = current->next;
+            current->next = NULL;
+            current->len = 0;
+        }
 
-       return apr_pstrdup(p,tmp);
+        if (*s == '$') {
+            if (s[1] == '{' && (e = ap_strchr_c(s, '}'))) {
+                word = getenv(apr_pstrndup(p, s+2, e-s-2));
+                if (word) {
+                    current->string = word;
+                    current->len = strlen(word);
+                    outlen += current->len;
+                }
+                else {
+                    current->string = s;
+                    current->len = e - s + 1;
+                    outlen += current->len;
+                }
+                s = e + 1;
+            }
+            else {
+                current->string = s++;
+                current->len = 1;
+                ++outlen;
+            }
+        }
+        else {
+            word = s;
+            s = ap_strchr_c(s, '$');
+            current->string = word;
+            current->len = s ? s - word : ep - word;
+            outlen += current->len;
+        }
+    } while (s && *s);
+
+    /* assemble result */
+    res_buf = cp = apr_palloc(p, outlen + 1);
+    do {
+        if (result->len) {
+            memcpy(cp, result->string, result->len);
+            cp += result->len;
+        }
+        result = result->next;
+    } while (result);
+    res_buf[outlen] = '\0';
+
+    return res_buf;
 }
+
 AP_DECLARE(int) ap_cfg_closefile(ap_configfile_t *cfp)
 {
 #ifdef DEBUG

