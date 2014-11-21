--- module.c.orig	2014-11-21 23:10:30.682534594 +0100
+++ module.c	2014-11-21 23:13:53.911520262 +0100
@@ -71,7 +71,7 @@
      void *module = NULL;
      CI_DLIB_HANDLE module_handle;
 
-     module_handle = ci_module_load(module_file, CONF.MODULES_DIR);
+     module_handle = ci_module_load(module_file, CI_CONF.MODULES_DIR);
      if (!module_handle)
           return NULL;
      module = ci_module_sym(module_handle, "module");
@@ -146,7 +146,7 @@
           if (((service_handler_module_t *) module)->init_service_handler)
                ret =
                    ((service_handler_module_t *) module)->
-                   init_service_handler(&CONF);
+                   init_service_handler(&CI_CONF);
           if (((service_handler_module_t *) module)->conf_table)
                register_conf_table(((service_handler_module_t *) module)->name,
                                    ((service_handler_module_t *) module)->
@@ -154,7 +154,7 @@
           break;
      case LOGGER:
           if (((logger_module_t *) module)->init_logger)
-               ret = ((logger_module_t *) module)->init_logger(&CONF);
+               ret = ((logger_module_t *) module)->init_logger(&CI_CONF);
           if (((logger_module_t *) module)->conf_table)
                register_conf_table(((logger_module_t *) module)->name,
                                    ((logger_module_t *) module)->conf_table,
@@ -165,7 +165,7 @@
           if (((access_control_module_t *) module)->init_access_controller)
                ret =
                    ((access_control_module_t *) module)->
-                   init_access_controller(&CONF);
+                   init_access_controller(&CI_CONF);
           if (((access_control_module_t *) module)->conf_table)
                register_conf_table(((access_control_module_t *) module)->name,
                                    ((access_control_module_t *) module)->
@@ -173,7 +173,7 @@
           break;
      case AUTH_METHOD:
           if (((http_auth_method_t *) module)->init_auth_method)
-               ret = ((http_auth_method_t *) module)->init_auth_method(&CONF);
+               ret = ((http_auth_method_t *) module)->init_auth_method(&CI_CONF);
           if (((http_auth_method_t *) module)->conf_table)
                register_conf_table(((http_auth_method_t *) module)->name,
                                    ((http_auth_method_t *) module)->conf_table,
@@ -184,7 +184,7 @@
           if (((authenticator_module_t *) module)->init_authenticator)
                ret =
                    ((authenticator_module_t *) module)->
-                   init_authenticator(&CONF);
+                   init_authenticator(&CI_CONF);
           if (((authenticator_module_t *) module)->conf_table)
                register_conf_table(((authenticator_module_t *) module)->name,
                                    ((authenticator_module_t *) module)->
@@ -192,7 +192,7 @@
           break;
      case COMMON:
           if (((common_module_t *) module)->init_module)
-               ret = ((common_module_t *) module)->init_module(&CONF);
+               ret = ((common_module_t *) module)->init_module(&CI_CONF);
           if (((common_module_t *) module)->conf_table)
                register_conf_table(((common_module_t *) module)->name,
                                    ((common_module_t *) module)->conf_table,
@@ -607,7 +607,7 @@
           if (((common_module_t *) common_modules.modules[i])->
               post_init_module != NULL)
                ((common_module_t *) common_modules.modules[i])->
-                   post_init_module(&CONF);
+                   post_init_module(&CI_CONF);
      }     
 
 /*     service_handlers */
@@ -615,7 +615,7 @@
           if (((service_handler_module_t *) service_handlers.modules[i])->
               post_init_service_handler != NULL)
                ((service_handler_module_t *) service_handlers.modules[i])->
-                   post_init_service_handler(&CONF);
+                   post_init_service_handler(&CI_CONF);
      }
 
 /*     loggers? loggers do not have post init handlers .... */
@@ -626,7 +626,7 @@
           if (((access_control_module_t *) access_controllers.modules[i])->
               post_init_access_controller != NULL)
                ((access_control_module_t *) access_controllers.modules[i])->
-                   post_init_access_controller(&CONF);
+                   post_init_access_controller(&CI_CONF);
      }
 
 
@@ -636,7 +636,7 @@
           if (((http_auth_method_t *) auth_methods.modules[i])->
               post_init_auth_method != NULL)
                ((http_auth_method_t *) auth_methods.modules[i])->
-                   post_init_auth_method(&CONF);
+                   post_init_auth_method(&CI_CONF);
      }
 
 /*     authenticators */
@@ -644,7 +644,7 @@
           if (((authenticator_module_t *) authenticators.modules[i])->
               post_init_authenticator != NULL)
                ((authenticator_module_t *) authenticators.modules[i])->
-                   post_init_authenticator(&CONF);
+                   post_init_authenticator(&CI_CONF);
      }
 
      return 1;
@@ -684,7 +684,7 @@
           if (((access_control_module_t *) access_controllers.modules[i])->
               release_access_controller != NULL)
                ((access_control_module_t *) access_controllers.modules[i])->
-                   release_access_controller(&CONF);
+                   release_access_controller(&CI_CONF);
      }
      RELEASE_MOD_LIST(access_controllers);
 
@@ -693,7 +693,7 @@
           if (((http_auth_method_t *) auth_methods.modules[i])->
               close_auth_method != NULL)
                ((http_auth_method_t *) auth_methods.modules[i])->
-                   close_auth_method(&CONF);
+                   close_auth_method(&CI_CONF);
      }
      RELEASE_MOD_LIST(auth_methods);
 
@@ -702,7 +702,7 @@
           if (((authenticator_module_t *) authenticators.modules[i])->
               close_authenticator != NULL)
                ((authenticator_module_t *) authenticators.modules[i])->
-                   close_authenticator(&CONF);
+                   close_authenticator(&CI_CONF);
      }
      RELEASE_MOD_LIST(authenticators);
 
@@ -711,7 +711,7 @@
           if (((common_module_t *) common_modules.modules[i])->
               close_module != NULL)
                ((common_module_t *) common_modules.modules[i])->
-                   close_module(&CONF);
+                   close_module(&CI_CONF);
      }
      RELEASE_MOD_LIST(common_modules);
 
