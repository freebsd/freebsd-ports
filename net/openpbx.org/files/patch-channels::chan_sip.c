--- channels/chan_sip.c.orig	Wed Apr  4 12:59:02 2007
+++ channels/chan_sip.c	Wed Apr  4 13:08:42 2007
@@ -3711,6 +3711,8 @@
     opbx_mutex_unlock(&i->lock);
     fmt = opbx_best_codec(tmp->nativeformats);
 
+    pbx_builtin_setvar_helper(tmp, "SIP_CODEC_USED", opbx_getformatname(fmt));
+
     if (title)
         snprintf(tmp->name, sizeof(tmp->name), "SIP/%s-%04x", title, thread_safe_opbx_random() & 0xffff);
     else if (strchr(i->fromdomain, ':'))
@@ -11450,6 +11452,13 @@
          username = p->authname;
          secret =  p->peersecret;
          md5secret = p->peermd5secret;
+     }
+     /* No authentication. Try to get auth info from channel vars */
+     if (opbx_strlen_zero(username))
+     {
+	 username = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_NAME");
+	 secret = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_SECRET");
+	 md5secret = pbx_builtin_getvar_helper(p->owner, "SIP_AUTH_MD5SECRET");
      }
     if (opbx_strlen_zero(username))    /* We have no authentication */
         return -1;
